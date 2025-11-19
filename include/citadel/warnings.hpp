// File:       warnings.hpp
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
#include "citadel/pragma.hpp"

#if CITADEL_COMPILER_MSVC
	#define CITADEL_WARNING_UNREACHABLE_CODE 4702
	#define CITADEL_WARNING_PADDING          4820
	#define CITADEL_WARNING_SPECTRE          5045
#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
	#define CITADEL_WARNING_UNREACHABLE_CODE "-Wunreachable-code"
	#define CITADEL_WARNING_PADDING
	#define CITADEL_WARNING_SPECTRE          "-Wno-spectre"
#else
	#define CITADEL_WARNING_UNREACHABLE_CODE
	#define CITADEL_WARNING_PADDING
	#define CITADEL_WARNING_SPECTRE
#endif

#if CITADEL_COMPILER_MSVC
	#define CITADEL_IGNORE_WARNING_PUSH() CITADEL_PRAGMA(warning(push))
	#define CITADEL_IGNORE_WARNING(name)  CITADEL_PRAGMA(warning(disable : name))
	#define CITADEL_IGNORE_WARNING_POP()  CITADEL_PRAGMA(warning(pop))
#elif CITADEL_COMPILER_CLANG
	#define CITADEL_IGNORE_WARNING_PUSH() CITADEL_PRAGMA(clang diagnostic push)
	#define CITADEL_IGNORE_WARNING(name)  CITADEL_PRAGMA(clang diagnostic ignored name)
	#define CITADEL_IGNORE_WARNING_POP()  CITADEL_PRAGMA(clang diagnostic pop)
#elif CITADEL_COMPILER_GCC
	#define CITADEL_IGNORE_WARNING_PUSH() CITADEL_PRAGMA(GCC diagnostic push)
	#define CITADEL_IGNORE_WARNING(name)  CITADEL_PRAGMA(GCC diagnostic ignored name)
	#define CITADEL_IGNORE_WARNING_POP()  CITADEL_PRAGMA(GCC diagnostic pop)
#else
	#define CITADEL_IGNORE_WARNING_PUSH()
	#define CITADEL_IGNORE_WARNING(name)
	#define CITADEL_IGNORE_WARNING_POP()
#endif
