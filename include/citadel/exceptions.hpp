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

#include "citadel/debug/exceptions/invalid_argument_error.hpp"
#include "citadel/debug/exceptions/invalid_member_error.hpp"
#include "citadel/debug/exceptions/invalid_operation_error.hpp"
#include "citadel/debug/exceptions/invalid_result_error.hpp"
#include "citadel/debug/exceptions/null_reference_error.hpp"

#include "citadel/logging/log_macros.hpp"

#include "citadel/utils/format/formatter.hpp"

#ifndef CITADEL_NOTHROW
	#define CITADEL_THROW(exception, ...) throw exception(__VA_ARGS__)
#else
	#define CITADEL_THROW(exception, ...) CITADEL_LOG_ERROR(__VA_ARGS__)
#endif

#define CITADEL_THROW_IF(condition, exception, ...) do { if (unlikely(static_cast<bool>(condition))) { CITADEL_THROW(exception, __VA_ARGS__); } } while (0)
#define CITADEL_THROW_IF_NULL(value, exception, ...) CITADEL_THROW_IF(value == nullptr, exception, __VA_ARGS__)

#define CITADEL_THROW_IF_TRUE(value, exception, message, ...) CITADEL_THROW_IF(value == true, exception, message, __VA_ARGS__)
#define CITADEL_THROW_IF_FALSE(value, exception, message, ...) CITADEL_THROW_IF(value == false, exception, message, __VA_ARGS__)

#define CITADEL_CHECK_ARGUMENT(argument, condition)                      CITADEL_THROW_IF(condition, ::citadel::invalid_argument_error, ::citadel::formatter::format("Argument '{0}' is invalid ({1})", #argument, #condition))
#define CITADEL_CHECK_MEMBER(member, condition)                          CITADEL_THROW_IF(condition, ::citadel::invalid_member_error, ::citadel::formatter::format("Member '{0}' is invalid ({1})", #member, #condition))
#define CITADEL_CHECK_OPERATION(operation, condition)                    CITADEL_THROW_IF(condition, ::citadel::invalid_operation_error, ::citadel::formatter::format("Operation '{0}' is invalid ({1})", operation, #condition))

#define CITADEL_CHECK_RESULT(result, condition)                           CITADEL_THROW_IF(condition, ::citadel::invalid_result_error, ::citadel::formatter::format("Result '{0}' is invalid ({1})", #result, #condition))
#define CITADEL_CHECK_FUNCTION_RESULT_STORED(result, function, condition) do { result = function; if (unlikely(static_cast<bool>(condition))) { CITADEL_THROW(::citadel::invalid_result_error, "Function '{0}' result is invalid ({1})", #function, #condition); } } while (0)
#define CITADEL_CHECK_FUNCTION_RESULT(function, condition)                CITADEL_CHECK_FUNCTION_RESULT_STORED(auto result, function, condition)

#define CITADEL_CHECK_NULL_REFERENCE(value)                               CITADEL_THROW_IF_NULL(value, ::citadel::null_reference_error, ::citadel::formatter::format("'{0}' is null", #value))
