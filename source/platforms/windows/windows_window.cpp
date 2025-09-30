// File:       windows_window.cpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
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

#include "citadel/pch.hpp"
#include "citadel/platforms/windows/windows_window.hpp"

namespace citadel {
	windows_window::windows_window(dimension x, dimension y, dimension width, dimension height, const std::string& title)
		: window(x, y, width, height, title), handle_(nullptr), instance_(GetModuleHandle(NULL)) {
		CITADEL_ASSERT(instance_, "Failed to get module handle");
	}

	windows_window::windows_window(dimension width, dimension height, const std::string& title)
		: window(width, height, title), handle_(nullptr), instance_(GetModuleHandle(NULL)) {
		CITADEL_ASSERT(instance_, "Failed to get module handle");
	}

	std::string windows_window::get_class_name() {
		std::wstring wide_class_name(class_name);
		std::string string_class_name(wide_class_name.begin(), wide_class_name.end());
		return string_class_name;
	}

	std::size_t windows_window::instance_count_ = 0;

	LRESULT windows_window::window_procedure(HWND window_handle, UINT message, WPARAM wide_parameter, LPARAM long_parameter) {
		CITADEL_ASSERT(window_handle, "Window handle is null");

		if (message == WM_CREATE) {
			CREATESTRUCT* create_struct = reinterpret_cast<CREATESTRUCT*>(long_parameter);
			CITADEL_ASSERT(create_struct, "Failed to obtain create struct");

			void* raw_pointer = create_struct->lpCreateParams;
			LONG_PTR long_pointer = reinterpret_cast<LONG_PTR>(raw_pointer);

			SetWindowLongPtr(window_handle, GWLP_USERDATA, long_pointer);
		}

		windows_window* window = reinterpret_cast<windows_window*>(GetWindowLongPtr(window_handle, GWLP_USERDATA));

		switch (message) {
		case WM_CREATE: {
			instance_count_++;
		} break;

		case WM_MOVE: {
			int x = (int)(short)LOWORD(long_parameter);
			int y = (int)(short)HIWORD(long_parameter);

			CITADEL_ASSERT(window, "The given window is null");

			if (window) {
				window->x_ = x;
				window->y_ = y;
			}
		} break;

		case WM_SIZE: {
			int width = (int)(short)LOWORD(long_parameter);
			int height = (int)(short)HIWORD(long_parameter);

			CITADEL_ASSERT(window, "The given window is null");

			if (window) {
				window->width_ = width;
				window->height_ = height;
			}
		} break;

		case WM_CLOSE:
			CITADEL_ASSERT(window, "The given window is null");

			if (window) {
				window->close();
			}

			return 0;

		case WM_DESTROY:
			instance_count_--;

			if (instance_count_ <= 0) {
				PostQuitMessage(0);
			}

			return 0;
		}

		return DefWindowProc(window_handle, message, wide_parameter, long_parameter);
	}

	void windows_window::register_class() {
		std::cout << "Registering window class '" << get_class_name() << "'." << std::endl;

		WNDCLASS window_class = { };
		window_class.lpszClassName = class_name;
		window_class.hInstance = GetModuleHandle(NULL);
		window_class.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
		window_class.lpfnWndProc = window_procedure;

		RegisterClass(&window_class);
	}

	void windows_window::unregister_class() {
		std::cout << "Unregistering window class '" << get_class_name() << "'." << std::endl;

		UnregisterClass(class_name, GetModuleHandle(NULL));
	}

	void windows_window::update_rect() const {
		CITADEL_ASSERT(handle_, "Window handle is null");

		UINT flags = SWP_NOZORDER | SWP_NOACTIVATE;

		SetWindowPos(
			handle_,
			NULL,
			get_x(),
			get_y(),
			get_width(),
			get_height(),
			flags
		);
	}

	void windows_window::_open() {
		if (instance_count_ <= 0) {
			register_class();
		}

		std::cout << "Opening window '" << get_title() << "'." << std::endl;

		DWORD style = WS_OVERLAPPEDWINDOW;

		RECT rect = { };
		rect.left = static_cast<LONG>(get_x());
		rect.top = static_cast<LONG>(get_y());
		rect.right = static_cast<LONG>(get_x() + get_width());
		rect.bottom = static_cast<LONG>(get_y() + get_height());

		AdjustWindowRect(&rect, style, FALSE);

		std::wstring wide_title(get_title().begin(), get_title().end());

		handle_ = CreateWindowEx(
			0,
			class_name,
			wide_title.c_str(),
			style,
			rect.left,
			rect.top,
			rect.right - rect.left,
			rect.bottom - rect.top,
			NULL,
			NULL,
			instance_,
			this
		);

		CITADEL_ASSERT(handle_, "Failed to create window");
	}

	void windows_window::_close() {
		std::cout << "Closing window '" << get_title() << "'." << std::endl;

		CITADEL_ASSERT(handle_, "Window handle is null");

		DestroyWindow(handle_);

		if (instance_count_ <= 0) {
			unregister_class();
		}
	}

	void windows_window::_show() {
		CITADEL_ASSERT(handle_, "Window handle is null");
		ShowWindow(handle_, SW_SHOW);
	}

	void windows_window::_hide() {
		CITADEL_ASSERT(handle_, "Window handle is null");
		ShowWindow(handle_, SW_HIDE);
	}

	void windows_window::_maximize() {
		CITADEL_ASSERT(handle_, "Window handle is null");
		ShowWindow(handle_, SW_MAXIMIZE);
	}

	void windows_window::_minimize() {
		CITADEL_ASSERT(handle_, "Window handle is null");
		ShowWindow(handle_, SW_MINIMIZE);
	}

	void windows_window::_update() {
		MSG message = { };

		while (PeekMessage(&message, handle_, 0, 0, PM_REMOVE)) {
			if (message.message == WM_QUIT) {
				close();
			}

			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}

	void* windows_window::_get_native_handle() const {
		return handle_;
	}

	void windows_window::_set_x(dimension x) {
		update_rect();
	}

	void windows_window::_set_y(dimension y) {
		update_rect();
	}

	void windows_window::_set_width(dimension width) {
		update_rect();
	}

	void windows_window::_set_height(dimension height) {
		update_rect();
	}

	void windows_window::_set_title(const std::string& title) {
		CITADEL_ASSERT(handle_, "Window handle is null");
		std::wstring wide_title(title.begin(), title.end());
		SetWindowText(handle_, wide_title.c_str());
	}
}
