// File:       opengl_vertex_array.cpp
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
#include "citadel/drivers/opengl/opengl_vertex_array.hpp"

#include "citadel/drivers/opengl/opengl_vertex_buffer.hpp"

namespace citadel {
	opengl_vertex_array::opengl_vertex_array()
		: vertex_buffer_index_(0)
	{
		glGenVertexArrays(1, &id_);
		CITADEL_ASSERT(id_, "Failed to generate OpenGL vertex array");
	}

	opengl_vertex_array::~opengl_vertex_array() {
		glDeleteVertexArrays(1, &id_);
	}

	opengl_vertex_array::opengl_vertex_array(opengl_vertex_array&& other) noexcept
		: vertex_buffer_index_(0)
	{
		id_ = other.id_;
		other.id_ = 0;
	}

	opengl_vertex_array& opengl_vertex_array::operator=(opengl_vertex_array&& other) noexcept {
		if (this != &other) {
			glDeleteVertexArrays(1, &id_);

			id_ = other.id_;
			other.id_ = 0;
		}

		return *this;
	}

	opengl_vertex_array::id opengl_vertex_array::get_id() const noexcept {
		return id_;
	}

	void opengl_vertex_array::_bind() {
		glBindVertexArray(id_);
	}

	void opengl_vertex_array::_unbind() {
		glBindVertexArray(0);
	}

CITADEL_IGNORE_WARNING_PUSH();
CITADEL_IGNORE_WARNING(CITADEL_WARNING_SPECTRE);

	void opengl_vertex_array::_add_vertex_buffer(const std::unique_ptr<vertex_buffer>& buffer) {
		CITADEL_ASSERT(buffer, "The given vertex buffer is null");

		if (buffer) {
			bind();
			buffer->bind();

			const vertex_buffer_layout& buffer_layout = buffer->get_layout();
			std::size_t buffer_layout_stride = buffer_layout.get_stride();

			for (const vertex_buffer_element& buffer_element : buffer_layout) {
				switch (buffer_element.data_type) {
				case shader_data_type_bool:
				case shader_data_type_int:
				case shader_data_type_ivec2:
				case shader_data_type_ivec3:
				case shader_data_type_ivec4: {
					glEnableVertexAttribArray(static_cast<GLuint>(vertex_buffer_index_));
					glVertexAttribIPointer(
						static_cast<GLuint>(vertex_buffer_index_),
						static_cast<GLint>(buffer_element.component_count()),
						shader_data_type::to_opengl(buffer_element.data_type),
						static_cast<GLsizei>(buffer_layout_stride),
						reinterpret_cast<const void*>(buffer_element.offset())
					);
					vertex_buffer_index_++;
				} break;

				case shader_data_type_float:
				case shader_data_type_vec2:
				case shader_data_type_vec3:
				case shader_data_type_vec4: {
					glEnableVertexAttribArray(static_cast<GLuint>(vertex_buffer_index_));
					glVertexAttribPointer(
						static_cast<GLuint>(vertex_buffer_index_),
						static_cast<GLint>(buffer_element.component_count()),
						shader_data_type::to_opengl(buffer_element.data_type),
						buffer_element.normalized ? GL_TRUE : GL_FALSE,
						static_cast<GLsizei>(buffer_layout_stride),
						reinterpret_cast<const void*>(buffer_element.offset())
					);
					vertex_buffer_index_++;
				} break;

				case shader_data_type_mat3:
				case shader_data_type_mat4: {
					std::size_t component_count = buffer_element.component_count();

					for (std::size_t i = 0; i < component_count; i++) {
						glEnableVertexAttribArray(static_cast<GLuint>(vertex_buffer_index_));
						glVertexAttribPointer(
							static_cast<GLuint>(vertex_buffer_index_),
							static_cast<GLint>(component_count),
							shader_data_type::to_opengl(buffer_element.data_type),
							buffer_element.normalized ? GL_TRUE : GL_FALSE,
							static_cast<GLsizei>(buffer_layout_stride),
							reinterpret_cast<const void*>(buffer_element.offset() + sizeof(float) * component_count * i)
						);

						glVertexAttribDivisor(static_cast<GLuint>(vertex_buffer_index_), 1);
						vertex_buffer_index_++;
					}
				} break;

				case shader_data_type_unknown:
					break;
				}
			}
		}
	}

CITADEL_IGNORE_WARNING_POP();

	void opengl_vertex_array::_set_index_buffer(const std::shared_ptr<index_buffer>& buffer) {
		CITADEL_ASSERT(buffer, "The given index buffer is null");

		if (buffer) {
			bind();
			buffer->bind();
		}
	}
}
