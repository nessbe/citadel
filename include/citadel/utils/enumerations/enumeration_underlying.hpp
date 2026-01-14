// File:       enumeration_underlying.hpp
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

#include <type_traits>

namespace citadel {
	namespace detail {
		template <typename Enumeration>
		constexpr auto enumeration_to_underlying(Enumeration enumeration) noexcept
			-> std::enable_if_t<std::is_enum_v<Enumeration>, std::underlying_type_t<Enumeration>>
		{
			return static_cast<std::underlying_type_t<Enumeration>>(enumeration);
		}
	}
}
