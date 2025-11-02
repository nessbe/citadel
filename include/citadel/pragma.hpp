// File:       pragma.hpp
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
	#define CITADEL_PRAGMA(x) __pragma(x)
#elif CITADEL_COMPILER_GCC ||CITADEL_COMPILER_CLANG
	#define CITADEL_PRAGMA(x) _Pragma(#x)
#else
	#define CITADEL_PRAGMA(x)
#endif
