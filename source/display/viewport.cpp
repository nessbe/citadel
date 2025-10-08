// File:       viewport.cpp
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

#include "citadel/pch.hpp"
#include "citadel/display/viewport.hpp"

namespace citadel {
	viewport::viewport(dimension x, dimension y, dimension width, dimension height, color clear_color)
		: x_(x), y_(y), width_(width), height_(height), clear_color_(clear_color) { }

	viewport::viewport(dimension width, dimension height, color clear_color)
		: viewport(0, 0, width, height, clear_color) { }

	viewport::dimension viewport::get_x() const noexcept {
		return x_;
	}

	void viewport::set_x(dimension value) noexcept {
		x_ = value;
		_set_x(value);
	}

	viewport::dimension viewport::get_y() const noexcept {
		return y_;
	}

	void viewport::set_y(dimension value) noexcept {
		y_ = value;
		_set_y(value);
	}

	viewport::dimension viewport::get_width() const noexcept {
		return width_;
	}

	void viewport::set_width(dimension value) noexcept {
		width_ = value;
		_set_width(value);
	}

	viewport::dimension viewport::get_height() const noexcept {
		return height_;
	}

	void viewport::set_height(dimension value) noexcept {
		height_ = value;
		_set_height(value);
	}

	color viewport::get_clear_color() const noexcept {
		return clear_color_;
	}

	void viewport::set_clear_color(color value) noexcept {
		clear_color_ = value;
		_set_clear_color(value);
	}

	scope<viewport> viewport::create(dimension x, dimension y, dimension width, dimension height, color clear_color) {
		#error Citadel does not support your viewport system yet
		return nullptr;
	}

	scope<viewport> viewport::create(dimension width, dimension height, color clear_color) {
		return create(0, 0, width, height, clear_color);
	}
}
