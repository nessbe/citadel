// File:       platforms.hpp
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
