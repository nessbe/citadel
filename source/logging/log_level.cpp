// File:       log_level.cpp
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

#include "citadel/pch.hpp"
#include "citadel/logging/log_level.hpp"

namespace citadel {
	std::array<log_level, static_cast<std::size_t>(log_level::count)> log_levels = {
		log_level::debug,
		log_level::trace,
		log_level::info,
		log_level::warning,
		log_level::error,
		log_level::fatal,
	};

	std::string to_string(log_level value) {
		switch (value) {
		case log_level::debug:
			return "DEBUG";

		case log_level::trace:
			return "TRACE";

		case log_level::info:
			return "INFO";

		case log_level::warning:
			return "WARNING";

		case log_level::error:
			return "ERROR";

		case log_level::fatal:
			return "FATAL";

		case log_level::off:
			return "OFF";

		case log_level::count:
		default:
			return "UNKNOWN";
		}
	}

	std::ostream& operator<<(std::ostream& out, log_level value) {
		return out << to_string(value);
	}
}
