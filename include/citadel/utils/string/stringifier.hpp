// File:       stringifier.hpp
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

#include <ostream>
#include <string>
#include <type_traits>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/utils/string/stringifiable.hpp"

namespace citadel {
	template <typename, typename = void>
	struct is_stringifiable : std::false_type { };

	template <typename T>
	struct is_stringifiable<T, std::void_t<decltype(citadel::stringifiable<T>::to_string(std::declval<T>()))>>
		: std::bool_constant<std::is_convertible_v<decltype(citadel::stringifiable<T>::to_string(std::declval<T>())), std::string>> { };

	template <typename T>
	inline constexpr bool is_stringifiable_v = is_stringifiable<T>::value;

	template <typename, typename = void>
	struct has_free_to_string : std::false_type { };

	template <typename T>
	struct has_free_to_string<T, std::void_t<decltype(::to_string(std::declval<T>()))>> : std::true_type { };

	template <typename T>
	inline constexpr bool has_free_to_string_v = has_free_to_string<T>::value;

	template <typename, typename = void>
	struct has_member_to_string : std::false_type { };

	template <typename T>
	struct has_member_to_string<T, std::void_t<decltype(std::declval<T>().to_string())>> : std::true_type { };

	template <typename T>
	inline constexpr bool has_member_to_string_v = has_member_to_string<T>::value;

	template <typename, typename = void>
	struct has_std_to_string : std::false_type { };

	template <typename T>
	struct has_std_to_string<T, std::void_t<decltype(std::to_string(std::declval<T>()))>> : std::true_type { };

	template <typename T>
	inline constexpr bool has_std_to_string_v = has_std_to_string<T>::value;
 
	template <typename, typename = void>
	struct has_ostream_operator : std::false_type { };

	template <typename T>
	struct has_ostream_operator<T, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T>())>> : std::true_type { };

	template <typename T>
	inline constexpr bool has_ostream_operator_v = has_ostream_operator<T>::value;

	class exported stringifier {
	public:
		template <typename T, std::size_t N>
		static std::string stringify(const T(&array)[N]);

		template <typename T>
		static std::string stringify(const T& value);

		stringifier() = default;

		template <typename T>
		stringifier(const T& value);

		void reset();

		template <typename T>
		void reset(const T& value);

		nodisc const std::string& value() const noexcept;

	private:
		std::string value_;
	};
}

#include "citadel/utils/string/stringifier.inl"
