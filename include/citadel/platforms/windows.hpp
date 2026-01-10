// File:       windows.hpp
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

#include <string>

#include "citadel/platforms.hpp"

#include "citadel/debug/assert.hpp"

#include "citadel/logging/log_macros.hpp"

#if CITADEL_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		#define NOMINMAX 1
	#endif

	#include <Windows.h>
	#include <Windowsx.h>
	#include <sal.h>

	#undef near
	#undef far
#endif

#define CITADEL_WIN32_LOG_LAST_ERROR()                                        \
	do {                                                                  \
		const DWORD error = GetLastError();                           \
		if (error != NO_ERROR) {                                      \
			CITADEL_LOG_FATAL("Detected Win32 error {0}", error); \
		}                                                             \
	} while (0)

#define CITADEL_WIN32_CALL(function)                                                     \
	do {                                                                             \
		if (!(function)) {                                                       \
			CITADEL_WIN32_LOG_LAST_ERROR();                                  \
			CITADEL_PANIC("Failed to call Win32 function '{0}'", #function); \
		}                                                                        \
	} while (0)                                                                      \

#ifdef UNICODE
	#define CITADEL_UNIVERSAL_STRING(string) L##string
#else
	#define CITADEL_UNIVERSAL_STRING(string) string
#endif

namespace citadel {
#ifdef UNICODE
	using universal_char = wchar_t;
#else
	using universal_char = char;
#endif

	using universal_string = std::basic_string<universal_char>;
}
