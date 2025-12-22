// File:       scene.cpp
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
#include "citadel/scenes/scene.hpp"

namespace citadel {
	scene::scene(const reference<class camera>& camera)
		: camera_(camera)
	{
		CITADEL_CHECK_ARGUMENT(camera, camera == nullptr);
	}

	void scene::refresh() {
		view_ = camera_->get_view();
		projection_ = camera_->get_projection();
		CITADEL_LOG_DEBUG("Scene refreshed successfully");
	}

	const mat4& scene::view() const noexcept {
		return view_;
	}

	const mat4& scene::projection() const noexcept {
		return projection_;
	}

	mat4 scene::view_projection() const noexcept {
		return projection_ * view_;
	}

	void scene::add(const mesh_instance& mesh) {
		meshes_.push_back(mesh);
	}

	const std::vector<mesh_instance>& scene::meshes() const noexcept {
		return meshes_;
	}

	camera& scene::camera() const noexcept {
		CITADEL_POINTER_RETURN_REFERENCE(camera_);
	}

	scene::data scene::pack() const {
		return {
			view(),
			projection()
		};
	}
}
