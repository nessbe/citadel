// File:       window.cpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#include "citadel/pch.hpp"
#include "citadel/core/display/window.hpp"

#include "citadel/rendering/render_command.hpp"

#include "citadel/platforms/windows/windows_window.hpp"

namespace citadel {
	scope<window> window::create(rendering_api_type rendering_api, dimension_type x, dimension_type y, dimension_type width, dimension_type height, const std::string& title) {
#if CITADEL_PLATFORM_WINDOWS
		scope<windows_window> window = make_scoped<windows_window>(rendering_api, x, y, width, height, title);
		window->initialize(rendering_api);
		return window;

#else
	#error Citadel does not support your window system yet
		return nullptr;
#endif
	}

	scope<window> window::create(rendering_api_type rendering_api, dimension_type width, dimension_type height, const std::string& title) {
#if CITADEL_PLATFORM_WINDOWS
		return make_scoped<windows_window>(rendering_api, width, height, title);
#else
#error Citadel does not support your window system yet
		return nullptr;
#endif
	}

	scope<window> window::create(dimension_type x, dimension_type y, dimension_type width, dimension_type height, const std::string& title) {
		return create(render_command::get_api(), x, y, width, height, title);
	}

	scope<window> window::create(dimension_type width, dimension_type height, const std::string& title) {
		return create(render_command::get_api(), width, height, title);
	}

	window::window(rendering_api_type rendering_api, dimension_type x, dimension_type y, dimension_type width, dimension_type height, const std::string& title) :
		x_(x),
		y_(y),
		width_(width),
		height_(height),
		title_(title),
		surface_(nullptr),
		rendering_context_(nullptr)
	{ }

	window::window(rendering_api_type rendering_api, dimension_type width, dimension_type height, const std::string& title)
		: window(rendering_api, 0, 0, width, height, title) { }

	void window::show() {
		if (CITADEL_LIKELY(!is_visible_)) {
			_show();
		}
		else {
			CITADEL_LOG_WARNING("Trying to show window '{0}' which is already visible", title_);
		}


		is_visible_ = true;
	}

	void window::hide() {
		if (CITADEL_LIKELY(is_visible_)) {
			_hide();
		}
		else {
			CITADEL_LOG_WARNING("Trying to hide window '{0}' which is already hidden", title_);
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
		if (should_close()) {
			return false;
		}

		clock_type::time_point now = clock_type::now();
		std::chrono::duration<double> elapsed_time = now - last_frame_;
		double delta_time = elapsed_time.count();

		bool result = _update(delta_time);
		layer_stack_.update(delta_time);

		if (!result) {
			set_should_close(true);
			return false;
		}

		last_frame_ = now;

		return result;
	}

	void window::render() {
		_render();
		layer_stack_.render(surface_);
	}

	void window::begin_frame() {
		rendering_context_->bind();
		surface_->bind();

		surface_->clear();
		_begin_frame();

		CITADEL_LOG_DEBUG("Beginning '{0}' window's frame", title_);
	}

	void window::end_frame() {
		_end_frame();

		surface_->present();
		rendering_context_->swap_buffers();

		surface_->unbind();
		rendering_context_->unbind();

		CITADEL_LOG_DEBUG("Ending '{0}' window's frame", title_);
	}

	void* window::get_native_handle() const {
		return _get_native_handle();
	}

	const std::string& window::get_title() const noexcept {
		return title_;
	}

	void window::set_title(const std::string& value) {
		_set_title(value);
		title_ = value;
	}

	layer_stack& window::layer_stack() {
		return layer_stack_;
	}

	surface& window::surface() const {
		return *surface_;
	}

	rendering_context& window::rendering_context() const {
		return *rendering_context_;
	}

	window::dimension_type window::get_x() const noexcept {
		return x_;
	}

	void window::set_x(dimension_type value) {
		_set_x(value);
		x_ = value;

		surface_->set_x(value);
	}

	window::dimension_type window::get_y() const noexcept {
		return y_;
	}

	void window::set_y(dimension_type value) {
		_set_y(value);
		y_ = value;

		surface_->set_y(value);
	}

	window::dimension_type window::get_width() const noexcept {
		return width_;
	}

	void window::set_width(dimension_type value) {
		_set_width(value);
		width_ = value;

		surface_->set_width(value);
	}

	window::dimension_type window::get_height() const noexcept {
		return height_;
	}

	void window::set_height(dimension_type value) {
		_set_height(value);
		height_ = value;

		surface_->set_height(value);
	}

	bool window::is_vsync() const noexcept {
		return is_vsync_;
	}

	void window::set_vsync(bool value) {
		_set_vsync(value);
		is_vsync_ = value;
	}

	bool window::should_close() const noexcept {
		return should_close_;
	}

	void window::set_should_close(bool value) noexcept {
		CITADEL_LOG_INFO("Window '{0}' should now close", title_);
		should_close_ = value;
	}

	bool window::is_visible() const noexcept {
		return is_visible_;
	}

	void window::initialize(rendering_api_type rendering_api) {
		surface_ = surface::create(rendering_api, x_, y_, width_, height_, color(color::max_value, color::max_value, color::max_value, color::max_value));
		rendering_context_ = rendering_context::create(rendering_api, this);

		CITADEL_POSTCONDITION(surface_ != nullptr, "Failed to create surface");
		CITADEL_POSTCONDITION(rendering_context_ != nullptr, "Failed to create rendering context");
	}
}
