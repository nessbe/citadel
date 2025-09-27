// File:       platforms.hpp
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

#define CITADEL_PLATFORM_WINDOWS       0
#define CITADEL_PLATFORM_WIN32         0
#define CITADEL_PLATFORM_WIN64         0
#define CITADEL_PLATFORM_APPLE         0
#define CITADEL_PLATFORM_IOS_SIMULATOR 0
#define CITADEL_PLATFORM_IOS           0
#define CITADEL_PLATFORM_MACOS         0
#define CITADEL_PLATFORM_ANDROID       0
#define CITADEL_PLATFORM_LINUX         0

#ifdef _WIN32
	#undef CITADEL_PLATFORM_WINDOWS
	#define CITADEL_PLATFORM_WINDOWS 1

	#ifdef _WIN64
		#undef CITADEL_PLATFORM_WIN64
		#define CITADEL_PLATFORM_WIN64 1
	#else
		#undef CITADEL_PLATFORM_WIN32
		#define CITADEL_PLATFORM_WIN32 1
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>

	#undef CITADEL_PLATFORM_APPLE
	#define CITADEL_PLATFORM_APPLE 0

	#if TARGET_IPHONE_SIMULATOR
		#undef CITADEL_PLATFORM_IOS_SIMULATOR
		#define CITADEL_PLATFORM_IOS_SIMULATOR 1
	#elif TARGET_OS_IPHONE
		#undef CITADEL_PLATFORM_IOS
		#define CITADEL_PLATFORM_IOS 1
	#elif TARGET_OS_MAC
		#undef CITADEL_PLATFORM_MACOS
		#define CITADEL_PLATFORM_MACOS 1
	#endif
#elif defined(__ANDROID__)
	#undef CITADEL_PLATFORM_ANDROID
	#define CITADEL_PLATFORM_ANDROID 1
#elif defined(__linux__)
	#undef CITADEL_PLATFORM_LINUX
	#define CITADEL_PLATFORM_LINUX 1
#endif
