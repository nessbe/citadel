// File:        window.h
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

#ifndef CITADEL_WINDOW_H
#define CITADEL_WINDOW_H

#include <cstddef>
#include <string>

#include "citadel/attributes.h"
#include "citadel/export.h"

#include "citadel/memory/scope.h"

#include "citadel/rendering/rendering_context.h"
#include "citadel/rendering/viewport.h"

namespace citadel
{
	class window
	{
	public:
		using dimension_t = unsigned int;

	public:
		window(dimension_t x, dimension_t y, dimension_t width, dimension_t height, const std::string& title);

		window(const window&) = delete;
		window& operator=(const window&) = delete;

		virtual ~window() = default;

		CITADEL_API void open();
		CITADEL_API void close();

		CITADEL_API void show();
		CITADEL_API void hide();

		CITADEL_API bool should_close() const;

		CITADEL_API void update();
		CITADEL_API void render();

		CITADEL_API void begin_step();
		CITADEL_API void end_step();

		CITADEL_API CITADEL_GETTER dimension_t get_x() const noexcept;
		CITADEL_API CITADEL_SETTER void set_x(dimension_t x) noexcept;

		CITADEL_API CITADEL_GETTER dimension_t get_y() const noexcept;
		CITADEL_API CITADEL_SETTER void set_y(dimension_t y) noexcept;

		CITADEL_API CITADEL_GETTER dimension_t get_width() const noexcept;
		CITADEL_API CITADEL_SETTER void set_width(dimension_t width);

		CITADEL_API CITADEL_GETTER dimension_t get_height() const noexcept;
		CITADEL_API CITADEL_SETTER void set_height(dimension_t height);

		CITADEL_API CITADEL_GETTER const std::string& get_title() const;
		CITADEL_API CITADEL_SETTER void set_title(const std::string& title);

		CITADEL_API CITADEL_GETTER bool is_running() const noexcept;
		CITADEL_API CITADEL_GETTER bool is_visible() const noexcept;

		CITADEL_API CITADEL_GETTER void* get_native_handle() const;
		CITADEL_API CITADEL_GETTER viewport& get_viewport();

	private:
		dimension_t x_ = 0;
		dimension_t y_ = 0;
		dimension_t width_ = 0;
		dimension_t height_ = 0;

		std::string title_;

		bool is_running_ = false;
		bool is_visible_ = false;

		scope<viewport> viewport_;
		scope<rendering_context> rendering_context_;

	private:
		virtual void _open() = 0;
		virtual void _close() = 0;

		virtual void _show() = 0;
		virtual void _hide() = 0;

		virtual bool _update() = 0;
		virtual void _render() = 0;

		virtual void _begin_step() = 0;
		virtual void _end_step() = 0;

		virtual void _set_x(dimension_t x) = 0;
		virtual void _set_y(dimension_t y) = 0;

		virtual void _set_width(dimension_t width) = 0;
		virtual void _set_height(dimension_t height) = 0;

		virtual void _set_title(const std::string& title) = 0;

		CITADEL_GETTER virtual void* _get_native_handle() const = 0;
	};
}

#endif
