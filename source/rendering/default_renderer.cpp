// File:       default_renderer.cpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#include "citadel/pch.hpp"
#include "citadel/rendering/default_renderer.hpp"

#include "citadel/rendering/render_command.hpp"

namespace citadel {
	void default_renderer::_begin_scene(scene& scene) {}
	void default_renderer::_end_scene() {}

	void default_renderer::_submit(const vertex_array& vertex_array, shader_program& shader, const transform_3d& transform) {
		shader.use();
		const scene::data& data = scene_data();

		shader.set_uniform_mat4("view", data.view);
		shader.set_uniform_mat4("projection", data.projection);
		shader.set_uniform_mat4("transform", transform);

		render_command::draw_indexed(vertex_array);
	}

	void default_renderer::_flush() {}
}
