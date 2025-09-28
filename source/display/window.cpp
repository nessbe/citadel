// File:       window.cpp
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
#include "citadel/display/window.hpp"

namespace citadel {
	window::~window() {
		close();
	}

	void window::open() {
		_open();
		is_open_ = true;
	}

	void window::close() {
		_close();
		is_open_ = false;
	}

	void window::show() {
		_show();
		is_visible_ = true;
	}

	void window::hide() {
		_hide();
		is_visible_ = false;
	}

	void window::maximize() {
		_maximize();
	}

	void window::minimize() {
		_minimize();
	}

	void window::update() {
		_update();
	}

	bool window::is_open() const noexcept {
		return is_open_;
	}

	bool window::is_visible() const noexcept {
		return is_visible_;
	}

	void* window::get_native_handle() const {
		return _get_native_handle();
	}

	window::dimension window::get_x() const noexcept {
		return x_;
	}

	void window::set_x(dimension x) noexcept {
		x_ = x;
		_set_x(x);
	}

	window::dimension window::get_y() const noexcept {
		return y_;
	}

	void window::set_y(dimension y) noexcept {
		y_ = y;
		_set_y(y);
	}

	window::dimension window::get_width() const noexcept {
		return width_;
	}

	void window::set_width(dimension width) noexcept {
		width_ = width;
		_set_width(width);
	}

	window::dimension window::get_height() const noexcept {
		return height_;
	}

	void window::set_height(dimension height) noexcept {
		height_ = height;
		_set_height(height);
	}

	const std::string& window::get_title() const noexcept {
		return title_;
	}

	void window::set_title(const std::string& title) {
		title_ = title;
		_set_title(title);
	}
}
