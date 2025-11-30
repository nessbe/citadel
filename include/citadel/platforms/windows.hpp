// File:       windows.hpp
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

#include <string>

#include "citadel/platforms.hpp"

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
