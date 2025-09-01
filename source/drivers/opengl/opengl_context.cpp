// File:        opengl_context.cpp
// Project:     citadel
// Repository:  https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// For more details, see the LICENSE file at the root of the project.

#include "citadelpch.h"
#include "drivers/opengl/opengl_context.h"

#include "citadel/core/window.h"

#include "citadel/rendering/color.h"

#include "drivers/opengl/opengl_loader.h"

namespace citadel
{
	void opengl_context::_initialize(window* window)
	{
#if CITADEL_PLATFORM_WINDOWS
		windows_window* platform_window = static_cast<windows_window*>(window);
		initialize_windows(platform_window);
#else
	#error opengl_context does not support your platform yet
#endif
		load_opengl_functions();
	}

	void opengl_context::_destroy()
	{
#if CITADEL_PLATFORM_WINDOWS
		destroy_windows();
#else
	#error opengl_context does not support your platform yet
#endif
	}

	void opengl_context::_swap_buffers()
	{
#if CITADEL_PLATFORM_WINDOWS
		swap_buffers_windows();
#else
	#error opengl_context does not support your platform yet
#endif
	}

	void opengl_context::initialize_windows(windows_window* window)
	{
#if CITADEL_PLATFORM_WINDOWS
		window_handle_ = static_cast<HWND>(window->get_native_handle());
		device_context_handle_ = GetDC(window_handle_);

		PIXELFORMATDESCRIPTOR pixel_format_descriptor = { sizeof(PIXELFORMATDESCRIPTOR) };
		pixel_format_descriptor.nVersion = 1;
		pixel_format_descriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pixel_format_descriptor.iPixelType = PFD_TYPE_RGBA;
		pixel_format_descriptor.cColorBits = 32;
		pixel_format_descriptor.cDepthBits = 24;
		pixel_format_descriptor.cStencilBits = 8;
		pixel_format_descriptor.iLayerType = PFD_MAIN_PLANE;

		int pixel_format = ChoosePixelFormat(device_context_handle_, &pixel_format_descriptor);
		CITADEL_ASSERT(pixel_format != 0, "Failed to choose pixel format");

		BOOL set_pixel_format_result = SetPixelFormat(device_context_handle_, pixel_format, &pixel_format_descriptor);
		CITADEL_ASSERT(set_pixel_format_result == TRUE, "Failed to set pixel format");

		gl_rendering_context_handle_ = wglCreateContext(device_context_handle_);
		CITADEL_ASSERT(gl_rendering_context_handle_, "Windows OpenGL context handle is null");

		wglMakeCurrent(device_context_handle_, gl_rendering_context_handle_);
#endif
	}

	void opengl_context::destroy_windows()
	{
#if CITADEL_PLATFORM_WINDOWS
		wglDeleteContext(gl_rendering_context_handle_);
		gl_rendering_context_handle_ = nullptr;
#endif
	}

	void opengl_context::swap_buffers_windows() const
	{
#if CITADEL_PLATFORM_WINDOWS
		if (device_context_handle_)
		{
			SwapBuffers(device_context_handle_);
		}
#endif
	}
}
