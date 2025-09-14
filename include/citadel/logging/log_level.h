// File:        log_level.h
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

#include <cinttypes>
#include <string>
#include <unordered_map>

#include "citadel/attributes.h"
#include "citadel/export.h"

namespace citadel
{
	using log_level_t = std::uint8_t;

	enum class log_level : log_level_t
	{
		debug =   0,
		trace =   1,
		info =    2,
		warning = 3,
		error =   4,
		fatal =   5,
		off =     6,
	};

}

namespace citadel::detail
{
	extern std::unordered_map<log_level, std::string> log_level_to_string_map;
}

namespace citadel
{
	CITADEL_API CITADEL_GETTER constexpr log_level_t log_level_to_value(log_level level) noexcept;
	CITADEL_API CITADEL_NODISCARD std::string log_level_to_string(log_level level);
}
