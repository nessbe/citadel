// File:       perspective_camera.hpp
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
	class exported perspective_camera : public camera {
	public:
		perspective_camera(float fov, float aspect, float near, float far);
		perspective_camera(float fov, dimension_type width, dimension_type height, float near, float far);

		nodisc float get_fov() const noexcept;
		void set_fov(float value) noexcept;

		nodisc float get_aspect() const noexcept;
		void set_aspect(float value) noexcept;

		nodisc float get_near() const noexcept;
		void set_near(float value) noexcept;

		nodisc float get_far() const noexcept;
		void set_far(float value) noexcept;

	private:
		float fov_, aspect_, near_, far_;

	private:
		virtual void _set_projection(dimension_type width, dimension_type height) override;
		nodisc virtual mat4 _get_projection() const override;
	};
}
