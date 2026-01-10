// File:       renderer.hpp
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

#include <optional>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/math/transforms/transform_3d.hpp"

#include "citadel/memory/reference.hpp"
#include "citadel/memory/scope.hpp"

#include "citadel/rendering/rendering_api_type.hpp"

#include "citadel/rendering/materials/material.hpp"

#include "citadel/rendering/meshes/mesh_instance.hpp"

#include "citadel/rendering/vertices/vertex_array.hpp"

#include "citadel/scenes/scene.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported renderer {
	public:
		nodisc static scope<renderer> create(rendering_api_type api);
		nodisc static scope<renderer> create();

		virtual ~renderer() = default;

		void begin_scene(scene& scene);
		void end_scene();

		void submit(const vertex_array& vertex_array, shader_program& shader, const transform_3d& transform);
		void submit(const mesh_instance& mesh);

		void flush();

		nodisc bool has_scene() const noexcept;
		nodisc scene::data& scene_data();

	private:
		std::optional<scene::data> scene_data_;

	private:
		virtual void _begin_scene(scene& scene) = 0;
		virtual void _end_scene() = 0;

		virtual void _submit(const vertex_array& vertex_array, shader_program& shader, const transform_3d& transform) = 0;
		virtual void _flush() = 0;
	};
}

CITADEL_WARNING_IGNORE_POP
