// File:        viewport.cpp
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
#include "citadel/rendering/viewport.h"

namespace citadel
{
	void viewport::bind() const
	{
		_bind();
	}

	void viewport::clear() const
	{
		_clear();
	}

	viewport::dimension_t viewport::get_x() const noexcept
	{
		return x_;
	}

	void viewport::set_x(dimension_t x) noexcept
	{
		x_ = x;
	}

	viewport::dimension_t viewport::get_y() const noexcept
	{
		return y_;
	}

	void viewport::set_y(dimension_t y) noexcept
	{
		y_ = y;
	}

	viewport::dimension_t viewport::get_width() const noexcept
	{
		return width_;
	}

	void viewport::set_width(dimension_t width) noexcept
	{
		width_ = width;
	}

	viewport::dimension_t viewport::get_height() const noexcept
	{
		return height_;
	}

	void viewport::set_height(dimension_t height) noexcept
	{
		height_ = height;
	}

	color viewport::get_clear_color() const
	{
		return clear_color_;
	}

	void viewport::set_clear_color(color clear_color)
	{
		clear_color_ = clear_color;
	}
}
