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
	opengl_vertex_array::opengl_vertex_array() {
		glGenVertexArrays(1, &id_);
		CITADEL_ASSERT(id_, "Failed to generate OpenGL vertex array");
	}

	opengl_vertex_array::~opengl_vertex_array() {
		glDeleteVertexArrays(1, &id_);
	}

	opengl_vertex_array::opengl_vertex_array(opengl_vertex_array&& other) noexcept {
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

	void opengl_vertex_array::_add_vertex_buffer(const std::unique_ptr<vertex_buffer>& buffer) {
		CITADEL_ASSERT(buffer, "The given vertex buffer is null");

		if (buffer) {
			bind();
			buffer->bind();

			glEnableVertexArrayAttrib(id_, 0);
			glVertexAttribPointer(
				0,
				3,
				GL_FLOAT,
				GL_FALSE,
				static_cast<GLsizei>(7 * sizeof(float)),
				reinterpret_cast<void*>(0)
			);

			glEnableVertexArrayAttrib(id_, 1);
			glVertexAttribPointer(
				1,
				4,
				GL_FLOAT,
				GL_FALSE,
				static_cast<GLsizei>(7 * sizeof(float)),
				reinterpret_cast<void*>(3 * sizeof(float))
			);

			buffer->unbind();
		}
	}

	void opengl_vertex_array::_set_index_buffer(const std::shared_ptr<index_buffer>& buffer) {
		CITADEL_ASSERT(buffer, "The given index buffer is null");

		if (buffer) {
			bind();
			buffer->bind();
		}
	}
}
