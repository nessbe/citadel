// File:       sequential_policy.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	class CITADEL_API sequencial_policy {
	public:
		using value_type = std::uint32_t;

		CITADEL_NODISCARD value_type acquire() noexcept;
		void release(value_type value) noexcept;

	private:
		value_type current_;
	};
}
