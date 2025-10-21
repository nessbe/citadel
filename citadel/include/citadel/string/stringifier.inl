// File:       stringifier.inl
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// For more details, see the LICENSE file at the root of the project.

#pragma once

namespace citadel {
	template <typename T>
	stringifier::stringifier(const T& value)
		: result_(to_string(value)) { }

	template <typename T>
	stringifier::stringifier(T&& value)
		: result_(to_string(std::forward<T>(value))) { }

	template <typename T>
	void stringifier::reset(const T& value) {
		result_ = to_string(value);
	}

	template <typename T>
	void stringifier::reset(T&& value) {
		result_ = to_string(std::forward<T>(value));
	}

	template <typename T>
	std::string stringifier::stringify(T&& value) {
		using decay = std::decay_t<T>;
		decay decayed_value = std::forward<T>(value);

		if constexpr (std::is_same_v<decay, std::string>) {
			return decayed_value;
		} else if constexpr (std::is_same_v<decay, bool>) {
			return decayed_value ? "true" : "false";
		} else if constexpr (has_to_string_method_v<decay>) {
			return decayed_value.to_string();
		} else if constexpr (has_ostream_operator_v<decay>) {
			std::ostringstream out;
			out << decayed_value;
			return out.str();
		}

		return "[unstringifiable]";
	}
}
