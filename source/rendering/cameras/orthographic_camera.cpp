// File:       orthographic_camera.cpp
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
#include "citadel/rendering/cameras/orthographic_camera.hpp"

namespace citadel {
	orthographic_camera::orthographic_camera(float left, float right, float bottom, float top)
		: left_(left), right_(right), bottom_(bottom), top_(top) { }

	orthographic_camera::orthographic_camera(dimension width, dimension height)
		: left_(0), right_(0), bottom_(0), top_(0)
	{
		set_projection(width, height);
	}

	float orthographic_camera::get_left() const noexcept {
		return left_;
	}

	void orthographic_camera::set_left(float value) noexcept {
		left_ = value;
	}

	float orthographic_camera::get_right() const noexcept {
		return right_;
	}

	void orthographic_camera::set_right(float value) noexcept {
		right_ = value;
	}

	float orthographic_camera::get_bottom() const noexcept {
		return bottom_;
	}

	void orthographic_camera::set_bottom(float value) noexcept {
		bottom_ = value;
	}

	float orthographic_camera::get_top() const noexcept {
		return top_;
	}

	void orthographic_camera::set_top(float value) noexcept {
		top_ = value;
	}

	void orthographic_camera::get_sides(float& left, float& right, float& bottom, float& top) const noexcept {
		left = left_;
		right = right_;
		bottom = bottom_;
		top = top_;
	}

	void orthographic_camera::set_sides(float left, float right, float bottom, float top) noexcept {
		left_ = left;
		right_ = right;
		bottom_ = bottom;
		top_ = top;
	}

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_SPECTRE)

	void orthographic_camera::_set_projection(dimension width, dimension height) {
		float aspect = static_cast<float>(width) / static_cast<float>(height);

		if (aspect >= 1.0) {
			set_sides(-aspect, aspect, -1.0f, 1.0f);
		} else {
			set_sides(-1.0f, 1.0f, -1.0f / aspect, 1.0f / aspect);
		}

	}

CITADEL_WARNING_IGNORE_POP

	mat4 orthographic_camera::_get_projection() const {
		return mat4::ortho(left_, right_, bottom_, top_, -1.0f, 1.0f);
	}
}
