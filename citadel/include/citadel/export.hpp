// File:       apiexport.hpp
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

#include "citadel/platforms.hpp"

#if CITADEL_PLATFORM_WINDOWS
	#define apiexport   __declspec(dllexport)
	#define apiimport   __declspec(dllimport)
	#define apinoexport
#else
	#define apiexport   __attribute__((visibility("default")))
	#define apiimport   __attribute__((visibility("default")))
	#define apinoexport __attribute__((visibility("hidden")))

#endif

#ifdef CITADEL_LINKAGE_STATIC
	#pragma message("Linking Citadel statically")
	#define api
#elif defined(CITADEL_LINKAGE_DYNAMIC)
	#pragma message("Linking Citadel dynamically")

	#ifdef CITADEL_BUILD_DLL
		#pragma message("Exporting Citadel symbols")
		#define api apiexport
	#else
		#pragma message("Importing Citadel symbols")
		#define api apiimport
	#endif
#else
	#pragma message("Citadel is not linking")
	#define api apinoexport
#endif
