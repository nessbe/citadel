// File:       mesh_instance.cpp
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
#include "citadel/rendering/meshes/mesh_instance.hpp"

namespace citadel {
	mesh_instance::mesh_instance(const reference<class mesh>& mesh, const reference<class material>& material, const transform_3d& transform)
		: mesh_(mesh), material_(material), transform_(transform)
	{
		CITADEL_CHECK_ARGUMENT(mesh, mesh == nullptr);
		CITADEL_CHECK_ARGUMENT(material, material == nullptr);
	}

	void mesh_instance::use() {
		CITADEL_POINTER_CALL(mesh_, bind);
		CITADEL_POINTER_CALL(material_, use);
	}

	void mesh_instance::render(const mat4& view, const mat4& projection) {
		use();

		CITADEL_POINTER_CALL(material_, set_uniform_mat4, "view", view);
		CITADEL_POINTER_CALL(material_, set_uniform_mat4, "projection", projection);
		CITADEL_POINTER_CALL(material_, set_uniform_mat4, "transform", transform_);

		CITADEL_POINTER_CALL(material_, apply);

		CITADEL_POINTER_CALL(mesh_, render);
		CITADEL_POINTER_CALL(mesh_, unbind);
	}

	mesh& mesh_instance::mesh() const {
		CITADEL_POINTER_RETURN_REFERENCE(mesh_);
	}

	material& mesh_instance::material() const {
		CITADEL_POINTER_RETURN_REFERENCE(material_);
	}

	const transform_3d& mesh_instance::transform() const noexcept {
		return transform_;
	}

	void mesh_instance::set_transform(const transform_3d& value) {
		transform_ = value;
	}
}
