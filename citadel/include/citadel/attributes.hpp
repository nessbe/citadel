// File:       attributes.hpp
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

#include "citadel/compilers.hpp"

#ifndef nodisc
	#if CITADEL_COMPILER_MSVC
		#define nodisc _Check_return_
	#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define nodisc __attribute__((warn_unused_result))
	#else
		#define nodisc [[nodiscard]]
	#endif
#endif

#ifndef deprec
	#if CITADEL_COMPILER_MSVC
		#define deprec                  __declspec(deprecated)
		#define deprec_message(message) __declspec(deprecated(message))
	#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define deprec                  __attribute__((deprecated))
		#define deprec_message(message) __attribute__((deprecated(message)))
	#else
		#define deprec                  [[deprecated]]
		#define deprec_message(message) [[deprecated(message)]]
	#endif
#endif

#ifndef unused
	#if CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define unused __attribute__((unused))
	#else
		#define unused [[maybe_unused]]
	#endif
#endif

#ifndef likely
	#if CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define likely(x) __builtin_expect(!!(x), 1)
	#else
		#define likely(x) (x)
	#endif
#endif

#ifndef unlikely
	#if CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define unlikely(x) __builtin_expect(!!(x), 0)
	#else
		#define unlikely(x) (x)
	#endif
#endif

#ifndef forceinline
	#if CITADEL_COMPILER_MSVC
		#define forceinl __forceinline
	#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define forceinl inline __attribute__((always_inline))
	#else
		#define forceinl inline
	#endif
#endif
