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

#include <iostream>
#include <stdexcept>

#ifdef CITADEL_ENABLE_THROWING
	#define CITADEL_THROW(exception, ...) \
		throw exception(##__VA_ARGS__)
#else
	#define CITADEL_THROW(exception, ...)
#endif

#ifdef CITADEL_ENABLE_EXCEPTIONS
	#define CITADEL_EXCEPT(condition, message, exception, ...) \
		do \
		{ \
			if (!(condition)) \
			{ \
				std::cerr << "Exception thrown (" << #condition << "): " \
					<< message << std::endl; \
				CITADEL_THROW(exception, message, ##__VA_ARGS__); \
			} \
		} while(0)
#else
	#define CITADEL_EXCEPT(condition, message, exception, ...)
#endif

#define CITADEL_EXCEPT_RUNTIME_ERROR(condition, message, ...) \
	CITADEL_EXCEPT(condition, message, std::runtime_error, ##__VA_ARGS__)

#define CITADEL_EXCEPT_OUT_OF_RANGE(condition, message, ...) \
	CITADEL_EXCEPT(condition, message, std::out_of_range, ##__VA_ARGS__)

#endif
