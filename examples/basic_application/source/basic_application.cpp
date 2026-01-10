// File:       basic_application.cpp
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

#include "basic_application/basic_application.hpp"

#include "basic_application/basic_layer.hpp"

namespace basic_application {
	basic_application::basic_application(basic_application&& other) noexcept {
		window_ = std::move(other.window_);
		other.window_ = nullptr;
	}

	basic_application& basic_application::operator=(basic_application&& other) noexcept {
		if (this != &other) {
			window_ = std::move(other.window_);
			other.window_ = nullptr;
		}

		return *this;
	}

	void basic_application::_initialize() {
		window_ = citadel::window::create(100, 100, 960, 540, "Basic Application");
		CITADEL_ASSERT(window_, "Failed to open window");

		window_->set_vsync(false);
		window_->surface().set_clear_color({ 30, 30, 30, 255 });

		citadel::reference<basic_layer> layer = citadel::make_referenced<basic_layer>();
		window_->layer_stack().push(layer);

		window_->show();
	}

	citadel::exit_code basic_application::_run() {
		while (window_->update()) {
			window_->begin_frame();
			window_->render();
			window_->end_frame();
		}

		return citadel::exit_code::success;
	}

	void basic_application::_shutdown() { }
}
