// File:       attributes.hpp
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

#pragma once

#include "citadel/compilers.hpp"

#ifndef CITADEL_NODISCARD
	#if CITADEL_COMPILER_MSVC
		#include <sal.h>
		#define CITADEL_NODISCARD _Check_return_
	#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define CITADEL_NODISCARD __attribute__((warn_unused_result))
	#else
		#define CITADEL_NODISCARD [[nodiscard]]
	#endif
#endif

#ifndef CITADEL_NORETURN
	#if CITADEL_COMPILER_MSVC
		#define CITADEL_NORETURN __declspec(noreturn)
	#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define CITADEL_NORETURN __attribute__((noreturn))
	#else
		#define CITADEL_NORETURN [[noreturn]]
	#endif
#endif

#ifndef CITADEL_DEPRECATED
	#if CITADEL_COMPILER_MSVC
		#define CITADEL_DEPRECATED __declspec(deprecated)
	#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define CITADEL_DEPRECATED __attribute__((deprecated))
	#else
		#define CITADEL_DEPRECATED [[deprecated]]
	#endif
#endif

#ifndef CITADEL_DEPRECATED_MESSAGE
	#if CITADEL_COMPILER_MSVC
		#define CITADEL_DEPRECATED_MESSAGE(message) __declspec(deprecated(message))
	#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define CITADEL_DEPRECATED_MESSAGE(message) __attribute__((deprecated(message)))
	#else
		#define CITADEL_DEPRECATED_MESSAGE(message) [[deprecated(message)]]
	#endif
#endif

#ifndef CITADEL_LIKELY
	#if CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define CITADEL_LIKELY(condition) __builtin_expect(!!(condition), 1)
	#else
		#define CITADEL_LIKELY(condition) (condition)
	#endif
#endif

#ifndef CITADEL_UNLIKELY
	#if CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define CITADEL_UNLIKELY(condition) __builtin_expect(!!(condition), 0)
	#else
		#define CITADEL_UNLIKELY(condition) (condition)
	#endif
#endif

#ifndef CITADEL_FORCE_INLINE
	#if CITADEL_COMPILER_MSVC
		#define CITADEL_FORCE_INLINE __forceinline
	#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
		#define CITADEL_FORCE_INLINE inline __attribute__((always_inline))
	#else
		#define CITADEL_FORCE_INLINE inline
	#endif
#endif
