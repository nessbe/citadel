// File:       window.cpp
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
#include "citadel/display/window.hpp"

#if CITADEL_PLATFORM_WINDOWS
	#include "citadel/platforms/windows/windows_window.hpp"
#endif

namespace citadel {
	std::unique_ptr<window> window::create(dimension x, dimension y, dimension width, dimension height, const std::string& title) {
#if CITADEL_PLATFORM_WINDOWS
		return std::make_unique<windows_window>(x, y, width, height, title);
#else
	#error Citadel does not support your window system yet
		return nullptr;
#endif
	}

	std::unique_ptr<window> window::create(dimension width, dimension height, const std::string& title) {
		return create(0, 0, width, height, title);
	}

	window::window(dimension x, dimension y, dimension width, dimension height, const std::string& title) :
		x_(x),
		y_(y),
		width_(width),
		height_(height),
		title_(title),
		surface_(std::make_unique<surface>(x, y, width, height, color(255, 255, 255, 255))) {
		CITADEL_ASSERT(surface_, "Failed to create surface");
	}

	window::window(dimension width, dimension height, const std::string& title)
		: window(0, 0, width, height, title) { }

	void window::open() {
		if (likely(!is_open_)) {
			_open();
		}

		is_open_ = true;
	}

	void window::close() {
		if (likely(is_open_)) {
			_close();
		}

		is_open_ = false;
	}

	void window::show() {
		if (likely(!is_visible_)) {
			_show();
		}

		is_visible_ = true;
	}

	void window::hide() {
		if (likely(is_visible_)) {
			_hide();
		}

		is_visible_ = false;
	}

	void window::maximize() {
		_maximize();
	}

	void window::minimize() {
		_minimize();
	}

	bool window::update() {
		if (!is_open()) {
			return false;
		}

		bool result = _update();

		if (!result) {
			close();
		}

		if (is_visible()) {
			render();
		}

		return result;
	}

	void window::render() {
		CITADEL_ASSERT(surface_, "Surface is null");

		surface_->bind();
		surface_->clear();

		_render();

		surface_->present();
		surface_->bind();
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

	void window::set_x(dimension value) {
		_set_x(value);
		x_ = value;
	}

	window::dimension window::get_y() const noexcept {
		return y_;
	}

	void window::set_y(dimension value) {
		_set_y(value);
		y_ = value;
	}

	window::dimension window::get_width() const noexcept {
		return width_;
	}

	void window::set_width(dimension value) {
		_set_width(value);
		width_ = value;
	}

	window::dimension window::get_height() const noexcept {
		return height_;
	}

	void window::set_height(dimension value) {
		_set_height(value);
		height_ = value;
	}

	const std::string& window::get_title() const noexcept {
		return title_;
	}

	void window::set_title(const std::string& value) {
		_set_title(value);
		title_ = value;
	}

	surface& window::get_surface() const {
		CITADEL_ASSERT(surface_, "Surface is null");
		return *surface_;
	}
}
