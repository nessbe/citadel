// File:       window.cpp
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
#include "citadel/display/window.hpp"

#include "citadel/platforms/windows/windows_window.hpp"

namespace citadel {
	std::unique_ptr<window> window::create(dimension x, dimension y, dimension width, dimension height, const std::string& title) {
#if CITADEL_PLATFORM_WINDOWS
		return std::make_unique<windows_window>(x, y, width, height, title);
#else
	#error Citadel does not support your window system yet
		return nullptr;
#endif
	}

	std::unique_ptr<window> window::create(dimension width, dimension height, const std::string& title) {
		return create(0, 0, width, height, title);
	}

	window::window(dimension x, dimension y, dimension width, dimension height, const std::string& title) :
		x_(x),
		y_(y),
		width_(width),
		height_(height),
		title_(title),
		surface_(surface::create(x_, y_, width_, height_, color(255, 255, 255, 255))),
		rendering_context_(rendering_context::create()) {
		CITADEL_ASSERT(surface_, "Failed to create surface");
		CITADEL_ASSERT(rendering_context_, "Failed to create rendering context");
	}

	window::window(dimension width, dimension height, const std::string& title)
		: window(0, 0, width, height, title) { }

	void window::open() {
		if (likely(!is_open_)) {
			_open();
		}

		CITADEL_ASSERT(rendering_context_, "Rendering context is null");

		//if (rendering_context_) {
		//	rendering_context_->construct(this);
		//	rendering_context_->bind();
		//}

		is_open_ = true;

		auto get_proc_address = [](const char* name) {
			void* proc = wglGetProcAddress(name);

			if (proc) {
				return proc;
			}

			static HMODULE opengl32 = LoadLibrary(L"opengl32.dll");
			return (void*)GetProcAddress(opengl32, name);
		};

		HWND native_window = reinterpret_cast<HWND>(get_native_handle());

		HWND dummy_window = CreateWindowEx(
			0,
			L"CitadelWindow",
			L"Dummy OpenGL Window",
			NULL,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			NULL,
			NULL,
			GetModuleHandle(NULL),
			NULL
		);

		CITADEL_ASSERT(dummy_window, "Failed to open dummy window");

		HDC dummy_device_context = GetDC(dummy_window);

		PIXELFORMATDESCRIPTOR dummy_pfd = { };
		dummy_pfd.nSize = sizeof(dummy_pfd);
		dummy_pfd.nVersion = 1;
		dummy_pfd.iPixelType = PFD_TYPE_RGBA;
		dummy_pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		dummy_pfd.cColorBits = 32;
		dummy_pfd.cAlphaBits = 8;
		dummy_pfd.cDepthBits = 24;
		dummy_pfd.cStencilBits = 8;
		dummy_pfd.iLayerType = PFD_MAIN_PLANE;

		int dummy_pixel_format = ChoosePixelFormat(dummy_device_context, &dummy_pfd);
		CITADEL_ASSERT(dummy_pixel_format, "Failed to choose pixel format");

		CITADEL_ASSERT(
			SetPixelFormat(dummy_device_context, dummy_pixel_format, &dummy_pfd),
			"Failed to set pixel format"
		);

		HGLRC dummy_rendering_context = wglCreateContext(dummy_device_context);
		CITADEL_ASSERT(dummy_rendering_context, "Failed to create WGL rendering context");

		CITADEL_ASSERT(
			wglMakeCurrent(dummy_device_context, dummy_rendering_context),
			"Failed to make WGL rendering context current"
		);

		CITADEL_ASSERT(
			gladLoadWGLLoader((GLADloadproc)get_proc_address, dummy_device_context),
			"Failed to load WGL using GLAD"
		);

		wglMakeCurrent(dummy_device_context, NULL);
		wglDeleteContext(dummy_rendering_context);
		ReleaseDC(dummy_window, dummy_device_context);

		device_context = GetDC(native_window);

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

		int real_pixel_format;
		UINT pixel_format_count;

		wglChoosePixelFormatARB(device_context, pixel_format_attributes, NULL, 1, &real_pixel_format, &pixel_format_count);

		CITADEL_ASSERT(pixel_format_count > 0, "Failed to set modern OpenGL pixel format");

		int current_pixel_format = GetPixelFormat(device_context);
		CITADEL_ASSERT(!current_pixel_format, "Pixel format is already set");

		PIXELFORMATDESCRIPTOR real_pfd;
		DescribePixelFormat(device_context, real_pixel_format, sizeof(real_pfd), &real_pfd);

		CITADEL_ASSERT(
			SetPixelFormat(device_context, real_pixel_format, &real_pfd),
			"Failed to set modern OpenGL pixel format"
		);

		int opengl_attributes[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
			WGL_CONTEXT_MINOR_VERSION_ARB, 6,
			WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
			0
		};

		rendering_context = wglCreateContextAttribsARB(
			device_context,
			NULL,
			opengl_attributes
		);

		wglMakeCurrent(device_context, rendering_context);

		CITADEL_ASSERT(
			gladLoadWGLLoader((GLADloadproc)get_proc_address, device_context),
			"Failed to load WGL using GLAD"
		);

		CITADEL_ASSERT(
			gladLoadGLLoader((GLADloadproc)get_proc_address),
			"Failed to load modern OpenGL using GLAD"
		);

		float vertices[] = {
			0.0f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
			-0.5f, -0.5, 0.0f, 0.0f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
		};

		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);

		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		constexpr const char* vertex_shader_source = R"(
			#version 330 core

			layout (location = 0) in vec3 position;
			layout (location = 1) in vec3 color;

			out vec3 vertex_color;

			void main() {
				gl_Position = vec4(position, 1.0);
				vertex_color = color;
			}
		)";

		constexpr const char* fragment_shader_source = R"(
			#version 330 core

			in vec3 vertex_color;
			out vec4 fragment_color;

			void main() {
				fragment_color = vec4(vertex_color, 1.0);
			}	
		)";

		GLuint vertex_shader;
		vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader, 1, &vertex_shader_source, nullptr);
		glCompileShader(vertex_shader);

		GLuint fragment_shader;
		fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader, 1, &fragment_shader_source, nullptr);
		glCompileShader(fragment_shader);

		GLuint shader_program;
		shader_program = glCreateProgram();
		glAttachShader(shader_program, vertex_shader);
		glAttachShader(shader_program, fragment_shader);
		glLinkProgram(shader_program);
		glUseProgram(shader_program);
	}

	void window::close() {
		CITADEL_ASSERT(rendering_context_, "Rendering context is null");

		if (rendering_context_) {
			rendering_context_->destroy();
		}

		if (likely(is_open_)) {
			_close();
		}

		is_open_ = false;

		glDeleteProgram(shader_program);
		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);
	}

	void window::show() {
		if (likely(!is_visible_)) {
			_show();
		}

		is_visible_ = true;
	}

	void window::hide() {
		if (likely(is_visible_)) {
			_hide();
		}

		is_visible_ = false;
	}

	void window::maximize() {
		_maximize();
	}

	void window::minimize() {
		_minimize();
	}

	bool window::update() {
		if (!is_open()) {
			return false;
		}

		bool result = _update();

		if (!result) {
			close();
		}

		if (is_visible()) {
			render();
		}

		return result;
	}

	void window::render() {
		CITADEL_ASSERT(surface_, "Surface is null");
		CITADEL_ASSERT(rendering_context_, "Rendering context is null");

		//rendering_context_->bind();

		surface_->bind();
		surface_->clear();

		_render();

		glUseProgram(shader_program);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		surface_->present();

		SwapBuffers(device_context);
		//rendering_context_->swap_buffers();

		surface_->unbind();
		//rendering_context_->unbind();
	}

	bool window::is_open() const noexcept {
		return is_open_;
	}

	bool window::is_visible() const noexcept {
		return is_visible_;
	}

	void* window::get_native_handle() const {
		return _get_native_handle();
	}

	window::dimension window::get_x() const noexcept {
		return x_;
	}

	void window::set_x(dimension value) {
		_set_x(value);
		x_ = value;

		CITADEL_ASSERT(surface_, "Surface is null");

		if (surface_) {
			surface_->set_x(value);
		}
	}

	window::dimension window::get_y() const noexcept {
		return y_;
	}

	void window::set_y(dimension value) {
		_set_y(value);
		y_ = value;

		CITADEL_ASSERT(surface_, "Surface is null");

		if (surface_) {
			surface_->set_y(value);
		}
	}

	window::dimension window::get_width() const noexcept {
		return width_;
	}

	void window::set_width(dimension value) {
		_set_width(value);
		width_ = value;

		CITADEL_ASSERT(surface_, "Surface is null");

		if (surface_) {
			surface_->set_width(value);
		}
	}

	window::dimension window::get_height() const noexcept {
		return height_;
	}

	void window::set_height(dimension value) {
		_set_height(value);
		height_ = value;

		CITADEL_ASSERT(surface_, "Surface is null");

		if (surface_) {
			surface_->set_height(value);
		}
	}

	const std::string& window::get_title() const noexcept {
		return title_;
	}

	void window::set_title(const std::string& value) {
		_set_title(value);
		title_ = value;
	}

	surface& window::get_surface() const {
		CITADEL_ASSERT(surface_, "Surface is null");
		return *surface_;
	}

	rendering_context& window::get_rendering_context() const {
		CITADEL_ASSERT(rendering_context_, "Rendering context is null");
		return *rendering_context_;
	}
}
