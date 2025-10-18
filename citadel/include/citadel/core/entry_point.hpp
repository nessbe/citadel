// File:       entry_point.hpp
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

#pragma once

#include "citadel/platforms.hpp"

#include "citadel/core/application.hpp"

namespace citadel {
	extern application* create_application();

	int run_application(int argc, char** argv) {
		application* application = create_application();
		application->initialize();

		int exit_code = application->run();

		application->shutdown();
		delete application;

		return exit_code;
	}
}

#if CITADEL_PLATFORM_WINDOWS && defined(CITADEL_DISTRIBUTION)

#include <windows.h>

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous_instance, LPSTR command_line, int command_show) {
	return citadel::run_application(__argc, __argv);
}

#else

int main(int argc, char** argv) {
	return citadel::run_application(argc, argv);
}

#endif
