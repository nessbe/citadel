// File:        export.h
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

#ifndef CITADEL_EXPORT_H
#define CITADEL_EXPORT_H

#ifdef _WIN32
	#define CITADEL_EXPORT_ATTRIBUTE __declspec(dllexport)
	#define CITADEL_IMPORT_ATTRIBUTE __declspec(dllimport)
	#define CITADEL_NO_EXPORT_ATTRIBUTE
	#define CITADEL_DEPRECATED_ATTRIBUTE __declspec(deprecated)
#else
	#define CITADEL_EXPORT_ATTRIBUTE __attribute__((visibility("default")))
	#define CITADEL_IMPORT_ATTRIBUTE __attribute__((visibility("default")))
	#define CITADEL_NO_EXPORT_ATTRIBUTE __attribute__((visibility("hidden")))
	#define CITADEL_DEPRECATED_ATTRIBUTE __attribute__((__deprecated__))
#endif

#ifdef CITADEL_LINKAGE_STATIC
	#define CITADEL_API CITADEL_NO_EXPORT_ATTRIBUTE
#elif defined(CITADEL_LINKAGE_DYNAMIC)
	#ifdef CITADEL_BUILD_DLL
		#define CITADEL_API CITADEL_EXPORT_ATTRIBUTE
	#else
		#define CITADEL_API CITADEL_IMPORT_ATTRIBUTE
	#endif
#else
	#define CITADEL_API CITADEL_NO_EXPORT_ATTRIBUTE
#endif

#define CITADEL_API_DEPRECATTED \
	CITADEL_API CITADEL_DEPRECATED_ATTRIBUTE

#endif
