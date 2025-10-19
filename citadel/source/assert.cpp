// File:       assert.cpp
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
#include "citadel/assert.hpp"

namespace citadel {
	void panic() noexcept {
#if CITADEL_COMPILER_MSVC
		__debugbreak();
#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		__builtin_trap();
#else
		std::abort();
#endif
	}

	void panic(const std::string& message) {
		std::cout << "Program panicked: " << message << std::endl;
		panic();
	}

	void assert(bool condition) noexcept {
		if (unlikely(!condition)) {
			panic();
		}
	}

	void assert(bool condition, const std::string& message) {
		if (unlikely(!condition)) {
			std::cout << "Assertion failed: " << message << std::endl;
			panic();
		}
	}
}
