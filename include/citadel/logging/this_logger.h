// File:        this_logger.h
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

#include "citadel/attributes.h"
#include "citadel/export.h"

#include "citadel/logging/logger.h"

#ifndef CITADEL_THIS_LOGGER_NAME
	#define CITADEL_THIS_LOGGER_NAME "CORE"
#endif

namespace citadel::detail
{
	logger this_logger(CITADEL_THIS_LOGGER_NAME);
}

namespace citadel::this_logger
{
	CITADEL_API CITADEL_GETTER logger& get() noexcept;

	CITADEL_API void log(const std::string& message);

	CITADEL_API CITADEL_GETTER const std::string& get_name() noexcept;
}

#include "citadel/logging/this_logger.inl"
