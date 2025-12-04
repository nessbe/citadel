// File:       exit_code.hpp
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

#include <cinttypes>
#include <cstdlib>

#include "citadel/utility.hpp"

namespace citadel {
	enum class exit_code : std::uint8_t {
		success = EXIT_SUCCESS,
		failure = EXIT_FAILURE,
	};

	CITADEL_BITWISE_OPERATORS_WRAPPER(exit_code)
}
