// File:       transform_3d.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/math/matrices/mat4.hpp"

#include "citadel/math/vectors/vec3.hpp"

namespace citadel {
	class CITADEL_API transform_3d {
	public:
		transform_3d();
		transform_3d(const mat4& matrix);
		transform_3d(const vec3& translation, const vec3& rotation, const vec3& scale);

		bool decompose(vec3& translation, vec3& rotation, vec3& scale) const;

		CITADEL_NODISCARD vec3 get_translation() const;
		void set_translation(const vec3& value);

		CITADEL_NODISCARD vec3 get_rotation() const;
		void set_rotation(const vec3& value);

		CITADEL_NODISCARD vec3 get_scale() const;
		void set_scale(const vec3& value);

		CITADEL_NODISCARD const mat4& get_matrix() const noexcept;
		void set_matrix(const mat4& value) noexcept;

		CITADEL_NODISCARD operator mat4() const;

	private:
		mat4 matrix_;

	private:
		static bool decompose_transform(const mat4& transform, vec3& translation, vec3& rotation, vec3& scale);
	};
}
