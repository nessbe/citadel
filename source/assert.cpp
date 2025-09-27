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
	void debugbreak() {
#ifdef CITADEL_ENABLE_DEBUGBREAK
	#if CITADEL_COMPILER_MSVC
		__debugbreak();
	#elif CITADEL_COMPILER_CLANG || CITADEL_COMPILER_GCC
		#if CITADEL_ARCHITECTURE_X86_32 || CITADEL_ARCHITECTURE_X86_64
			__asm__ volatile("int3");
		#elif CITADEL_ARCHITECTURE_ARM_64
			__asm__ volatile("brk #0");
		#elif CITADEL_ARCHITECTURE_ARM_32
			__asm__ volatile("bkpt #0");
		#else
			raise(SIGTRAP);
		#endif
	#else
		std::abort();
	#endif
#endif
	}

	void assert(bool condition, const std::string& message) {
#ifdef CITADEL_ENABLE_ASSERTION
		if (!condition) {
			std::cerr << message << std::endl;
			debugbreak();
		}
#endif
	}
}
