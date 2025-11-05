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
#if CITADEL_PLATFORM_WINDOWS
	void opengl_context::construct_windows(windows_window* window) {
		CITADEL_ASSERT(
			wgl_loader_.load(),
			"Failed to load WGL using Glad"
		);

		window_ = reinterpret_cast<HWND>(window->get_native_handle());
		device_context_ = GetDC(window_);

		int pixel_format_attributes[] = {
			WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
			WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
			WGL_DOUBLE_BUFFER_ARB,  GL_TRUE,
			WGL_ACCELERATION_ARB,   WGL_FULL_ACCELERATION_ARB,
			WGL_PIXEL_TYPE_ARB,     WGL_TYPE_RGBA_ARB,
			WGL_COLOR_BITS_ARB,     32,
			WGL_DEPTH_BITS_ARB,     24,
			WGL_STENCIL_BITS_ARB,   8,
			NULL
		};

		int pixel_format;
		UINT pixel_format_count;

		wglChoosePixelFormatARB(device_context_, pixel_format_attributes, NULL, 1, &pixel_format, &pixel_format_count);
		CITADEL_ASSERT(pixel_format_count > 0, "Failed to choose pixel format");

		PIXELFORMATDESCRIPTOR pixel_format_descriptor;
		DescribePixelFormat(device_context_, pixel_format, sizeof(pixel_format_descriptor), &pixel_format_descriptor);

		CITADEL_ASSERT(
			SetPixelFormat(device_context_, pixel_format, &pixel_format_descriptor),
			"Failed to set pixel format"
		);

		int opengl_attributes[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
			WGL_CONTEXT_MINOR_VERSION_ARB, 6,
			WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
			NULL
		};

		rendering_context_ = wglCreateContextAttribsARB(device_context_, NULL, opengl_attributes);
		CITADEL_ASSERT(rendering_context_, "Failed to create OpenGL rendering context");

		wglMakeCurrent(device_context_, rendering_context_);

		CITADEL_ASSERT(
			opengl_loader_.load(),
			"Failed to load OpenGL using Glad"
		);
	}
#endif

	void opengl_context::_construct(window* window) {
#if CITADEL_PLATFORM_WINDOWS
		if (windows_window* platform_window = dynamic_cast<windows_window*>(window)) {
			construct_windows(platform_window);
		} else {
			CITADEL_PANIC("The given window is not supported for Windows");
		}
#else
	#error Rendering context does not support your window system yet
#endif
	}

	void opengl_context::_destroy() {
#if CITADEL_PLATFORM_WINDOWS
		CITADEL_ASSERT(device_context_, "Device context is null");
		CITADEL_ASSERT(rendering_context_, "OpenGL rendering context is null");

		wglMakeCurrent(device_context_, NULL);
		wglDeleteContext(rendering_context_);

		ReleaseDC(window_, device_context_);

		rendering_context_ = nullptr;

		opengl_loader_.unload();
		wgl_loader_.unload();
#else
	#error Rendering context does not support your window system yet
#endif
	}

	void opengl_context::_bind() {
#if CITADEL_PLATFORM_WINDOWS
		CITADEL_ASSERT(device_context_, "Device context is null");
		CITADEL_ASSERT(rendering_context_, "OpenGL rendering context is null");

		wglMakeCurrent(device_context_, rendering_context_);
#else
	#error Rendering context does not support your window system yet
#endif
	}

	void opengl_context::_unbind() {
		CITADEL_ASSERT(device_context_, "Device context is null");
		wglMakeCurrent(device_context_, NULL);
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
