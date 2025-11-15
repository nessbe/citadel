// File:       camera.cpp
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
#include "citadel/rendering/cameras/camera.hpp"

namespace citadel {
	mat4 camera::get_view() const {
		mat4 transform = mat4::identity()
			.translate(position_)
			.rotate_x(rotation_.x)
			.rotate_y(rotation_.y)
			.rotate_z(rotation_.z);

		return transform.inverse();
	}

	mat4 camera::get_projection() const {
		return _get_projection();
	}

	const vec3& camera::get_position() const noexcept {
		return position_;
	}

	void camera::set_position(const vec3& value) noexcept {
		position_ = value;
	}

	const vec3& camera::get_rotation() const noexcept {
		return rotation_;
	}

	void camera::set_rotation(const vec3& value) noexcept {
		rotation_ = value;
	}
}
