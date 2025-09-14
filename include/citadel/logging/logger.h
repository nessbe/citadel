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

#include <string>

#include "citadel/attributes.h"
#include "citadel/export.h"

#include "citadel/logging/log_level.h"

namespace citadel
{
	class logger
	{
	public:
		logger(const std::string& name)
			: name_(name), min_level_(log_level::debug) { }

		logger(const std::string& name, log_level min_level)
			: name_(name), min_level_(min_level) { }

		~logger() = default;

		CITADEL_API CITADEL_GETTER bool is_level_valid(log_level level) const noexcept;

		CITADEL_API void log(const std::string& message, log_level level);

		CITADEL_API CITADEL_INLINE void log_debug(const std::string& message);
		CITADEL_API CITADEL_INLINE void log_trace(const std::string& message);
		CITADEL_API CITADEL_INLINE void log_info(const std::string& message);
		CITADEL_API CITADEL_INLINE void log_warning(const std::string& message);
		CITADEL_API CITADEL_INLINE void log_error(const std::string& message);
		CITADEL_API CITADEL_INLINE void log_fatal(const std::string& message);

		CITADEL_API CITADEL_GETTER const std::string& get_name() const noexcept;

		CITADEL_API CITADEL_GETTER log_level get_min_level() const noexcept;
		CITADEL_API CITADEL_SETTER void set_min_level(log_level value) noexcept;

	private:
		std::string name_;
		log_level min_level_;

	private:
		CITADEL_API CITADEL_NODISCARD std::string format_message(const std::string& message, log_level level) const;
	};
}
