// File:       renderer.cpp
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
#include "citadel/rendering/renderer.hpp"

#include "citadel/rendering/render_command.hpp"

namespace citadel {

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_UNREACHABLE_CODE)

	scope<renderer> renderer::create(rendering_api_type api) {
		switch (api) {
		case rendering_api_type::none:
			CITADEL_LOG_WARNING("No rendering API specified, using default one");
			return make_scoped<renderer>();

		case rendering_api_type::opengl:
			return nullptr;
		}

		CITADEL_PANIC("Unknown rendering API");
		return nullptr;
	}

CITADEL_WARNING_IGNORE_POP

	scope<renderer> renderer::create() {
		return create(render_command::get_api());
	}

	void renderer::begin_scene(scene& scene) {
		CITADEL_CHECK_OPERATION("renderer::begin_scene", scene_data_.has_value());
		scene_data_ = scene.pack();

		scene.refresh();

		for (const mesh_instance& mesh : scene.meshes()) {
			submit(mesh);
		}

		_begin_scene(scene);
	}

	void renderer::end_scene() {
		CITADEL_CHECK_OPERATION("renderer::end_scene", !scene_data_.has_value());
		scene_data_.reset();

		_end_scene();
		flush();
	}

	void renderer::submit(const vertex_array& vertex_array, shader_program& shader, const transform_3d& transform) {
		CITADEL_CHECK_OPERATION("renderer::submit", !scene_data_.has_value());
		_submit(vertex_array, shader, transform);
	}

	void renderer::submit(const mesh_instance& mesh) {
		submit(
			mesh.mesh().vertex_array(),
			mesh.material().shader_program(),
			mesh.transform()
		);
	}

	void renderer::flush() {
		_flush();
	}

	bool renderer::has_scene() const noexcept {
		return scene_data_.has_value();
	}

	void renderer::_begin_scene(scene& scene) { }
	void renderer::_end_scene() { }

	void renderer::_submit(const vertex_array& vertex_array, shader_program& shader, const transform_3d& transform) {
		shader.use();
		const scene::data& data = scene_data_.value();

		shader.set_uniform_mat4("view", data.view);
		shader.set_uniform_mat4("projection", data.projection);
		shader.set_uniform_mat4("transform", transform);

		render_command::draw_indexed(vertex_array);
	}

	void renderer::_flush() { }
}
