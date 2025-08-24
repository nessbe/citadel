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

#ifndef CITADEL_LOG_LEVEL_H
#define CITADEL_LOG_LEVEL_H

#include <string>

namespace Citadel
{
	using LogLevel_t = int;

	enum class LogLevel : LogLevel_t
	{
		Debug = 0,
		Trace = 1,
		Info = 2,
		Warning = 3,
		Error = 4,
		Critical = 5,
	};

	inline std::string to_string(LogLevel level)
	{
		switch (level)
		{
		case LogLevel::Debug:
			return "DEBUG";

		case LogLevel::Trace:
			return "TRACE";

		case LogLevel::Info:
			return "INFO";

		case LogLevel::Warning:
			return "WARNING";

		case LogLevel::Error:
			return "ERROR";

		case LogLevel::Critical:
			return "CRITICAL";

		default:
			return "UNKNOWN";
		}
	}

	inline std::ostream& operator<<(std::ostream& out, LogLevel level)
	{
		out << to_string(level);
		return out;
	}
}

#endif
