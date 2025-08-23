// File:        assert.h
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

#ifndef CITADEL_ASSERT_H
#define CITADEL_ASSERT_H

#include <csignal>
#include <cstdio>
#include <iostream>

#include "citadel/architectures.h"
#include "citadel/compilers.h"
#include "citadel/platforms.h"

#ifdef CITADEL_DEBUG
	#if CITADEL_COMPILER_MSVC
		#define CITADEL_DEBUGBREAK() __debugbreak()
	#elif CITADEL_COMPILER_CLANG || CITADEL_COMPILER_GCC
		#if CITADEL_ARCHITECTURE_X86_32 || CITADEL_ARCHITECTURE_X86_64
			#define CITADEL_DEBUGBREAK() __asm__ volatile("int3")
		#elif CITADEL_ARCHITECTURE_ARM_64
			#define CITADEL_DEBUGBREAK() __asm__ volatile("brk #0")
		#elif CITADEL_ARCHITECTURE_ARM_32
			#define CITADEL_DEBUGBREAK() __asm__ volatile("bkpt #0")
		#else
			#define CITADEL_DEBUGBREAK() raise(SIGTRAP)
		#endif
	#else
		#define CITADEL_DEBUGBREAK() raise(SIGTRAP)
	#endif
#endif

#ifdef CITADEL_ENABLE_ASSERTS
	#define CITADEL_ASSERT(condition, message) \
		do \
		{ \
			if (!(condition)) \
			{ \
				std::cerr << "Assertion failed: (" << #condition << ") " \
					<< message << std::endl; \
				CITADEL_DEBUGBREAK(); \
			} \
		} \
		while(0);
#else
	#define CITADEL_ASSERT(condition, message)
#endif


#define CITADEL_TRY_OR_ASSERT(scope, message) \
	try scope \
	catch (...) \
	{ \
		CITADEL_ASSERT(false, message); \
	}

#endif
