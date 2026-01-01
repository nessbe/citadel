// File:       json_types.hpp
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

#include <map>
#include <string>
#include <variant>

#include "citadel/memory/reference.hpp"

namespace citadel {
	class json_value;
	using json_value_reference = reference<json_value>;

	using json_null = std::nullptr_t;
	using json_boolean = bool;
	using json_number = double;
	using json_string = std::string;
	using json_array = std::vector<json_value_reference>;
	using json_object = std::map<std::string, json_value_reference>;
}
