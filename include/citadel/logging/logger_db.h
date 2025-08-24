// File:        logger_db.h
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

#ifndef CITADEL_LOGGER_DB_H
#define CITADEL_LOGGER_DB_H

#include <optional>
#include <string>
#include <unordered_map>

#include "citadel/assert.h"
#include "citadel/attributes.h"
#include "citadel/export.h"

#include "citadel/logging/logger.h"

#include "citadel/memory/reference.h"


namespace Citadel
{
	class LoggerDB
	{
	public:
		LoggerDB() = delete;
		~LoggerDB() = delete;

		LoggerDB(const LoggerDB&) = delete;
		LoggerDB& operator=(const LoggerDB&) = delete;

		CITADEL_API CITADEL_GETTER static bool has_logger(const std::string& configuration);

		CITADEL_API static bool add_logger(Reference<Logger> logger);

		CITADEL_API std::optional<Reference<Logger>> static create_logger(const std::string& configuration);

		CITADEL_API static bool remove_logger(const std::string& configuration);

		CITADEL_API CITADEL_GETTER static std::optional<Reference<Logger>> get_logger(const std::string& configuration);

		CITADEL_API CITADEL_GETTER static Reference<Logger> get_or_create_logger(const std::string& configuration);

	private:
		static std::unordered_map<std::string, Reference<Logger>> loggers_;
	};
}

#endif
