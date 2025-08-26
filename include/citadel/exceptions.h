// File:        exceptions.h
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

#ifndef CITADEL_EXCEPTIONS_H
#define CITADEL_EXCEPTIONS_H

#include <stdexcept>
#include <string>

#include "citadel/format/formatter.h"

#include "citadel/logging/log_macros.h"

#ifdef CITADEL_ENABLE_EXCEPTIONS
	#define CITADEL_THROW(exception, message) \
		throw exception(message)
#else
	#define CITADEL_THROW(exception, message)
#endif

#define CITADEL_EXCEPT(condition, exception, message, ...) \
	do \
	{ \
		if (!(condition)) \
		{ \
			const std::string message_format = "Exception '{0}' thrown: ({1}) {2}"; \
			\
			Citadel::Formatter message_formatter(message_format); \
			Citadel::Formatter literal_formatter(message); \
			\
			std::string literal = literal_formatter.format(##__VA_ARGS__); \
			std::string msg = message_formatter.format(condition, literal); \
			\
			CITADEL_LOG_ERROR(message_format, condition, literal); \
			CITADEL_THROW(exception, msg); \
		} \
	} \
	while(0);

#define CITADEL_EXCEPT_RUNTIME_ERROR(condition, message, ...) \
	CITADEL_EXCEPT(condition, std::runtime_error, message, ##__VA_ARGS__)

#define CITADEL_EXCEPT_INVALID_ARGUMENT(condition, message, ...) \
	CITADEL_EXCEPT(condition, std::invalid_argument, message, ##__VA_ARGS__)

#define CITADEL_EXCEPT_OUT_OF_RANGE(condition, message, ...) \
	CITADEL_EXCEPT(condition, std::out_of_range, message, ##__VA_ARGS__)

#endif
