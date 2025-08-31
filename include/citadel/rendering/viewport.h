// File:        viewport.h
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

#ifndef CITADEL_VIEWPORT_H
#define CITADEL_VIEWPORT_H

#include "citadel/attributes.h"
#include "citadel/export.h"

#include "citadel/rendering/color.h"

namespace citadel
{
	class viewport
	{
	public:
		using dimension_t = unsigned int;

	public:
		viewport(dimension_t x, dimension_t y, dimension_t width, dimension_t height)
			: x_(x), y_(y), width_(width), height_(height) { }

		virtual ~viewport() = default;

		CITADEL_API void bind() const;
		CITADEL_API void clear() const;

		CITADEL_API CITADEL_GETTER dimension_t get_x() const noexcept;
		CITADEL_API CITADEL_SETTER void set_x(dimension_t x) noexcept;

		CITADEL_API CITADEL_GETTER dimension_t get_y() const noexcept;
		CITADEL_API CITADEL_SETTER void set_y(dimension_t y) noexcept;

		CITADEL_API CITADEL_GETTER dimension_t get_width() const noexcept;
		CITADEL_API CITADEL_SETTER void set_width(dimension_t width) noexcept;

		CITADEL_API CITADEL_GETTER dimension_t get_height() const noexcept;
		CITADEL_API CITADEL_SETTER void set_height(dimension_t height) noexcept;

		CITADEL_API CITADEL_SETTER color get_clear_color() const;
		CITADEL_API CITADEL_SETTER void set_clear_color(color clear_color);

	private:
		dimension_t x_, y_, width_, height_;
		color clear_color_ = color(color::MAX_CHANNEL_VALUE, color::MAX_CHANNEL_VALUE, color::MAX_CHANNEL_VALUE);

	private:
		virtual void _bind() const = 0;
		virtual void _clear() const = 0;
	};
}

#endif
