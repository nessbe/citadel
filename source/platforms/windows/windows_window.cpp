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
	bool windows_window::register_class(const wchar_t* class_name) {
		WNDCLASS window_class = { };

		window_class.lpszClassName = class_name;
		window_class.hInstance = GetModuleHandle(NULL);
		window_class.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
		window_class.lpfnWndProc = window_procedure;

		ATOM result = RegisterClass(&window_class);
		return static_cast<bool>(result);
	}

	bool windows_window::unregister_class(const wchar_t* class_name) {
		BOOL result = UnregisterClass(class_name, GetModuleHandle(NULL));
		return static_cast<bool>(result);
	}

	windows_window::windows_window(dimension x, dimension y, dimension width, dimension height, const std::string& title)
		: window(x, y, width, height, title), window_(nullptr), instance_(GetModuleHandle(NULL)) {
		CITADEL_ASSERT(instance_, "Failed to get module handle");
	}

	windows_window::windows_window(dimension width, dimension height, const std::string& title)
		: windows_window(0, 0, width, height, title) { }

	windows_window::~windows_window() {
		close();
	}

	std::size_t windows_window::instance_count_ = 0;

	LRESULT windows_window::window_procedure(HWND handle, UINT message, WPARAM wide_parameter, LPARAM long_parameter) {
		CITADEL_ASSERT(handle, "Window handle is null");

		switch (message) {
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

	void windows_window::_open() {
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
			NULL
		);

		CITADEL_ASSERT(window_, "Failed to create window");
	}

	void windows_window::_close() {
		CITADEL_ASSERT(window_, "Window handle is null");

		DestroyWindow(window_);

		if (instance_count_ <= 0) {
			unregister_class(class_name);
		}
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

	bool windows_window::_update() {
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

	void* windows_window::_get_native_handle() const {
		return window_;
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

	void windows_window::_set_title(const std::string& value) {
		CITADEL_ASSERT(window_, "Window handle is null");
		std::wstring wide_title(value.begin(), value.end());
		SetWindowText(window_, wide_title.c_str());
	}
}
