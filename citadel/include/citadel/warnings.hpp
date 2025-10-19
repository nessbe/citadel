// File:       warnings.hpp
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

#include "citadel/compilers.hpp"

#if CITADEL_COMPILER_MSVC
	#pragma warning(disable : 4251) // class needs to have dll-interface to be used by clients of class
	#pragma warning(disable : 4625) // copy constructor was implicitly deleted
	#pragma warning(disable : 4626) // assignment operator was implicitly deleted
	#pragma warning(disable : 4820) // padding added after data member
	#pragma warning(disable : 5267) // implicit copy assignment operator deprecated due to user-defined copy constructor/assignment
#elif CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wno-padded"
	#pragma GCC diagnostic ignored "-Wno-unused-parameter"
#endif
