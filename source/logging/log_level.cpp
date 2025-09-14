// File:        log_level.cpp
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
#include "citadel/logging/log_level.h"

namespace citadel::detail
{
	std::unordered_map<log_level, std::string> log_level_to_string_map = {
		{ log_level::debug, "DEBUG" },
		{ log_level::trace,   "TRACE" },
		{ log_level::info,    "INFO" },
		{ log_level::warning, "WARNING" },
		{ log_level::error,   "ERROR" },
		{ log_level::fatal,   "FATAL" },
		{ log_level::off,     "OFF" },
	};
}

namespace citadel
{
	constexpr log_level_t citadel::log_level_to_value(log_level level) noexcept
	{
		return static_cast<log_level_t>(level);
	}

	std::string log_level_to_string(log_level level)
	{
		if (citadel::detail::log_level_to_string_map.find(level) != citadel::detail::log_level_to_string_map.end())
		{
			return citadel::detail::log_level_to_string_map.at(level);
		}

		return "UNKNOWN";
	}
}
