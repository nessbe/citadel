// File:        log_settings.h
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

#ifndef CITADEL_LOG_SETTINGS_H
#define CITADEL_LOG_SETTINGS_H

#include "citadel/export.h"

#include "citadel/format/formatter.h"

#include "citadel/logging/log_level.h"
#include "citadel/logging/log_message.h"

#include "citadel/memory/reference.h"

namespace Citadel
{
	struct LogSettings
	{
	public:
		LogLevel min_level;

		CITADEL_API bool is_level_valid(LogLevel level) const noexcept;

		CITADEL_API bool is_valid(Reference<LogMessage> message) const;
	};
}

#endif
