// File:       surface.cpp
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

#include "citadel/pch.hpp"
#include "citadel/display/surface.hpp"

namespace citadel {
	surface::surface(dimension x, dimension y, dimension width, dimension height, color clear_color)
		: x_(x), y_(y), width_(width), height_(height), clear_color_(clear_color) { }

	surface::surface(dimension width, dimension height, color clear_color)
		: surface(0, 0, width, height, clear_color) { }

	void surface::bind() {
		_bind();
	}

	void surface::unbind() {
		_unbind();
	}

	void surface::clear() {
		_clear();
	}

	void surface::present() {
		_present();
	}

	surface::dimension surface::get_x() const noexcept {
		return x_;
	}

	void surface::set_x(dimension value) {
		_set_x(value);
		x_ = value;
	}

	surface::dimension surface::get_y() const noexcept {
		return y_;
	}

	void surface::set_y(dimension value) {
		_set_y(value);
		y_ = value;
	}

	surface::dimension surface::get_width() const noexcept {
		return width_;
	}

	void surface::set_width(dimension value) {
		_set_width(value);
		width_ = value;
	}

	surface::dimension surface::get_height() const noexcept {
		return height_;
	}

	void surface::set_height(dimension value) {
		_set_height(value);
		height_ = value;
	}

	color surface::get_clear_color() const noexcept {
		return clear_color_;
	}

	void surface::set_clear_color(color value) noexcept {
		_set_clear_color(value);
		clear_color_ = value;
	}
}
