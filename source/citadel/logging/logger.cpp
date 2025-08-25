// File:        logger.cpp
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

#include "citadelpch.h"
#include "citadel/logging/logger.h"

namespace Citadel
{
	const std::string& Logger::get_configuration() const noexcept
	{
		return configuration_;
	}

	LogLevel Logger::get_level() const noexcept
	{
		return LogLevel();
	}

	void Logger::set_level(LogLevel level) noexcept
	{
		min_level_ = level;
	}

	bool Logger::is_level_valid(LogLevel level) const noexcept
	{
		return level >= min_level_;
	}

	Reference<Sink> Logger::back_sink() const
	{
		return sinks_.back_sink();
	}

	void Logger::push_sink(Reference<Sink> sink)
	{
		sinks_.push_sink(sink);
	}

	Reference<Sink> Logger::pop_sink()
	{
		return sinks_.pop_sink();
	}

	void Logger::log_raw(const std::string& message)
	{
		sinks_.propagate(message);
	}
}
