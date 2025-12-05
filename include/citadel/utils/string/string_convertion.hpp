// File:       string_convertion.hpp
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
#include <string>
#include <type_traits>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	template <typename T>
	nodisc std::optional<T> from_characters(const std::string& string);

	template <typename T, typename Enabled>
	nodisc std::optional<T> to_arithmetic(const std::string& string);

	template <typename T>
	nodisc std::enable_if_t<std::is_arithmetic_v<T>, std::optional<T>> to_arithmetic(const std::string& string);

	nodisc exported std::optional<int> to_int(const std::string& string);
	nodisc exported std::optional<float> to_float(const std::string& string);
	nodisc exported std::optional<double> to_double(const std::string& string);
}

#include "citadel/utils/string/string_convertion.inl"
