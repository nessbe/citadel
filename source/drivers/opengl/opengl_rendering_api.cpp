// File:       opengl_rendering_api.cpp
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
#include "citadel/drivers/opengl/opengl_rendering_api.hpp"

#include "citadel/rendering/indices/index_buffer.hpp"

namespace citadel {
	opengl_rendering_api::opengl_rendering_api(rendering_api_type api)
		: rendering_api(api) { }

	void opengl_rendering_api::_draw_indexed(const vertex_array& vertex_array, std::size_t vertex_count) {
		vertex_array.bind();
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(vertex_count), GL_UNSIGNED_INT, nullptr);
	}

	void opengl_rendering_api::_draw_lines(const vertex_array& vertex_array, std::size_t vertex_count) {
		vertex_array.bind();
		glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(vertex_count));
	}

	void opengl_rendering_api::_set_line_width(float value) {
		glLineWidth(value);
	}
}
