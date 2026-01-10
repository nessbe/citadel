// File:       assert.cpp
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
#include "citadel/debug/assert.hpp"

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

	void assert(bool condition) noexcept {
		if (CITADEL_UNLIKELY(!condition)) {
			panic();
		}
	}
}
