// File:       shader_data_type.hpp
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

#include <cinttypes>
#include <cstddef>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	namespace shader_data_type {
		using type = std::uint8_t;

		enum enumeration : type {
			boolean = 0,
			int1,
			int2,
			int3,
			int4,
			float1,
			float2,
			float3,
			float4,
			mat3,
			mat4,
		};

		nodisc api std::size_t size(enumeration value) noexcept;
		nodisc api std::size_t component_count(enumeration value) noexcept;
	}
}
