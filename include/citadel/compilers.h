// File:        compilers.h
// Project:     citadel
// Repository:  https://github.com/nessbe/citadel
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

#define CITADEL_COMPILER_MSVC    0
#define CITADEL_COMPILER_CLANG   0
#define CITADEL_COMPILER_GCC     0
#define CITADEL_COMPILER_INTEL   0
#define CITADEL_COMPILER_MINGW   0
#define CITADEL_COMPILER_UNKNOWN 0

#define CITADEL_COMPILER_MSVC_NAME    "MSVC"
#define CITADEL_COMPILER_CLANG_NAME   "Clang"
#define CITADEL_COMPILER_GCC_NAME     "GCC"
#define CITADEL_COMPILER_INTEL_NAME   "Intel"
#define CITADEL_COMPILER_MINGW_NAME   "MinGW"
#define CITADEL_COMPILER_UNKNOWN_NAME "Unknown"

#ifdef _MSC_VER
	#undef CITADEL_COMPILER_MSVC
	#define CITADEL_COMPILER_MSVC 1
	#define CITADEL_COMPILER_VERSION _MSC_VER
	#define CITADEL_COMPILER_NAME CITADEL_COMPILER_MSVC_NAME
#elif defined(__clang__)
	#undef CITADEL_COMPILER_CLANG
	#define CITADEL_COMPILER_CLANG 1
	#define CITADEL_COMPILER_VERSION (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
	#define CITADEL_COMPILER_NAME CITADEL_COMPILER_CLANG_NAME
#elif defined(__MINGW32__) || defined(__MINGW64__)
	#undef CITADEL_COMPILER_MINGW
	#define CITADEL_COMPILER_MINGW 1
	#define CITADEL_COMPILER_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
	#define CITADEL_COMPILER_NAME CITADEL_COMPILER_MINGW_NAME
#elif defined(__GNUC__) || defined(__GNUG__)
	#undef CITADEL_COMPILER_GCC
	#define CITADEL_COMPILER_GCC 1
	#define CITADEL_COMPILER_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
	#define CITADEL_COMPILER_NAME CITADEL_COMPILER_GCC_NAME
#elif defined(__INTEL_COMPILER) || defined(__IC)
	#undef CITADEL_COMPILER_INTEL
	#define CITADEL_COMPILER_INTEL 1
	#define CITADEL_COMPILER_VERSION __INTEL_COMPILER
	#define CITADEL_COMPILER_NAME CITADEL_COMPILER_INTEL_NAME
#else
	#undef CITADEL_COMPILER_UNKNOWN
	#define CITADEL_COMPILER_UNKNOWN 1
	#define CITADEL_COMPILER_VERSION 0
	#define CITADEL_COMPILER_NAME CITADEL_COMPILER_UNKNOWN_NAME
#endif
