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
	application& application::get() {
		CITADEL_POINTER_RETURN_REFERENCE(instance_);
	}

	void application::initialize() {
		engine_ = make_scoped<engine>();
		CITADEL_POINTER_CALL(engine_, initialize);
		_initialize();
	}

	exit_code application::run() {
		exit_code engine_exit_code = CITADEL_POINTER_CALL_OR_DEFAULT(engine_, run, exit_code::failure);
		exit_code application_exit_code = _run();

		exit_code exit_code = static_cast<enum exit_code>(engine_exit_code | application_exit_code);

		return exit_code;
	}

	void application::shutdown() {
		_shutdown();
		CITADEL_POINTER_CALL(engine_, shutdown);
		engine_ = nullptr;
	}

	void application::exit(exit_code code) {
		shutdown();
		std::exit(static_cast<int>(code));
	}

	std::size_t application::get_error_level() const noexcept {
		return error_level_;
	}

	void application::notify_error() noexcept {
		error_level_++;
	}

	engine& application::get_engine() const {
		CITADEL_POINTER_RETURN_REFERENCE(engine_);
	}

	application* application::instance_ = nullptr;
}
