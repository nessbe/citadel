// File:       export.hpp
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

#if CITADEL_COMPILER_MSVC
	#define api_export   __declspec(dllexport)
	#define api_import   __declspec(dllimport)
	#define api_noexport
#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
	#define api_export   __attribute__((visibility("default")))
	#define api_import   __attribute__((visibility("default")))
	#define api_noexport __attribute__((visibility("hidden")))
#else
	#define api_export
	#define api_import
	#define api_noexport
#endif

#ifdef CITADEL_LINKAGE_STATIC
	#define api
#elif defined(CITADEL_LINKAGE_DYNAMIC)
	#ifdef CITADEL_BUILD_DLL
		#define api api_export
	#else
		#define api api_import
	#endif
#else
	#define api api_noexport
#endif
