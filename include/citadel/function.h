// File:        function.h
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

#include "citadel/compilers.h"

#define CITADEL_FUNCTION_NAME __func__

#if CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
	#define CITADEL_FUNCTION_SIGNATURE __PRETTY_FUNCTION__
#elif CITADEL_COMPILER_MSVC
	#define CITADEL_FUNCTION_SIGNATURE __FUNCSIG__
#else
	#define CITADEL_FUNCTION_SIGNATURE __func__
#endif

#define CITADEL_FUNCTION_CONTEXT __FILE__ << ':' << __LINE__ << " in " << CITADEL_FUNCTION_SIGNATURE
