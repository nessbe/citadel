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

#include "citadel/pch.h"
#include "citadel/logging/logger.h"

namespace citadel
{
	bool logger::is_level_valid(log_level level) const noexcept
	{
		return level >= min_level_;
	}

	void logger::log(const std::string& message, log_level level)
	{
		if (!is_level_valid(level))
		{
			return;
		}

		std::string formatted_message = format_message(message, level);
		std::cout << formatted_message << std::endl;
	}

	void logger::log_debug(const std::string& message)
	{
		log(message, log_level::debug);
	}

	void logger::log_trace(const std::string& message)
	{
		log(message, log_level::trace);
	}

	void logger::log_info(const std::string& message)
	{
		log(message, log_level::info);
	}

	void logger::log_warning(const std::string& message)
	{
		log(message, log_level::warning);
	}

	void logger::log_error(const std::string& message)
	{
		log(message, log_level::error);
	}

	void logger::log_fatal(const std::string& message)
	{
		log(message, log_level::fatal);
	}

	const std::string& logger::get_name() const noexcept
	{
		return name_;
	}

	log_level logger::get_min_level() const noexcept
	{
		return min_level_;
	}

	void logger::set_min_level(log_level value) noexcept
	{
		min_level_ = value;
	}

	std::string logger::format_message(const std::string& message, log_level level) const
	{
		std::ostringstream oss;
		oss << '[' << name_ << "] ";
		oss << '[' << log_level_to_string(level) << "] ";
		oss << message;
		return oss.str();
	}
}
