// File:       json_type_of.hpp
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

#include "citadel/formats/json/json_type.hpp"
#include "citadel/formats/json/json_value.hpp"

namespace citadel {
	template <typename T>
	struct json_type_of;

	template <typename T>
	inline constexpr json_type json_type_of_v = json_type_of<T>::value;

	template <>
	struct json_type_of<json_null> {
		static constexpr json_type value = json_type::null;
	};

	template <>
	struct json_type_of<json_boolean> {
		static constexpr json_type value = json_type::boolean;
	};

	template <>
	struct json_type_of<json_number> {
		static constexpr json_type value = json_type::number;
	};

	template <>
	struct json_type_of<json_string> {
		static constexpr json_type value = json_type::string;
	};

	template <>
	struct json_type_of<json_array> {
		static constexpr json_type value = json_type::array;
	};

	template <>
	struct json_type_of<json_object> {
		static constexpr json_type value = json_type::object;
	};
}
