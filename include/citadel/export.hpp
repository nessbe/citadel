// File:       export.hpp
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

#if CITADEL_COMPILER_MSVC
	#define CITADEL_EXPORT   __declspec(dllexport)
	#define CITADEL_IMPORT   __declspec(dllimport)
	#define CITADEL_NOEXPORT
#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
	#define CITADEL_EXPORT   __attribute__((visibility("default")))
	#define CITADEL_IMPORT   __attribute__((visibility("default")))
	#define CITADEL_NOEXPORT __attribute__((visibility("hidden")))
#else
	#define CITADEL_EXPORT
	#define CITADEL_IMPORT
	#define CITADEL_NOEXPORT
#endif

#ifdef CITADEL_LINKAGE_STATIC
	#define CITADEL_API
#elif defined(CITADEL_LINKAGE_DYNAMIC)
	#ifdef CITADEL_BUILD_DLL
		#define CITADEL_API CITADEL_EXPORT
	#else
		#define CITADEL_API CITADEL_IMPORT
	#endif
#else
	#define CITADEL_API CITADEL_NOEXPORT
#endif
