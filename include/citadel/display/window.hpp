// File:       window.hpp
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

#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/input/input.hpp"

#include "citadel/memory/scope.hpp"

namespace citadel {
	class window {
	public:
		using dimension = unsigned int;

	public:
		CITADEL_API window(dimension x, dimension y, dimension width, dimension height, const std::string& title);

		window(dimension width, dimension height, const std::string& title)
			: window(0, 0, width, height, title) { }

		CITADEL_API virtual ~window();

		window(const window&) = delete;
		window& operator=(const window&) = delete;

		window(window&&) noexcept = delete;
		window& operator=(window&&) noexcept = delete;

		CITADEL_API void open();
		CITADEL_API void close();

		CITADEL_API void show();
		CITADEL_API void hide();

		CITADEL_API void maximize();
		CITADEL_API void minimize();

		CITADEL_API void update();

		CITADEL_API CITADEL_GETTER void* get_native_handle() const;

		CITADEL_API CITADEL_GETTER dimension get_x() const noexcept;
		CITADEL_API CITADEL_GETTER void set_x(dimension x) noexcept;

		CITADEL_API CITADEL_GETTER dimension get_y() const noexcept;
		CITADEL_API CITADEL_GETTER void set_y(dimension y) noexcept;

		CITADEL_API CITADEL_GETTER dimension get_width() const noexcept;
		CITADEL_API CITADEL_SETTER void set_width(dimension width) noexcept;

		CITADEL_API CITADEL_GETTER dimension get_height() const noexcept;
		CITADEL_API CITADEL_SETTER void set_height(dimension height) noexcept;

		CITADEL_API CITADEL_GETTER const std::string& get_title() const noexcept;
		CITADEL_API CITADEL_SETTER void set_title(const std::string& title);

		CITADEL_API CITADEL_GETTER bool is_visible() const noexcept;
		CITADEL_API CITADEL_GETTER bool is_open() const noexcept;

		CITADEL_API CITADEL_GETTER input& get_input() const noexcept;

		CITADEL_API CITADEL_NODISCARD static scope<window> create(dimension x, dimension y, dimension width, dimension height, const std::string& title);
		CITADEL_API CITADEL_NODISCARD static scope<window> create(dimension width, dimension y, const std::string& title);

	private:
		std::string title_;

		bool is_open_ = false;
		bool is_visible_ = false;

		scope<input> input_;

	private:
		virtual void _open() = 0;
		virtual void _close() = 0;

		virtual void _show() = 0;
		virtual void _hide() = 0;

		virtual void _maximize() = 0;
		virtual void _minimize() = 0;

		virtual void _update() = 0;

		virtual void* _get_native_handle() const = 0;

		virtual void _set_x(dimension x) = 0;
		virtual void _set_y(dimension y) = 0;

		virtual void _set_width(dimension height) = 0;
		virtual void _set_height(dimension height) = 0;

		virtual void _set_title(const std::string& title) = 0;

	protected:
		dimension x_, y_, width_, height_;
	};
}
