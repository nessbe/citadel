// File:       application.cpp
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
#include "citadel/core/application.hpp"

namespace citadel {
	void application::initialize() {
		engine_ = std::make_unique<engine>();
		CITADEL_ASSERT(engine_, "Failed to create engine");

		if (engine_) {
			engine_->initialize();
		}

		_initialize();
	}

	int application::run() {
		CITADEL_ASSERT(engine_, "Engine pointer is null");

		int engine_exit_code = engine_ ? engine_->run() : 0;
		int application_exit_code = _run();

		return engine_exit_code | application_exit_code;
	}

	void application::shutdown() {
		_shutdown();

		CITADEL_ASSERT(engine_, "Engine pointer is null");

		if (engine_) {
			engine_->shutdown();
		}

		engine_ = nullptr;
	}

	engine& application::get_engine() const {
		CITADEL_ASSERT(engine_, "Engine pointer is null");
		return *engine_;
	}
}
