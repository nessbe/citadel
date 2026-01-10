// File:       windows_window.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
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
#include "citadel/warnings.hpp"

#include "citadel/core/display/window.hpp"

#include "citadel/platforms/windows.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class CITADEL_API windows_window : public window {
	public:
		static constexpr const universal_char* class_name = CITADEL_UNIVERSAL_STRING("CitadelWindow");

	public:
		static bool register_class(const universal_char* name);
		static bool unregister_class(const universal_char* name);

		windows_window(rendering_api_type rendering_api, dimension_type x, dimension_type y, dimension_type width, dimension_type height, const std::string& title);
		windows_window(rendering_api_type rendering_api, dimension_type width, dimension_type height, const std::string& title);

		windows_window(const windows_window&) = delete;
		windows_window& operator=(const windows_window&) = delete;

		virtual ~windows_window() override;

	private:
		static std::size_t instance_count_;

		HWND window_;
		HINSTANCE instance_;

		DWORD style_ = WS_OVERLAPPEDWINDOW;

	private:
		static LRESULT CALLBACK window_procedure(HWND handle, UINT message, WPARAM wide_parameter, LPARAM long_parameter);

		RECT calculate_rect(dimension_type x, dimension_type y, dimension_type width, dimension_type height) const;
		void move_window(dimension_type x, dimension_type y, dimension_type width, dimension_type height) const;

		universal_string get_universal_title() const;

		virtual void _show() override;
		virtual void _hide() override;

		virtual void _maximize() override;
		virtual void _minimize() override;

		virtual bool _update(double delta) override;
		virtual void _render() override;

		virtual void _begin_frame() override;
		virtual void _end_frame() override;

		virtual void* _get_native_handle() const override;

		virtual void _set_title(const std::string& value) override;

		virtual void _set_x(dimension_type value) override;
		virtual void _set_y(dimension_type value) override;
		virtual void _set_width(dimension_type value) override;
		virtual void _set_height(dimension_type value) override;

		virtual void _set_vsync(bool value) override;
	};
}

CITADEL_WARNING_IGNORE_POP

#endif
