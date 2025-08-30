// File:        windows_window.cpp
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
#include "platforms/windows/windows_window.h"

namespace citadel
{
	windows_window::~windows_window()
	{
		close();
	}

	void windows_window::_open()
	{
		register_window_class();

		DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

		RECT rect = { };

		rect.left = static_cast<LONG>(get_x());
		rect.top = static_cast<LONG>(get_y());
		rect.right = rect.left + static_cast<LONG>(get_width());
		rect.bottom = rect.top + static_cast<LONG>(get_height());

		AdjustWindowRect(&rect, style, false);

		std::wstring wide_title = get_wide_title();

		window_handle_ = CreateWindowEx(
			0,
			CLASS_NAME,
			wide_title.c_str(),
			style,
			rect.left,
			rect.top,
			rect.right - rect.left,
			rect.bottom - rect.top,
			nullptr,
			nullptr,
			instance_handle_,
			this
		);

		show();
	}

	void windows_window::_close()
	{
		if (window_handle_)
		{
			DestroyWindow(window_handle_);
		}
	}

	void windows_window::_show()
	{
		ShowWindow(window_handle_, SW_SHOW);
	}

	void windows_window::_hide()
	{
		ShowWindow(window_handle_, SW_HIDE);
	}

	bool windows_window::_update()
	{
		return process_messages();
	}

	void windows_window::_set_x(dimension_t x)
	{
		set_position(x, get_y(), get_width(), get_height());
	}

	void windows_window::_set_y(dimension_t y)
	{
		set_position(get_x(), y, get_width(), get_height());
	}

	void windows_window::_set_width(dimension_t width)
	{
		set_position(get_x(), get_y(), width, get_height());
	}

	void windows_window::_set_height(dimension_t height)
	{
		set_position(get_x(), get_y(), get_width(), height);
	}

	void windows_window::_set_title(const std::string& title)
	{
		std::wstring wide_title = std::wstring(title.begin(), title.end());
		SetWindowText(window_handle_, wide_title.c_str());
	}

	void* windows_window::_get_native_handle() const
	{
		return window_handle_;
	}

	LRESULT windows_window::window_procedure(HWND window_handle, UINT message, WPARAM wide_parameter, LPARAM long_parameter)
	{
		if (message == WM_NCCREATE)
		{
			CREATESTRUCT* create_struct = reinterpret_cast<CREATESTRUCT*>(long_parameter);
			void* raw_pointer = create_struct->lpCreateParams;
			LONG_PTR long_pointer = reinterpret_cast<LONG_PTR>(raw_pointer);
			SetWindowLongPtr(window_handle, GWLP_USERDATA, long_pointer);
		}

		windows_window* window = reinterpret_cast<windows_window*>(GetWindowLongPtr(window_handle, GWLP_USERDATA));

		switch (message)
		{
		case WM_MOVE:
		{
			int x = (int)(short)LOWORD(long_parameter);
			int y = (int)(short)HIWORD(long_parameter);

			if (window)
			{
				window->set_x(static_cast<dimension_t>(x));
				window->set_y(static_cast<dimension_t>(y));
			}
		} break;

		case WM_SIZE:
		{
			int width = (int)(short)LOWORD(long_parameter);
			int height = (int)(short)HIWORD(long_parameter);

			if (window)
			{
				window->set_width(static_cast<dimension_t>(width));
				window->set_height(static_cast<dimension_t>(height));
			}
		} break;

		case WM_CREATE:
			window_count_++;
			return 0;

		case WM_CLOSE:
			if (window_count_ > 0)
			{
				window_count_--;
			}

			DestroyWindow(window_handle);

			return 0;

		case WM_DESTROY:
			if (window_count_ <= 0)
			{
				if (window)
				{
					window->unregister_window_class();
				}

				PostQuitMessage(0);
			}

			return 0;
		}

		return DefWindowProc(window_handle, message, wide_parameter, long_parameter);
	}

	void windows_window::register_window_class()
	{
		if (is_class_registered_)
		{
			return;
		}

		WNDCLASS window_class = { };
		window_class.lpszClassName = CLASS_NAME;
		window_class.hInstance = instance_handle_;
		window_class.hIcon = LoadIcon(nullptr, IDI_WINLOGO);
		window_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
		window_class.lpfnWndProc = window_procedure;

		RegisterClass(&window_class);
		is_class_registered_ = true;
	}

	void windows_window::unregister_window_class()
	{
		if (!is_class_registered_)
		{
			return;
		}

		UnregisterClass(CLASS_NAME, instance_handle_);
		is_class_registered_ = false;
	}

	std::wstring windows_window::get_wide_title() const
	{
		const std::string& title = get_title();
		return std::wstring(title.begin(), title.end());
	}

	bool windows_window::process_messages()
	{
		MSG message = { };

		while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
			{
				close();
				return false;
			}

			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		return true;
	}

	void windows_window::set_position(dimension_t x, dimension_t y, dimension_t width, dimension_t height) const
	{
		UINT flags = SWP_NOZORDER | SWP_NOACTIVATE;

		SetWindowPos(
			window_handle_,
			nullptr,
			static_cast<int>(x),
			static_cast<int>(y),
			static_cast<int>(width),
			static_cast<int>(height),
			flags
		);
	}
}
