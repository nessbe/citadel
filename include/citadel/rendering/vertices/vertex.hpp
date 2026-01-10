// File:       vertex.hpp
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

#include <type_traits>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/math/vectors/vec2.hpp"
#include "citadel/math/vectors/vec3.hpp"

namespace citadel {
	struct CITADEL_API vertex {
	public:
		vec3 position;
		vec3 normal;
		vec2 uv;

	public:
		vertex() = default;
		vertex(const vec3& position, const vec3& normal, const vec2& uv);

		CITADEL_NODISCARD void* data() noexcept;
		CITADEL_NODISCARD const void* data() const noexcept;

		CITADEL_NODISCARD const vec3& get_position() const noexcept;
		void set_position(const vec3& value) noexcept;

		CITADEL_NODISCARD const vec3& get_normal() const noexcept;
		void set_normal(const vec3& value) noexcept;

		CITADEL_NODISCARD const vec2& get_uv() const noexcept;
		void set_uv(const vec2& value) noexcept;
	};

	static_assert(std::is_trivially_copyable_v<vertex>, "Vertex struct is not trivially copyable");
	static_assert(std::is_standard_layout_v<vertex>, "Vertex struct layout is not standard");
}
