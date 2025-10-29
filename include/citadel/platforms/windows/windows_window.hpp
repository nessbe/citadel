// File:       windows_window.hpp
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

#pragma once

#include "citadel/platforms.hpp"

#if CITADEL_PLATFORM_WINDOWS

#include "citadel/export.hpp"

#include "citadel/display/window.hpp"

#include "citadel/platforms/windows.hpp"

namespace citadel {
	class api windows_window : public window {
	public:
		static constexpr const wchar_t* class_name = L"CitadelWindow";

	public:
		static bool register_class(const wchar_t* class_name);
		static bool unregister_class(const wchar_t* class_name);

		windows_window(dimension x, dimension y, dimension width, dimension height, const std::string& title);
		windows_window(dimension width, dimension height, const std::string& title);

		virtual ~windows_window() override;

	private:
		static std::size_t instance_count_;

		HWND window_;
		HINSTANCE instance_;

		DWORD style_ = WS_OVERLAPPEDWINDOW;

	private:
		static LRESULT CALLBACK window_procedure(HWND handle, UINT message, WPARAM wide_parameter, LPARAM long_parameter);

		RECT calculate_rect(dimension x, dimension y, dimension width, dimension height) const;
		void move_window(dimension x, dimension y, dimension width, dimension height) const;

		std::wstring get_wide_title() const;

		virtual void _open() override;
		virtual void _close() override;

		virtual void _show() override;
		virtual void _hide() override;

		virtual void _maximize() override;
		virtual void _minimize() override;

		virtual bool _update() override;
		virtual void _render() override;

		virtual void* _get_native_handle() const override;

		virtual void _set_x(dimension value) override;
		virtual void _set_y(dimension value) override;
		virtual void _set_width(dimension value) override;
		virtual void _set_height(dimension value) override;
		virtual void _set_title(const std::string& value) override;
	};
}

#endif
