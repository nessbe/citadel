// File:       assertion_error.cpp
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

#include "citadel/pch.hpp"
#include "citadel/debug/exceptions/assertion_error.hpp"

namespace citadel {
	assertion_error::assertion_error(const char* message)
		: std::runtime_error(message) { }

	assertion_error::assertion_error(const std::string& message)
		: std::runtime_error(message) { }
}
