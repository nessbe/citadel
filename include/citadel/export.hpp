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
	#define export_attribute   __declspec(dllexport)
	#define import_attribute   __declspec(dllimport)
	#define noexport_attribute
#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
	#define export_attribute   __attribute__((visibility("default")))
	#define import_attribute   __attribute__((visibility("default")))
	#define noexport_attribute __attribute__((visibility("hidden")))
#else
	#define export_attribute
	#define import_attribute
	#define noexport_attribute
#endif

#ifdef CITADEL_LINKAGE_STATIC
	#define exported
#elif defined(CITADEL_LINKAGE_DYNAMIC)
	#ifdef CITADEL_BUILD_DLL
		#define exported export_attribute
	#else
		#define exported import_attribute
	#endif
#else
	#define exported noexport_attribute
#endif
