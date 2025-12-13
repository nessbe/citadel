// File:       exceptions.hpp
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

#include "citadel/attributes.hpp"

#include "citadel/logging/log_macros.hpp"

#include "citadel/utils/format/formatter.hpp"

#ifndef CITADEL_NOTHROW
	#define CITADEL_THROW(exception, message, ...) throw exception(::citadel::formatter::format(message, __VA_ARGS__))
#else
	#define CITADEL_THROW(exception, message, ...) CITADEL_LOG_ERROR(message, __VA_ARGS__)
#endif

#define CITADEL_THROW_IF(condition, exception, message, ...) do { if (unlikely(static_cast<bool>(condition))) { CITADEL_THROW(exception, message, __VA_ARGS__); } } while (0)
#define CITADEL_THROW_IF_NULL(value, exception, message, ...) CITADEL_THROW_IF(value == nullptr, exception, message, __VA_ARGS__)

#define CITADEL_THROW_IF_TRUE(value, exception, message, ...) CITADEL_THROW_IF(value == true, exception, message, __VA_ARGS__)
#define CITADEL_THROW_IF_FALSE(value, exception, message, ...) CITADEL_THROW_IF(value == false, exception, message, __VA_ARGS__)
