// File:       windows_window.cpp
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
#include "citadel/platforms/windows/windows_window.hpp"

namespace citadel {
	bool windows_window::register_class(const wchar_t* name) {
		WNDCLASS window_class = { };
		window_class.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		window_class.lpszClassName = name;
		window_class.hInstance = GetModuleHandle(NULL);
		window_class.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
		window_class.lpfnWndProc = window_procedure;

		ATOM result = RegisterClass(&window_class);
		return static_cast<bool>(result);
	}

	bool windows_window::unregister_class(const wchar_t* name) {
		BOOL result = UnregisterClass(name, GetModuleHandle(NULL));
		return static_cast<bool>(result);
	}

	windows_window::windows_window(rendering_api::api rendering_api, dimension x, dimension y, dimension width, dimension height, const std::string& title)
		: window(rendering_api, x, y, width, height, title), window_(nullptr), instance_(GetModuleHandle(NULL))
	{
		CITADEL_ASSERT(instance_, "Failed to get module handle");

		if (instance_count_ <= 0) {
			register_class(class_name);
		}

		RECT rect = calculate_rect(
			get_x(),
			get_y(),
			get_width(),
			get_height()
		);

		std::wstring wide_title = get_wide_title();

		window_ = CreateWindowEx(
			0,
			class_name,
			wide_title.c_str(),
			style_,
			rect.left,
			rect.top,
			rect.right - rect.left,
			rect.bottom - rect.top,
			NULL,
			NULL,
			instance_,
			this
		);

		CITADEL_ASSERT(window_, "Failed to create window");
	}

	windows_window::windows_window(rendering_api::api rendering_api, dimension width, dimension height, const std::string& title)
		: windows_window(rendering_api, 0, 0, width, height, title) { }

	windows_window::~windows_window() {
		CITADEL_ASSERT(window_, "Window handle is null");

		DestroyWindow(window_);

		if (instance_count_ <= 0) {
			unregister_class(class_name);
		}
	}

	std::size_t windows_window::instance_count_ = 0;

	LRESULT windows_window::window_procedure(HWND handle, UINT message, WPARAM wide_parameter, LPARAM long_parameter) {
		CITADEL_ASSERT(handle, "The given window handle is null");

		if (message == WM_CREATE) {
			CREATESTRUCT* create_struct = reinterpret_cast<CREATESTRUCT*>(long_parameter);
			CITADEL_ASSERT(create_struct, "Failed to retrieve create struct");

			void* raw_pointer = create_struct->lpCreateParams;
			LONG_PTR long_pointer = reinterpret_cast<LONG_PTR>(raw_pointer);

			SetWindowLongPtr(handle, GWLP_USERDATA, long_pointer);
		}

		windows_window* window = reinterpret_cast<windows_window*>(GetWindowLongPtr(handle, GWLP_USERDATA));

		switch (message) {
		case WM_MOVE: {
			int x = GET_X_LPARAM(long_parameter);
			int y = GET_Y_LPARAM(long_parameter);

			CITADEL_ASSERT(window, "Failed to retrieve Windows window");

			if (window) {
				window->x_ = static_cast<dimension>(x);
				window->y_ = static_cast<dimension>(y);

				window->get_surface().set_x(static_cast<dimension>(x));
				window->get_surface().set_y(static_cast<dimension>(y));
			}
		} break;

		case WM_SIZE: {
			int width = GET_X_LPARAM(long_parameter);
			int height = GET_Y_LPARAM(long_parameter);

			CITADEL_ASSERT(window, "Failed to retrieve Windows window");

			if (window) {
				window->width_ = static_cast<dimension>(width);
				window->height_ = static_cast<dimension>(height);

				window->get_surface().set_width(static_cast<dimension>(width));
				window->get_surface().set_height(static_cast<dimension>(height));
			}
		} break;

		case WM_CREATE:
			instance_count_++;
			break;

		case WM_CLOSE:
			DestroyWindow(handle);
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

		return DefWindowProc(handle, message, wide_parameter, long_parameter);
	}

	RECT windows_window::calculate_rect(dimension x, dimension y, dimension width, dimension height) const {
		RECT rect = { };

		rect.left = static_cast<LONG>(x);
		rect.top = static_cast<LONG>(y);
		rect.right = static_cast<LONG>(x) + static_cast<LONG>(width);
		rect.bottom = static_cast<LONG>(y) + static_cast<LONG>(height);

		AdjustWindowRect(&rect, style_, FALSE);
		return rect;
	}

	void windows_window::move_window(dimension x, dimension y, dimension width, dimension height) const {
		CITADEL_ASSERT(window_, "Window handle is null");

		RECT rect = calculate_rect(x, y, width, height);

		MoveWindow(
			window_,
			rect.left,
			rect.top,
			rect.right - rect.left,
			rect.bottom - rect.top,
			TRUE
		);
	}

	std::wstring windows_window::get_wide_title() const {
		return std::wstring(get_title().begin(), get_title().end());
	}

	void windows_window::_show() {
		CITADEL_ASSERT(window_, "Window handle is null");
		ShowWindow(window_, SW_SHOW);
	}

	void windows_window::_hide() {
		CITADEL_ASSERT(window_, "Window handle is null");
		ShowWindow(window_, SW_HIDE);
	}

	void windows_window::_maximize() {
		CITADEL_ASSERT(window_, "Window handle is null");
		ShowWindow(window_, SW_MAXIMIZE);
	}

	void windows_window::_minimize() {
		CITADEL_ASSERT(window_, "Window handle is null");
		ShowWindow(window_, SW_MINIMIZE);
	}

	bool windows_window::_update(double delta) {
		CITADEL_ASSERT(window_, "Window handle is null");

		MSG message = { };

		while (PeekMessage(&message, window_, 0, 0, PM_REMOVE)) {
			if (message.message == WM_QUIT) {
				return false;
			}

			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		return true;
	}

	void windows_window::_render() { }
	void windows_window::_begin_frame() { }
	void windows_window::_end_frame() { }

	void* windows_window::_get_native_handle() const {
		return window_;
	}

	void windows_window::_set_title(const std::string& value) {
		CITADEL_ASSERT(window_, "Window handle is null");
		std::wstring wide_title(value.begin(), value.end());
		SetWindowText(window_, wide_title.c_str());
	}

	void windows_window::_set_x(dimension value) {
		move_window(
			get_x(),
			get_y(),
			get_width(),
			get_height()
		);
	}

	void windows_window::_set_y(dimension value) {
		move_window(
			get_x(),
			get_y(),
			get_width(),
			get_height()
		);
	}

	void windows_window::_set_width(dimension value) {
		move_window(
			get_x(),
			get_y(),
			get_width(),
			get_height()
		);
	}

	void windows_window::_set_height(dimension value) {
		move_window(
			get_x(),
			get_y(),
			get_width(),
			get_height()
		);
	}

	void windows_window::_set_vsync(bool value) {
		wglSwapIntervalEXT(static_cast<int>(value));
	}
}
