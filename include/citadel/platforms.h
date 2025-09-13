// File:        platforms.h
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

// This file is highly inspired by this file in the Hazel GitHub repository by TheCherno:
//     - https://github.com/TheCherno/Hazel/blob/master/Hazel/src/Hazel/Core/PlatformDetection.h

#pragma once

#define CITADEL_PLATFORM_WINDOWS       0
#define CITADEL_PLATFORM_WIN64         0
#define CITADEL_PLATFORM_WIN32         0
#define CITADEL_PLATFORM_APPLE         0
#define CITADEL_PLATFORM_IOS_SIMULATOR 0
#define CITADEL_PLATFORM_IOS           0
#define CITADEL_PLATFORM_MACOS         0
#define CITADEL_PLATFORM_UNKNOWN_APPLE 0
#define CITADEL_PLATFORM_ANDROID       0
#define CITADEL_PLATFORM_LINUX         0
#define CITADEL_PLATFORM_UNKNOWN       0

#define CITADEL_PLATFORM_WIN64_NAME         "Win64"
#define CITADEL_PLATFORM_WIN32_NAME         "Win32"
#define CITADEL_PLATFORM_IOS_SIMULATOR_NAME "iOSSimulator"
#define CITADEL_PLATFORM_IOS_NAME           "iOS"
#define CITADEL_PLATFORM_MACOS_NAME         "macOS"
#define CITADEL_PLATFORM_UNKNOWN_APPLE_NAME "Apple?"
#define CITADEL_PLATFORM_ANDROID_NAME       "Android"
#define CITADEL_PLATFORM_LINUX_NAME         "Linux"
#define CITADEL_PLATFORM_UNKNOWN_NAME       "Unknown"

#ifdef _WIN32
	#undef CITADEL_PLATFORM_WINDOWS
	#define CITADEL_PLATFORM_WINDOWS 1

	#ifdef _WIN64
		#undef CITADEL_PLATFORM_WIN64
		#define CITADEL_PLATFORM_WIN64 1
		#define CITADEL_PLATFORM_NAME CITADEL_PLATFORM_WIN64_NAME
	#else
		#undef CITADEL_PLATFORM_WIN32
		#define CITADEL_PLATFORM_WIN32 1
		#define CITADEL_PLATFORM_NAME CITADEL_PLATFORM_WIN32_NAME
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>

	#undef CITADEL_PLATFORM_APPLE
	#define CITADEL_PLATFORM_APPLE 1

	#if defined(TARGET_IPHONE_SIMULATOR) && TARGET_IPHONE_SIMULATOR
		#undef CITADEL_PLATFORM_IOS_SIMULATOR
		#define CITADEL_PLATFORM_IOS_SIMULATOR 1
		#define CITADEL_PLATFORM_NAME CITADEL_PLATFORM_IOS_SIMULATOR_NAME
	#elif defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
		#undef CITADEL_PLATFORM_IOS
		#define CITADEL_PLATFORM_IOS 1
		#define CITADEL_PLATFORM_NAME CITADEL_PLATFORM_IOS_NAME
	#elif defined(TARGET_OS_MAC) && TARGET_OS_MAC
		#undef CITADEL_PLATFORM_MACOS
		#define CITADEL_PLATFORM_MACOS 1
		#define CITADEL_PLATFORM_NAME CITADEL_PLATFORM_MACOS_NAME
	#else
		#undef CITADEL_PLATFORM_UNKNOWN_APPLE
		#define CITADEL_PLATFORM_UNKNOWN_APPLE 1
		#define CITADEL_PLATFORM_NAME CITADEL_PLATFORM_UNKNOWN_APPLE_NAME
	#endif
#elif defined(__ANDROID__)
	#undef CITADEL_PLATFORM_ANDROID
	#define CITADEL_PLATFORM_ANDROID 1
	#define CITADEL_PLATFORM_NAME CITADEL_PLATFORM_ANDROID_NAME
#elif defined(__linux__)
	#undef CITADEL_PLATFORM_LINUX
	#define CITADEL_PLATFORM_LINUX 1
	#define CITADEL_PLATFORM_NAME CITADEL_PLATFORM_LINUX_NAME
#else
	#undef CITADEL_PLATFORM_UNKNOWN
	#define CITADEL_PLATFORM_UNKNOWN 1
	#define CITADEL_PLATFORM_NAME CITADEL_PLATFORM_UNKNOWN_NAME
#endif
