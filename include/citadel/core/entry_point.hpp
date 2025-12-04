// File:       entry_point.hpp
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

#pragma once

#include "citadel/assert.hpp"
#include "citadel/export.hpp"

#include "citadel/core/application.hpp"
#include "citadel/core/exit_code.hpp"

namespace citadel {
	extern application* create_application();

	int run_application(int argc, char** argv) {
		application* application = create_application();
		CITADEL_ASSERT(application, "Failed to create application");

		application::instance_ = application;
		CITADEL_POINTER_CALL(application, initialize);

		exit_code exit_code = CITADEL_POINTER_CALL_OR_DEFAULT(application, run, exit_code::failure);
		CITADEL_POINTER_CALL(application, shutdown);

		application::instance_ = nullptr;
		delete application;

		return static_cast<int>(exit_code);
	}
}

int main(int argc, char** argv) {
	return citadel::run_application(argc, argv);
}
