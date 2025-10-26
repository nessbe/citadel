// File:       attributes.hpp
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

#include "citadel/compilers.hpp"

#ifndef nodisc
	#if CITADEL_COMPILER_MSVC
		#include <sal.h>
		#define nodisc _Check_return_
	#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define nodisc __attribute__((warn_unused_result))
	#else
		#define nodisc [[nodiscard]]
	#endif
#endif

#ifndef noret
	#if CITADEL_COMPILER_MSVC
		#define noret __declspec(noreturn)
	#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define noret __attribute__((noreturn))
	#else
		#define noret [[noreturn]]
	#endif
#endif

#ifndef deprec
	#if CITADEL_COMPILER_MSVC
		#define deprec __declspec(deprecated)
	#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define deprec __attribute__((deprecated))
	#else
		#define deprec [[deprecated]]
	#endif
#endif

#ifndef deprec_message
	#if CITADEL_COMPILER_MSVC
		#define deprec_message(message) __declspec(deprecated(message))
	#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define deprec_message(message) __attribute__((deprecated(message)))
	#else
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
		#define likely(condition) __builtin_expect(!!(condition), 1)
	#else
		#define likely(condition) (condition)
	#endif
#endif

#ifndef unlikely
	#if CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define unlikely(condition) __builtin_expect(!!(condition), 0)
	#else
		#define unlikely(condition) (condition)
	#endif
#endif

#ifndef forceinline
	#if CITADEL_COMPILER_MSVC
		#define forceinline __forceinline
	#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define forceinline inline __attribute__((always_inline))
	#else
		#define forceinline inline
	#endif
#endif
