// File:       formatter.inl
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

#include <optional>
#include <tuple>
#include <type_traits>

#include "citadel/warnings.hpp"

#include "citadel/utils/string/string_convertion.hpp"
#include "citadel/utils/string/stringifier.hpp"

#include "citadel/utils/variadic/variadic_accessor.hpp"

namespace citadel {

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_SPECTRE)

	template <typename... Arguments>
	std::string formatter::format(const std::string& source, Arguments&&... arguments) {
		std::size_t source_size = source.size();

		std::string result;
		result.resize(source_size);

		variadic_accessor<Arguments...> arguments_accessor(std::forward<Arguments>(arguments)...);

		for (std::size_t i = 0; i < source_size; i++) {
			char character = source[i];

			if (character == '{') {
				std::size_t j = i + 1;
				std::string number_string;

				while (j < source_size && std::isdigit(static_cast<unsigned char>(source[j])) ) {
					number_string.push_back(source[j++]);
				}

				if (std::optional<int> number = to_int(number_string)) {
					std::size_t index = static_cast<std::size_t>(number.value());

					arguments_accessor.visit(index, [&result](auto& value) {
						result += stringifier::stringify<decltype(value)>(value);
					});

					i = j;
					continue;
				}
			}

			result.push_back(character);
		}

		return result;
	}

CITADEL_WARNING_IGNORE_POP

	template <typename... Arguments>
	std::string formatter::formatted(Arguments&&... arguments) {
		return format(source_, std::forward<Arguments>(arguments)...);
	}
}
