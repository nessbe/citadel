// File:       mesh_instance.hpp
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

#include "citadel/math/transforms/transform_3d.hpp"

#include "citadel/memory/reference.hpp"

#include "citadel/rendering/rendering_api_type.hpp"

#include "citadel/rendering/materials/material.hpp"

#include "citadel/rendering/meshes/mesh.hpp"

namespace citadel {
	class CITADEL_API mesh_instance {
	public:
		mesh_instance(const reference<mesh>& mesh, const reference<material>& material, const transform_3d& transform);

		void use();
		void render(const mat4& view, const mat4& projection);

		CITADEL_NODISCARD mesh& mesh() const;
		CITADEL_NODISCARD material& material() const;

		CITADEL_NODISCARD const transform_3d& transform() const noexcept;
		void set_transform(const transform_3d& value);

	private:
		reference<class mesh>  mesh_;
		reference<class material> material_;

		transform_3d transform_;
	};
}
