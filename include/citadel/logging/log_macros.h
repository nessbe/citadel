// File:        log_macros.h
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

#ifndef CITADEL_LOG_MACROS_H
#define CITADEL_LOG_MACROS_H

#include "citadel/logging/log_level.h"
#include "citadel/logging/log_message.h"
#include "citadel/logging/logger.h"
#include "citadel/logging/logger_db.h"

#include "citadel/memory/reference.h"

#ifndef CITADEL_LOG_CONFIGURATION
	#define CITADEL_LOG_CONFIGURATION "CORE"
#endif

#define CITADEL_GET_LOGGER() \
	Citadel::LoggerDB::get_or_create_logger(CITADEL_LOG_CONFIGURATION)

#define CITADEL_CREATE_LOG_MESSAGE(literal, level) \
	Citadel::make_referenced<Citadel::LogMessage>(literal, level)

#define CITADEL_LOG(message, level, ...) \
	CITADEL_GET_LOGGER()->log(CITADEL_CREATE_LOG_MESSAGE(message, level), ##__VA_ARGS__)

#define CITADEL_LOG_DEBUG(message, ...) \
	CITADEL_LOG(message, Citadel::LogLevel::Debug, ##__VA_ARGS__)

#define CITADEL_LOG_TRACE(message, ...) \
	CITADEL_LOG(message, Citadel::LogLevel::Trace, ##__VA_ARGS__)

#define CITADEL_LOG_INFO(message, ...) \
	CITADEL_LOG(message, Citadel::LogLevel::Info, ##__VA_ARGS__)

#define CITADEL_LOG_WARNING(message, ...) \
	CITADEL_LOG(message, Citadel::LogLevel::Warning, ##__VA_ARGS__)

#define CITADEL_LOG_ERROR(message, ...) \
	CITADEL_LOG(message, Citadel::LogLevel::Error, ##__VA_ARGS__)

#define CITADEL_LOG_CRITICAL(message, ...) \
	CITADEL_LOG(message, Citadel::LogLevel::Critical, ##__VA_ARGS__)

#endif
