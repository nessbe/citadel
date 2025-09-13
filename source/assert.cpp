// File:        assert.cpp
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

#include "citadel/pch.h"
#include "citadel/assert.h"

#if !CITADEL_PLATFORM_WINDOWS && (CITADEL_COMPILER_GCC || CITADEL_COMPILER_CLANG)
	#include <signal.h>
#endif

namespace citadel
{
	void debugbreak()
	{
#ifdef CITADEL_ENABLE_DEBUGBREAK
	#if CITADEL_PLATFORM_WINDOWS
		__debugbreak();
	#elif defined(__GLUC__) || defined(__clang__)
		raise(SIGBREAK)
	#endif
#endif
	}

	void assert(bool condition, const std::string& condition_string, const std::string& message)
	{
#ifdef CITADEL_ENABLE_ASSERTIONS
		if (!(condition))
		{
			std::cerr << "Assertion failed (" << condition_string << "): " << message << std::endl;
			debugbreak();
		}
#endif
	}

	void assert(bool condition, const std::string& message)
	{
#ifdef CITADEL_ENABLE_ASSERTIONS
		if (!(condition))
		{
			std::cerr << "Assertion failed: " << message << std::endl;
			debugbreak();
		}
#endif
	}
}
