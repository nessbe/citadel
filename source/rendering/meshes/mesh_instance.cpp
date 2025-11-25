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
	mesh_instance::mesh_instance(const std::shared_ptr<mesh>& mesh, const std::shared_ptr<material>& material, const mat4 transform)
		: mesh_(mesh), material_(material), transform_(transform)
	{
		CITADEL_ASSERT(mesh, "The given mesh is null");
		CITADEL_ASSERT(material, "The given material is null");
	}

	void mesh_instance::render(const mat4& view_projection) {
		mesh_->bind();

		material_->use();

		citadel::mat4 mvp = view_projection * transform_;
		material_->set_uniform_mat4("mvp", mvp);

		material_->apply();

		mesh_->render();
		mesh_->unbind();
	}

	void mesh_instance::render(const mat4& view, const mat4& projection) {
		render(projection * view);
	}

	mesh& mesh_instance::get_mesh() const noexcept {
		return *mesh_;
	}

	material& mesh_instance::get_material() const noexcept {
		return *material_;
	}

	const transform_3d& mesh_instance::get_transform() const noexcept {
		return transform_;
	}

	void mesh_instance::set_transform(const transform_3d& value) noexcept {
		transform_ = value;
	}
}
