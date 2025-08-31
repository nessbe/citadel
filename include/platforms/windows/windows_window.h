// File:        windows_window.h
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

#pragma once

#ifndef CITADEL_WINDOWS_WINDOW_H
#define CITADEL_WINDOWS_WINDOW_H

#include <cstddef>

#include "citadel/attributes.h"
#include "citadel/export.h"
#include "citadel/platforms.h"

#include "citadel/core/window.h"

#if CITADEL_PLATFORM_WINDOWS

#include <Windows.h>

namespace citadel
{
	class windows_window : public window
	{
	public:
		windows_window(dimension_t x, dimension_t y, dimension_t width, dimension_t height, const std::string& title)
			: window(x, y, width, height, title), instance_handle_(GetModuleHandle(nullptr)) { }

		CITADEL_API virtual ~windows_window() override;

	private:
		const wchar_t* CLASS_NAME = L"citadel_window";
		static inline std::size_t window_count_;

		HWND window_handle_ = nullptr;
		HINSTANCE instance_handle_;

		bool is_class_registered_ = false;

	private:
		CITADEL_API virtual void _open() override;
		CITADEL_API virtual void _close() override;

		CITADEL_API virtual void _show() override;
		CITADEL_API virtual void _hide() override;

		CITADEL_API virtual bool _update() override;
		CITADEL_API virtual void _render() override;

		CITADEL_API virtual void _begin_step() override;
		CITADEL_API virtual void _end_step() override;

		CITADEL_API virtual void _set_x(dimension_t x) override;
		CITADEL_API virtual void _set_y(dimension_t y) override;

		CITADEL_API virtual void _set_width(dimension_t width) override;
		CITADEL_API virtual void _set_height(dimension_t height) override;

		CITADEL_API virtual void _set_title(const std::string& title) override;

		CITADEL_API CITADEL_GETTER virtual void* _get_native_handle() const override;

		CITADEL_API static LRESULT CALLBACK window_procedure(HWND window_handle, UINT message, WPARAM wide_parameter, LPARAM long_parameter);

		CITADEL_API void register_window_class();
		CITADEL_API void unregister_window_class();

		CITADEL_API CITADEL_GETTER std::wstring get_wide_title() const;

		CITADEL_API bool process_messages();
	};
}

#endif

#endif
