// File:       sandbox_application.cpp
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

#include "sandbox/sandbox_application.hpp"

#include <iostream>

namespace sandbox {
	void sandbox_application::_initialize() { }

	int sandbox_application::_run() {
		std::cout << "Hello, World!" << std::endl;
		while (true);
		return 0;
	}

	void sandbox_application::_shutdown() { }
}

namespace citadel {
	application* create_application() {
		return new sandbox::sandbox_application();
	}
}
