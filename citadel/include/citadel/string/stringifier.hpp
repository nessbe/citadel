// File:       stringifier.hpp
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

#include <sstream>
#include <string>
#include <type_traits>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	template <typename, typename = void>
	struct has_to_string_method : std::false_type { };

	template <typename T>
	struct has_to_string_method<T, std::void_t<decltype(std::declval<T>().to_string())>> : std::true_type { };

	template <typename T>
	inline constexpr bool has_to_string_method_v = has_to_string_method<T>::value;

	template <typename, typename = void>
	struct has_ostream_operator : std::false_type { };

	template <typename T>
	struct has_ostream_operator<T, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T>())>> : std::true_type { };

	template <typename T>
	inline constexpr bool has_ostream_operator_v = has_ostream_operator<T>::value;

	class api stringifier {
	public:
		template <typename T>
		stringifier(const T& value);

		template <typename T>
		stringifier(T&& value);

		~stringifier() = default;

		nodisc void reset();

		template <typename T>
		nodisc void reset(const T& value);

		template <typename T>
		nodisc void reset(T&& value);

		nodisc const std::string& stringify() const noexcept;

		template <typename T>
		nodisc static std::string stringify(T&& value);

	private:
		std::string result_;
	};
}

#include "citadel/string/stringifier.inl"
