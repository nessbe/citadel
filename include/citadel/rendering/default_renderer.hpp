// File:       default_renderer.hpp
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

#pragma once

#include "citadel/export.hpp"

#include "citadel/rendering/renderer.hpp"

namespace citadel {
	class CITADEL_API default_renderer final : public renderer {
	private:
		virtual void _begin_scene(scene& scene) override;
		virtual void _end_scene() override;

		virtual void _submit(const vertex_array& vertex_array, shader_program& shader, const transform_3d& transform) override;
		virtual void _flush() override;
	};
}
