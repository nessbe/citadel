// File:       invalid_argument_error.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#include <string>

#include "citadel/debug/exceptions/exception.hpp"

namespace citadel {
	class invalid_argument_error final : public exception {
	public:
		invalid_argument_error(const std::string& argument);
		invalid_argument_error(const std::string& argument, const std::string& condition);
	};
}
