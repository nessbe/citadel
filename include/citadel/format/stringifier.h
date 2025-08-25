// File:        stringifier.h
// Project:     citadel
// Repository:  https://github.com/nessbe/citadel
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

#ifndef CITADEL_STRINGIFIER_H
#define CITADEL_STRINGIFIER_H

#include <ostream>
#include <sstream>
#include <string>
#include <type_traits>

#include "citadel/assert.h"
#include "citadel/attributes.h"
#include "citadel/export.h"

#include "citadel/format/stringifiable.h"

namespace Citadel
{
	template<typename, typename = void>
	struct has_to_string_method : std::false_type {};

	template<typename T>
	struct has_to_string_method<
		T,
		std::void_t<decltype(std::declval<T>().to_string())>
	> : std::true_type {
	};

	template<typename T>
	inline constexpr bool has_to_string_method_v = has_to_string_method<T>::value;

	template<typename, typename = void>
	struct has_ostream_operator : std::false_type { };

	template<typename T>
	struct has_ostream_operator<
		T,
		std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T>())>
	> : std::true_type { };

	template<typename T>
	inline constexpr bool has_ostream_operator_v = has_ostream_operator<T>::value;

	class Stringifier
	{
	public:
		template<typename T>
		explicit Stringifier(T&& value)
			: value_(to_string(std::forward<T>(value))) { }
		~Stringifier() = default;

		CITADEL_API CITADEL_INLINE std::string to_string() const;

		template<typename T>
		CITADEL_INLINE static std::string to_string(T&& value)
		{
			return to_string_implementation(std::forward<T>(value));
		}

	private:
		std::string value_;

	private:
		template<typename T>
		static std::string to_string_implementation(T&& value)
		{
			using DecayT = std::decay_t<T>;
			DecayT decay_value = std::forward<T>(value);

			if constexpr (std::is_same_v<DecayT, std::string>)
			{
				return decay_value;
			}
			else if constexpr (std::is_same_v<DecayT, bool>)
			{
				return decay_value ? "true" : "false";
			}
			else if constexpr (std::is_base_of_v<IStringifiable, DecayT>)
			{
				return decay_value.to_string();
			}
			else if constexpr (has_to_string_method_v<DecayT>)
			{
				return decay_value.to_string();
			}
			else if constexpr (has_ostream_operator_v<DecayT>)
			{
				std::ostringstream oss;
				oss << decay_value;
				return oss.str();
			}
			return "[unstringifiable]";
		}
	};
}

#endif
