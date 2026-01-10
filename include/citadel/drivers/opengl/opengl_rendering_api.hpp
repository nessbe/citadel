// File:       opengl_rendering_api.hpp
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

#include "citadel/export.hpp"

#include "citadel/memory/scope.hpp"

#include "citadel/rendering/rendering_api.hpp"
#include "citadel/rendering/rendering_api_type.hpp"

namespace citadel {
	class CITADEL_API opengl_rendering_api : public rendering_api {
	public:
		opengl_rendering_api(rendering_api_type api);

	private:
		virtual void _draw_indexed(const vertex_array& vertex_array, std::size_t vertex_count) override;
		virtual void _draw_lines(const vertex_array& vertex_array, std::size_t vertex_count) override;

		virtual void _set_line_width(float value) override;
	};
}
