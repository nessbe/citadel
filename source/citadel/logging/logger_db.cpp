// File:        logger_db.cpp
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
#include "citadel/logging/logger_db.h"

namespace Citadel
{
	bool LoggerDB::has_logger(const std::string& configuration)
	{
		return loggers_.find(configuration) != loggers_.end();
	}

	std::optional<Reference<Logger>> Citadel::LoggerDB::create_logger(const std::string& configuration)
	{
		if (has_logger(configuration))
		{
			return std::nullopt;
		}

		Reference<Logger> logger = make_referenced<Logger>(configuration);

		add_logger(logger);

		return logger;
	}

	bool LoggerDB::remove_logger(const std::string& configuration)
	{
		if (has_logger(configuration))
		{
			loggers_.erase(configuration);
			return true;
		}

		return false;
	}

	bool LoggerDB::add_logger(Reference<Logger> logger)
	{
		if (!logger)
		{
			return false;
		}

		const std::string& configuration = logger->get_configuration();

		if (has_logger(configuration))
		{
			return false;
		}

		loggers_[configuration] = logger;
		return true;
	}

	std::optional<Reference<Logger>> LoggerDB::get_logger(const std::string& configuration)
	{
		if (has_logger(configuration))
		{
			return loggers_[configuration];
		}

		return std::nullopt;
	}

	Reference<Logger> LoggerDB::get_or_create_logger(const std::string& configuration)
	{
		if (has_logger(configuration))
		{
			return get_logger(configuration).value();
		}

		return create_logger(configuration).value();
	}

	std::unordered_map<std::string, Reference<Logger>> LoggerDB::loggers_;
}
