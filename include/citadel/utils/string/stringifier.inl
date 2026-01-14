// File:       stringifier.inl
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

#include <sstream>

#include "citadel/warnings.hpp"

#include "citadel/utils/enumerations/enumeration_underlying.hpp"

#include "citadel/utils/string/type_traits/adl_to_string.hpp"
#include "citadel/utils/string/type_traits/has_free_to_string.hpp"
#include "citadel/utils/string/type_traits/has_member_to_string.hpp"
#include "citadel/utils/string/type_traits/has_ostream_operator.hpp"
#include "citadel/utils/string/type_traits/has_std_to_string.hpp"
#include "citadel/utils/string/type_traits/is_stringifiable.hpp"

#include "citadel/utils/type_traits/dependent_false.hpp"

namespace citadel {

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_UNREACHABLE_CODE)

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_SPECTRE)

	template <typename T, std::size_t N>
	std::string stringifier::stringify(const T(&array)[N]) {
		if constexpr (std::is_same_v<T, char>) {
			return std::string(array);
		}

		std::ostringstream oss;
		oss << '[';

		for (std::size_t i = 0; i < N; i++) {
			oss << stringify(array[i]);

			if (i + 1 < N) {
				oss << ", ";
			}
		}

		oss << "]";
		return oss.str();
	}

CITADEL_WARNING_IGNORE_POP

	template <typename T>
	std::string stringifier::stringify(const T& value) {
		using decay_type = std::decay_t<T>;

		if constexpr (is_stringifiable_v<decay_type>) {
			return stringifiable<decay_type>::to_string(value);
		}
		else if constexpr (has_member_to_string_v<decay_type>) {
			return value.to_string();
		}
		else if constexpr (has_free_to_string_v<decay_type>) {
			return detail::adl_to_string(value);
		}
		else if constexpr (has_std_to_string_v<decay_type>) {
			return std::to_string(value);
		}
		else if constexpr (has_ostream_operator_v<decay_type>) {
			std::ostringstream oss;
			oss << value;
			return oss.str();
		}
		else if constexpr (std::is_enum_v<decay_type>) {
			return stringify(detail::enumeration_to_underlying(value));
		}
		else {
			static_assert(detail::dependent_false_v<decay_type>, "Type T is not stringifiable");
			return "<null>";
		}
	}

CITADEL_WARNING_IGNORE_POP

	template <typename T>
	stringifier::stringifier(const T& value)
		: value_(stringify<T>(value)) { }

	template <typename T>
	void stringifier::reset(const T& value) {
		value_ = stringify<T>(value);
	}
}
