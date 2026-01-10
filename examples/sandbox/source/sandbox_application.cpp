// File:       sandbox_application.cpp
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

#include "sandbox/sandbox_application.hpp"

#include "sandbox/sandbox.hpp"
#include "sandbox/sandbox_layer.hpp"

namespace sandbox {
	sandbox_application::sandbox_application(sandbox_application&& other) noexcept {
		window_ = std::move(other.window_);
		other.window_ = nullptr;
	}

	sandbox_application& sandbox_application::operator=(sandbox_application&& other) noexcept {
		if (this != &other) {
			window_ = std::move(other.window_);
			other.window_ = nullptr;
		}

		return *this;
	}

	void sandbox_application::_initialize() {
		application_initialize(this);
	}

	citadel::exit_code sandbox_application::_run() {
		window_ = citadel::window::create(
			100, 100,
			960, 520,
			"Sandbox Application"
		);

		window_->layer_stack().push(citadel::make_referenced<sandbox_layer>());

		window_->set_vsync(false);
		window_->show();

		citadel::exit_code exit_code = application_run(this);

		while (window_->update()) {
			window_->begin_frame();
			window_->render();
			window_->end_frame();
		}

		return exit_code;
	}

	void sandbox_application::_shutdown() {
		application_shutdown(this);
	}
}
