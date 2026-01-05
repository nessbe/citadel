// File:       stringifiable.inl
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

namespace citadel {
	std::string stringifiable<std::string>::to_string(const std::string& value) {
		return value;
	}

	std::string stringifiable<bool>::to_string(bool value) {
		return value ? "true" : "false";
	}

	template <typename T>
	std::string stringifiable<T, std::enable_if_t<std::is_arithmetic_v<T>>>::to_string(T value) {
		return std::to_string(value);
	}
}
