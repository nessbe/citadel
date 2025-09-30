// File:       windows_window.hpp
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

#pragma once

#include "citadel/platforms.hpp"

#if CITADEL_PLATFORM_WINDOWS

#include <windows.h>

#include "citadel/export.hpp"

#include "citadel/display/window.hpp"

namespace citadel {
	class windows_window : public window {
	public:
		static constexpr wchar_t* class_name = L"citadel_window";

	public:
		CITADEL_API windows_window(dimension x, dimension y, dimension width, dimension height, const std::string& title);
		CITADEL_API windows_window(dimension width, dimension height, const std::string& title);

		CITADEL_API static std::string get_class_name();

	private:
		HWND handle_;
		HINSTANCE instance_;

		CITADEL_API static std::size_t instance_count_;

	private:
		CITADEL_API static LRESULT CALLBACK window_procedure(HWND window_handle, UINT message, WPARAM wide_parameter, LPARAM long_parameter);

		CITADEL_API static void register_class();
		CITADEL_API static void unregister_class();

		CITADEL_API void update_rect() const;

		CITADEL_API virtual void _open() override;
		CITADEL_API virtual void _close() override;

		CITADEL_API virtual void _show() override;
		CITADEL_API virtual void _hide() override;

		CITADEL_API virtual void _maximize() override;
		CITADEL_API virtual void _minimize() override;

		CITADEL_API virtual void _update() override;

		CITADEL_API CITADEL_GETTER virtual void* _get_native_handle() const override;

		CITADEL_API virtual void _set_x(dimension x) override;
		CITADEL_API virtual void _set_y(dimension y) override;

		CITADEL_API virtual void _set_width(dimension height) override;
		CITADEL_API virtual void _set_height(dimension height) override;

		CITADEL_API virtual void _set_title(const std::string& title) override;
	};
}

#endif
