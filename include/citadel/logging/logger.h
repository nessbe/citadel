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

namespace Citadel
{
	class Logger
	{
	public:
		Logger(const std::string& configuration)
			: configuration_(configuration) { }
		~Logger() = default;

		CITADEL_API CITADEL_GETTER const std::string& get_configuration() const noexcept;

		CITADEL_API void log(const std::string& message);

	private:
		std::string configuration_;

	private:
		CITADEL_API std::string format_message(const std::string& message) const;
		CITADEL_API void log_raw(const std::string& message);
	};
}

#endif
