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

#include "citadel/logging/this_logger.hpp"

#ifndef CITADEL_THIS_LOGGER_NAME
	#define CITADEL_THIS_LOGGER_NAME "CITADEL"
#endif

#define CITADEL_THIS_LOGGER_CALL(function, ...) ::citadel::this_logger::set(CITADEL_THIS_LOGGER_NAME); ::citadel::this_logger::function(__VA_ARGS__)

#define CITADEL_LOG(message, level) CITADEL_THIS_LOGGER_CALL(log, message, level)
