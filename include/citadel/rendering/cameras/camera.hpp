// File:       camera.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/math/matrices/mat4.hpp"

#include "citadel/math/vectors/vec3.hpp"

namespace citadel {
	class api camera {
	public:
		using dimension = std::uint32_t;

	public:
		camera() = default;
		virtual ~camera() = default;

		nodisc mat4 get_view() const;

		void set_projection(dimension width, dimension height);
		nodisc mat4 get_projection() const;

		nodisc const vec3& get_position() const noexcept;
		void set_position(const vec3& value) noexcept;

		nodisc const vec3& get_rotation() const noexcept;
		void set_rotation(const vec3& value) noexcept;

	private:
		vec3 position_;
		vec3 rotation_;

	private:
		virtual void _set_projection(dimension width, dimension height) = 0;
		nodisc virtual mat4 _get_projection() const = 0;
	};
}
