// File:       json_value.inl
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

#include "citadel/formats/json/json_type_of.hpp"

#include "citadel/formats/json/exceptions/json_type_error.hpp"

namespace citadel {
	template <typename T>
	bool json_value::is() const noexcept {
		return std::holds_alternative<T>(value_);
	}

	template <typename T>
	T& json_value::as() {
		if (!is<T>()) {
			throw json_type_error(
				type(),
				json_type_of_v<T>
			);
		}
		return std::get<T>(value_);
	}

	template <typename T>
	const T& json_value::as() const {
		if (!is<T>()) {
			throw json_type_error(
				type(),
				json_type_of_v<T>
			);
		}
		return std::get<T>(value_);
	}
}
