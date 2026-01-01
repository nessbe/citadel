// File:       json_type.cpp
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
#include "citadel/formats/json/json_type.hpp"

namespace citadel {
	std::string json_type_to_string(json_type value) {
		switch (value) {
		case json_type::null:
			return "null";

		case json_type::boolean:
			return "boolean";

		case json_type::number:
			return "number";

		case json_type::string:
			return "string";

		case json_type::array:
			return "array";

		case json_type::object:
			return "object";

		default:
			CITADEL_PANIC("Unknown JSON type");
			return "unknown";
		}
	}
}
