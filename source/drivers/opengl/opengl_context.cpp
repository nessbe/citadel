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
	void APIENTRY opengl_context::opengl_debug_callback(
		GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message,
		const void* user_parameters
	) {
		log_level level = opengl::debug_severity_to_log_level(severity);
		CITADEL_LOG(level, "OpenGL debug callback: {0}", message);

		CITADEL_LOG(level, "\tSource: {0}", source);
		CITADEL_LOG(level, "\tType: {0}", type);
		CITADEL_LOG(level, "\tID: {0}", id);
		CITADEL_LOG(level, "\tSeverity: {0}", severity);
	}

	opengl_context::opengl_context(window* window) {
#if CITADEL_PLATFORM_WINDOWS
		CITADEL_SOFT_ASSERT(
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
			0
		};

		int pixel_format;
		UINT pixel_format_count;

		wglChoosePixelFormatARB(device_context_, pixel_format_attributes, NULL, 1, &pixel_format, &pixel_format_count);
		CITADEL_SOFT_ASSERT(pixel_format_count > 0, "Failed to choose pixel format");

		PIXELFORMATDESCRIPTOR pixel_format_descriptor;
		DescribePixelFormat(device_context_, pixel_format, sizeof(pixel_format_descriptor), &pixel_format_descriptor);

		CITADEL_SOFT_ASSERT(
			SetPixelFormat(device_context_, pixel_format, &pixel_format_descriptor),
			"Failed to set pixel format"
		);

		int opengl_attributes[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
			WGL_CONTEXT_MINOR_VERSION_ARB, 6,
			WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
			WGL_CONTEXT_FLAGS_ARB,         WGL_CONTEXT_DEBUG_BIT_ARB,
			0
		};

		rendering_context_ = wglCreateContextAttribsARB(device_context_, NULL, opengl_attributes);
		CITADEL_SOFT_ASSERT(rendering_context_, "Failed to create OpenGL rendering context");

		wglMakeCurrent(device_context_, rendering_context_);

		CITADEL_SOFT_ASSERT(
			opengl_loader_.load(),
			"Failed to load OpenGL using Glad"
		);

#else
	#error Rendering context does not support your window system yet
#endif

#if CITADEL_DEBUG
		enable_debug();
#endif

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	opengl_context::~opengl_context() {
#if CITADEL_PLATFORM_WINDOWS
		CITADEL_SOFT_ASSERT(device_context_, "Device context is null");
		CITADEL_SOFT_ASSERT(rendering_context_, "OpenGL rendering context is null");

		wglMakeCurrent(device_context_, NULL);
		wglDeleteContext(rendering_context_);

		ReleaseDC(window_, device_context_);

		rendering_context_ = nullptr;
		device_context_ = nullptr;
		window_ = nullptr;

		opengl_loader_.unload();
		wgl_loader_.unload();
#else
	#error Rendering context does not support your window system yet
#endif
	}

	void opengl_context::enable_debug() {
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

		glDebugMessageCallback(opengl_debug_callback, nullptr);
		glDebugMessageControl(
			GL_DONT_CARE,
			GL_DONT_CARE,
			GL_DONT_CARE,
			0,
			NULL,
			GL_TRUE
		);
	}

	void opengl_context::_bind() {
#if CITADEL_PLATFORM_WINDOWS
		CITADEL_SOFT_ASSERT(device_context_, "Device context is null");
		CITADEL_SOFT_ASSERT(rendering_context_, "OpenGL rendering context is null");

		wglMakeCurrent(device_context_, rendering_context_);
#else
	#error Rendering context does not support your window system yet
#endif
	}

	void opengl_context::_unbind() {
		CITADEL_SOFT_ASSERT(device_context_, "Device context is null");
		wglMakeCurrent(device_context_, NULL);
	}

	void opengl_context::_swap_buffers() {
#if CITADEL_PLATFORM_WINDOWS
		CITADEL_SOFT_ASSERT(device_context_, "Device context is null");
		SwapBuffers(device_context_);
#else
	#error Rendering context does not support your window system yet
#endif
	}
}
