// File:       rendering_api.cpp
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

#include "citadel/pch.hpp"
#include "citadel/rendering/rendering_api.hpp"

#include "citadel/drivers/opengl/opengl_rendering_api.hpp"

#include "citadel/rendering/vertices/vertex_array.hpp"

namespace citadel {

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_UNREACHABLE_CODE)

	scope<rendering_api> rendering_api::create(rendering_api_type api) {
		switch (api) {
		case rendering_api_type::none:
			CITADEL_UNREACHABLE("Rendering API must not be none");
			return nullptr;

		case rendering_api_type::opengl:
			return make_scoped<opengl_rendering_api>(api);

		default:
			CITADEL_UNREACHABLE("Unknown rendering API: {0}", api);
			return nullptr;
		}
	}

CITADEL_WARNING_IGNORE_POP

	rendering_api::rendering_api(rendering_api_type api)
		: api_(api) { }

	void rendering_api::draw_indexed(const vertex_array& vertex_array, std::size_t vertex_count) {
		_draw_indexed(vertex_array, vertex_count);
	}

	void rendering_api::draw_indexed(const vertex_array& vertex_array) {
		index_buffer& index_buffer = vertex_array.index_buffer();
		_draw_indexed(vertex_array, index_buffer.size());
	}

	void rendering_api::draw_lines(const vertex_array& vertex_array, std::size_t vertex_count) {
		_draw_lines(vertex_array, vertex_count);
	}

	void rendering_api::draw_lines(const vertex_array& vertex_array) {
		const index_buffer& index_buffer = vertex_array.index_buffer();
		_draw_lines(vertex_array, index_buffer.size());
	}

	void rendering_api::set_line_width(float value) {
		_set_line_width(value);
	}

	rendering_api_type rendering_api::get_api() const noexcept {
		return api_;
	}
}
