// File:       json_type_error.cpp
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
#include "citadel/formats/json/exceptions/json_type_error.hpp"

namespace citadel {
	json_type_error::json_type_error(json_type expected, json_type actual)
		: json_exception(formatter::format(
			"JSON type error: expected '{0}', got '{1}'",
			json_type_to_string(expected),
			json_type_to_string(actual)
		))
	{ }
}
