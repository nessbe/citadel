// File:        logger.h
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

#ifndef CITADEL_LOGGER_H
#define CITADEL_LOGGER_H

#include <string>

#include "citadel/attributes.h"
#include "citadel/export.h"

#include "citadel/logging/log_level.h"
#include "citadel/logging/log_message.h"

namespace Citadel
{
	class Logger
	{
	public:
		Logger(const std::string& configuration)
			: configuration_(configuration), min_level_(LogLevel::Debug) { }

		Logger(const std::string& configuration, LogLevel level)
			: configuration_(configuration), min_level_(level) { }

		~Logger() = default;

		CITADEL_API CITADEL_GETTER const std::string& get_configuration() const noexcept;

		CITADEL_API CITADEL_GETTER LogLevel get_level() const noexcept;
		CITADEL_API CITADEL_SETTER void set_level(LogLevel level) noexcept;

		CITADEL_API CITADEL_GETTER bool is_level_valid(LogLevel level) const noexcept;

		CITADEL_API void log(const LogMessage& message);

		CITADEL_API CITADEL_INLINE void log_debug(const std::string& message);
		CITADEL_API CITADEL_INLINE void log_trace(const std::string& message);
		CITADEL_API CITADEL_INLINE void log_info(const std::string& message);
		CITADEL_API CITADEL_INLINE void log_warning(const std::string& message);
		CITADEL_API CITADEL_INLINE void log_error(const std::string& message);
		CITADEL_API CITADEL_INLINE void log_critical(const std::string& message);

	private:
		std::string configuration_;
		LogLevel min_level_;

	private:
		CITADEL_API std::string format_message(const LogMessage& message) const;
		CITADEL_API void log_raw(const std::string& message);
	};
}

#endif
