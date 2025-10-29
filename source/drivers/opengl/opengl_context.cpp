// File:       opengl_context.cpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#include "citadel/pch.hpp"
#include "citadel/drivers/opengl/opengl_context.hpp"

#include "citadel/platforms/windows/windows_window.hpp"

namespace citadel {
	void opengl_context::_construct(window* window) {
#if CITADEL_PLATFORM_WINDOWS
		if (windows_window* windows_window = reinterpret_cast<class windows_window*>(window)) {
			window_ = reinterpret_cast<HWND>(windows_window->get_native_handle());
			device_context_ = GetDC(window_);

			PIXELFORMATDESCRIPTOR pixel_format_descriptor = { };
			pixel_format_descriptor.nSize = sizeof(PPIXELFORMATDESCRIPTOR);
			pixel_format_descriptor.nVersion = 1;
			pixel_format_descriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
			pixel_format_descriptor.iPixelType = PFD_TYPE_RGBA;
			pixel_format_descriptor.cColorBits = 32;
			pixel_format_descriptor.cDepthBits = 24;
			pixel_format_descriptor.cStencilBits = 8;
			pixel_format_descriptor.iLayerType = PFD_MAIN_PLANE;

			int pixel_format = ChoosePixelFormat(device_context_, &pixel_format_descriptor);
			CITADEL_ASSERT(pixel_format != 0, "Failed to choose pixel format");

			CITADEL_ASSERT(
				SetPixelFormat(device_context_, pixel_format, &pixel_format_descriptor),
				"Failed to set pixel format"
			);

			gl_rendering_context_ = wglCreateContext(device_context_);
			CITADEL_ASSERT(gl_rendering_context_, "Failed to create OpenGL rendering context");
		} else {
			CITADEL_ASSERT(false, "The given window is not supported for Windows");
		}
#else
	#error Rendering context does not support your window system yet
#endif
	}

	void opengl_context::_destroy() {
#if CITADEL_PLATFORM_WINDOWS
		CITADEL_ASSERT(gl_rendering_context_, "OpenGL rendering context is null");

		wglDeleteContext(gl_rendering_context_);
		ReleaseDC(window_, device_context_);

		gl_rendering_context_ = nullptr;
#else
	#error Rendering context does not support your window system yet
#endif
	}

	void opengl_context::_bind() {
#if CITADEL_PLATFORM_WINDOWS
		CITADEL_ASSERT(device_context_, "Device context is null");
		CITADEL_ASSERT(gl_rendering_context_, "OpenGL rendering context is null");

		wglMakeCurrent(device_context_, gl_rendering_context_);
#else
	#error Rendering context does not support your window system yet
#endif
	}

	void opengl_context::_unbind() {
		wglMakeCurrent(NULL, NULL);
	}

	void opengl_context::_swap_buffers() {
#if CITADEL_PLATFORM_WINDOWS
		CITADEL_ASSERT(device_context_, "Device context is null");
		SwapBuffers(device_context_);
#else
	#error Rendering context does not support your window system yet
#endif
	}
}
