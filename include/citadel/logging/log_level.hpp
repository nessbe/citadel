// File:       log_level.hpp
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

#include <cinttypes>
#include <sstream>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	enum class log_level : std::uint8_t {
		debug = 0,
		trace,
		info,
		warning,
		error,
		fatal,
		count,
		off,
	};

	exported extern std::array<log_level, static_cast<std::size_t>(log_level::count)> log_levels;

	nodisc exported std::string log_level_to_string(log_level value);

	exported std::ostream& operator<<(std::ostream& out, log_level value);
}
