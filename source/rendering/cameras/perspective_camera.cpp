// File:       perspective_camera.cpp
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
#include "citadel/rendering/cameras/perspective_camera.hpp"

namespace citadel {
	perspective_camera::perspective_camera(float fov, float aspect, float near, float far)
		: fov_(fov), aspect_(aspect), near_(near), far_(far) { }

	perspective_camera::perspective_camera(float fov, dimension_type width, dimension_type height, float near, float far)
		: perspective_camera(fov, static_cast<float>(width) / static_cast<float>(height), near, far) { }

	float perspective_camera::get_fov() const noexcept {
		return fov_;
	}

	void perspective_camera::set_fov(float value) noexcept {
		fov_ = value;
	}

	float perspective_camera::get_aspect() const noexcept {
		return aspect_;
	}

	void perspective_camera::set_aspect(float value) noexcept {
		aspect_ = value;
	}

	float perspective_camera::get_near() const noexcept {
		return near_;
	}

	void perspective_camera::set_near(float value) noexcept {
		near_ = value;
	}

	float perspective_camera::get_far() const noexcept {
		return far_;
	}

	void perspective_camera::set_far(float value) noexcept {
		far_ = value;
	}

	void perspective_camera::_set_projection(dimension_type width, dimension_type height) {
		aspect_ = width > 0 && height > 0 ? static_cast<float>(width) / static_cast<float>(height) : 1.0f;
	}

	mat4 perspective_camera::_get_projection() const {
		return mat4::perspective(fov_, aspect_, near_, far_);
	}
}
