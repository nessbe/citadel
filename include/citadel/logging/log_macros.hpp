// File:       log_macros.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#include "citadel/logging/log_level.hpp"
#include "citadel/logging/loggers.hpp"

#ifndef CITADEL_THIS_LOGGER_NAME
	#define CITADEL_THIS_LOGGER_NAME "CITADEL"
#endif

#define CITADEL_LOG(message, level, ...)  ::citadel::loggers::log(CITADEL_THIS_LOGGER_NAME, message, level, ##__VA_ARGS__)
#define CITADEL_LOG_DEBUG(message, ...)   ::citadel::loggers::log_debug(CITADEL_THIS_LOGGER_NAME, message, ##__VA_ARGS__)
#define CITADEL_LOG_TRACE(message, ...)   ::citadel::loggers::log_trace(CITADEL_THIS_LOGGER_NAME, message, ##__VA_ARGS__)
#define CITADEL_LOG_INFO(message, ...)    ::citadel::loggers::log_info(CITADEL_THIS_LOGGER_NAME, message, ##__VA_ARGS__)
#define CITADEL_LOG_WARNING(message, ...) ::citadel::loggers::log_warning(CITADEL_THIS_LOGGER_NAME, message, ##__VA_ARGS__)
#define CITADEL_LOG_ERROR(message, ...)   ::citadel::loggers::log_error(CITADEL_THIS_LOGGER_NAME, message, ##__VA_ARGS__)
#define CITADEL_LOG_FATAL(message, ...)   ::citadel::loggers::log_fatal(CITADEL_THIS_LOGGER_NAME, message, ##__VA_ARGS__)
