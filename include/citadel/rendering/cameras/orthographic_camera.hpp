// File:       orthographic_camera.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/math/matrices/mat4.hpp"

#include "citadel/rendering/cameras/camera.hpp"

namespace citadel {
	class api orthographic_camera : public camera {
	public:
		using dimension = std::uint32_t;

	public:
		orthographic_camera(float left, float right, float bottom, float top);
		orthographic_camera(dimension width, dimension height);

		nodisc float get_left() const noexcept;
		void set_left(float value) noexcept;

		nodisc float get_right() const noexcept;
		void set_right(float value) noexcept;

		nodisc float get_bottom() const noexcept;
		void set_bottom(float value) noexcept;

		nodisc float get_top() const noexcept;
		void set_top(float value) noexcept;

		void get_sides(float& left, float& right, float& bottom, float& top) const noexcept;
		void set_sides(float left, float right, float bottom, float top) noexcept;

	private:
		float left_, right_, bottom_, top_;

	private:
		virtual void _set_projection(dimension width, dimension height) override;
		nodisc virtual mat4 _get_projection() const override;
	};
}
