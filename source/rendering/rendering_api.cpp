// File:       rendering_api.cpp
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
#include "citadel/rendering/rendering_api.hpp"

#include "citadel/drivers/opengl/opengl_rendering_api.hpp"

#include "citadel/rendering/vertices/vertex_array.hpp"

namespace citadel {
CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_UNREACHABLE_CODE)

	std::unique_ptr<rendering_api> rendering_api::create(rendering_api_type api) {
		switch (api) {
		case rendering_api_type::none:
			CITADEL_PANIC("Rendering API cannot be none");
			return nullptr;

		case rendering_api_type::opengl:
			return std::make_unique<opengl_rendering_api>(api);
		}

		CITADEL_PANIC("Unknown rendering API");
		return nullptr;
	}

CITADEL_IGNORE_WARNING_POP()

	rendering_api::rendering_api(rendering_api_type api)
		: api_(api) { }

	void rendering_api::draw_indexed(const std::unique_ptr<vertex_array>& vertex_array, std::size_t vertex_count) {
		CITADEL_ASSERT(vertex_array, "The given vertex array is null");
		_draw_indexed(vertex_array, vertex_count);
	}

	void rendering_api::draw_indexed(const std::unique_ptr<vertex_array>& vertex_array) {
		CITADEL_ASSERT(vertex_array, "The given vertex array is null");
		const index_buffer& index_buffer = vertex_array->get_index_buffer();
		_draw_indexed(vertex_array, index_buffer.size());
	}

	void rendering_api::draw_lines(const std::unique_ptr<vertex_array>& vertex_array, std::size_t vertex_count) {
		CITADEL_ASSERT(vertex_array, "The given vertex array is null");
		_draw_lines(vertex_array, vertex_count);
	}

	void rendering_api::draw_lines(const std::unique_ptr<vertex_array>& vertex_array) {
		CITADEL_ASSERT(vertex_array, "The given vertex array is null");
		const index_buffer& index_buffer = vertex_array->get_index_buffer();
		_draw_lines(vertex_array, index_buffer.size());
	}

	void rendering_api::set_line_width(float value) {
		_set_line_width(value);
	}

	rendering_api_type rendering_api::get_api() const noexcept {
		return api_;
	}
}
