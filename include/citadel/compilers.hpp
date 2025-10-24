// File:       compilers.hpp
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

#define CITADEL_COMPILER_MSVC    0
#define CITADEL_COMPILER_CLANG   0
#define CITADEL_COMPILER_MINGW   0
#define CITADEL_COMPILER_GCC     0
#define CITADEL_COMPILER_INTEL   0
#define CITADEL_COMPILER_UNKNOWN 0

#ifdef _MSC_VER
	#undef CITADEL_COMPILER_MSVC
	#define CITADEL_COMPILER_MSVC 1
	#define CITADEL_COMPILER_VERSION _MSC_VER
#elif defined(__clang__)
	#undef CITADEL_COMPILER_CLANG
	#define CITADEL_COMPILER_CLANG 1
	#define CITADEL_COMPILER_VERSION (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
#elif defined(__MINGW32__) || defined(__MINGW64__)
	#undef CITADEL_COMPILER_MINGW
	#define CITADEL_COMPILER_MINGW 1
	#define CITADEL_COMPILER_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#elif defined(__GNUC__) || defined(__GNUG__)
	#undef CITADEL_COMPILER_GCC
	#define CITADEL_COMPILER_GCC 1
	#define CITADEL_COMPILER_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#elif defined(__INTEL_LLVM_COMPILER)
	#undef CITADEL_COMPILER_INTEL
	#define CITADEL_COMPILER_INTEL 1
	#define CITADEL_COMPILER_VERSION __VERSION__
#else
	#define CITADEL_COMPILER_VERSION 0
#endif
