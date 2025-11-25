// File:       transform_3d.cpp
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
#include "citadel/math/transforms/transform_3d.hpp"

namespace citadel {
	transform_3d::transform_3d()
		: matrix_(mat4::identity()) { }

	transform_3d::transform_3d(const mat4& matrix)
		: matrix_(matrix) { }

	transform_3d::transform_3d(const vec3& position, const vec3& rotation, const vec3& scale) :
		matrix_(
			mat4::identity()
				.translate(position)
				.rotate_x(rotation.x)
				.rotate_y(rotation.y)
				.rotate_z(rotation.z)
				.scale(scale)
		)
	{ }

	bool transform_3d::decompose(vec3& translation, vec3& rotation, vec3& scale) const {
		return decompose_transform(matrix_, translation, rotation, scale);
	}

	vec3 transform_3d::get_translation() const {
		vec3 translation, rotation, scale;

		if (!decompose(translation, rotation, scale)) {
			return vec3(0.0f, 0.0f, 0.0f);
		}

		return translation;
	}

	void transform_3d::set_translation(const vec3& value) {
		vec3 translation, rotation, scale;

		if (!decompose(translation, rotation, scale)) {
			return;
		}

		matrix_ = mat4::identity()
			.translate(value)
			.rotate_x(rotation.x)
			.rotate_y(rotation.y)
			.rotate_z(rotation.z)
			.scale(scale);
	}

	vec3 transform_3d::get_rotation() const {
		vec3 translation, rotation, scale;

		if (!decompose(translation, rotation, scale)) {
			return vec3(0.0f, 0.0f, 0.0f);
		}

		return rotation;
	}

	void transform_3d::set_rotation(const vec3& value) {
		vec3 translation, rotation, scale;

		if (!decompose(translation, rotation, scale)) {
			return;
		}

		matrix_ = mat4::identity()
			.translate(translation)
			.rotate_x(value.x)
			.rotate_y(value.y)
			.rotate_z(value.z)
			.scale(scale);
	}

	vec3 transform_3d::get_scale() const {
		vec3 translation, rotation, scale;

		if (!decompose(translation, rotation, scale)) {
			return vec3(0.0f, 0.0f, 0.0f);
		}

		return scale;
	}

	void transform_3d::set_scale(const vec3& value) {
		vec3 translation, rotation, scale;

		if (!decompose(translation, rotation, scale)) {
			return;
		}

		matrix_ = mat4::identity()
			.translate(translation)
			.rotate_x(rotation.x)
			.rotate_y(rotation.y)
			.rotate_z(rotation.z)
			.scale(value);
	}

	const mat4& transform_3d::get_matrix() const noexcept {
		return matrix_;
	}

	void transform_3d::set_matrix(const mat4& value) noexcept {
		matrix_ = value;
	}

	transform_3d::operator mat4() const {
		return matrix_;
	}

	bool transform_3d::decompose_transform(const mat4& transform, vec3& translation, vec3& rotation, vec3& scale) {
		mat4 local(transform);

		translation.x = local.w.x;
		translation.y = local.w.y;
		translation.z = local.w.z;

		local.w.x = 0.0f;
		local.w.y = 0.0f;
		local.w.z = 0.0f;

		vec3 x_column(local.x.x, local.x.y, local.x.z);
		vec3 y_column(local.y.x, local.y.y, local.y.z);
		vec3 z_column(local.z.x, local.z.y, local.z.z);

		scale.x = x_column.length();
		scale.y = y_column.length();
		scale.z = z_column.length();

		if (scale.x == 0 || scale.y == 0 || scale.z == 0) {
			return false;
		}

		x_column /= scale.x;
		y_column /= scale.y;
		z_column /= scale.z;

		float sinus_y = -z_column.y;
		float cosinus_y = std::sqrt(1.0f - sinus_y * sinus_y);

		bool singular = cosinus_y < gimbal_lock;

		if (!singular) {
			rotation.x = std::atan2(z_column.y, z_column.z);
			rotation.y = std::atan2(-z_column.x, z_column.z);
			rotation.z = std::atan2(y_column.x, x_column.x);
		}
		else {
			rotation.x = std::atan2(-y_column.z, y_column.y);
			rotation.y = std::atan2(-z_column.x, z_column.z);
			rotation.z = 0.0f;
		}

		return true;
	}
}
