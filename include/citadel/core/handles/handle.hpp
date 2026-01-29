// File:       handle.hpp
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

#include <cinttypes>
#include <type_traits>

#include "citadel/attributes.hpp"

namespace citadel {
	template <typename Tag, typename Value = std::uint32_t>
	struct handle {
		static_assert(std::is_integral_v<Value>, "Type Value must be integral");

	public:
		using value_type = Value;

	public:
		static const Value default_value;

	public:
		constexpr handle() noexcept;
		constexpr explicit handle(Value value) noexcept;

		CITADEL_NODISCARD constexpr Value value() const noexcept;
		CITADEL_NODISCARD constexpr bool valid() const noexcept;

		CITADEL_NODISCARD constexpr operator bool() const noexcept;
		CITADEL_NODISCARD friend constexpr bool operator==(handle, handle) = default;

	private:
		Value value_;
	};
}

#include "citadel/core/handles/handle.inl"
