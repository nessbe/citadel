// File:       shader_data_type.cpp
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

#include "citadel/pch.hpp"
#include "citadel/rendering/shaders/shader_data_type.hpp"

namespace citadel {
	namespace shader_data_type {
		std::size_t size(enumeration value) {
			switch (value) {
			case boolean:
				return sizeof(bool);

			case int1:
				return sizeof(int);

			case int2:
				return sizeof(int) * 2;

			case int3:
				return sizeof(int) * 3;

			case int4:
				return sizeof(int) * 4;

			case float1:
				return sizeof(float);

			case float2:
				return sizeof(float) * 2;

			case float3:
				return sizeof(float) * 3;

			case float4:
				return sizeof(float) * 4;

			case mat3:
				return sizeof(float) * 3 * 3;

			case mat4:
				return sizeof(float) * 4 * 4;

			default:
				CITADEL_PANIC("Unknown shader data type");
				return 0;
			}
		}

		std::size_t component_count(enumeration value) {
			switch (value) {
			case boolean:
				return 1;

			case int1:
				return 1;

			case int2:
				return 2;

			case int3:
				return 3;

			case int4:
				return 4;

			case float1:
				return 1;

			case float2:
				return 2;

			case float3:
				return 3;

			case float4:
				return 4;

			case mat3:
				return 3;

			case mat4:
				return 4;

			default:
				CITADEL_PANIC("Unknown shader data type");
				return 0;
			}
		}
	}
}
