// File:       opengl_vertex_buffer.cpp
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
#include "citadel/drivers/opengl/opengl_vertex_buffer.hpp"

namespace citadel {
	opengl_vertex_buffer::opengl_vertex_buffer(std::size_t size, const vertex_buffer_layout& layout)
		: vertex_buffer(size, layout)
	{
		glGenBuffers(1, &id_);
		CITADEL_ASSERT(id_ != 0, "Failed to generate OpenGL vertex buffer");


		glBindBuffer(GL_ARRAY_BUFFER, id_);
		glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(size), nullptr, GL_DYNAMIC_DRAW);
	}

	opengl_vertex_buffer::opengl_vertex_buffer(const void* data, std::size_t size, const vertex_buffer_layout& layout)
		: vertex_buffer(size, layout)
	{
		glGenBuffers(1, &id_);
		CITADEL_ASSERT(id_ != 0, "Failed to generate OpenGL vertex buffer");

		glBindBuffer(GL_ARRAY_BUFFER, id_);
		glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(size), data, GL_STATIC_DRAW);
	}

	opengl_vertex_buffer::~opengl_vertex_buffer() {
		glDeleteBuffers(1, &id_);
	}

	opengl_vertex_buffer::opengl_vertex_buffer(opengl_vertex_buffer&& other) noexcept
		: opengl_vertex_buffer(other.size(), other.get_layout()) {
		id_ = other.id_;
		other.id_ = 0;
	}

	opengl_vertex_buffer& opengl_vertex_buffer::operator=(opengl_vertex_buffer&& other) noexcept {
		if (this != &other) {
			glDeleteBuffers(1, &id_);

			id_ = other.id_;
			other.id_ = 0;
		}

		return *this;
	}

	opengl_vertex_buffer::id_type opengl_vertex_buffer::get_id() const noexcept {
		return id_;
	}

	void opengl_vertex_buffer::_bind() {
		glBindBuffer(GL_ARRAY_BUFFER, id_);
	}

	void opengl_vertex_buffer::_unbind() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void opengl_vertex_buffer::_set_data(const void* data, std::size_t size) {
		bind();
		glBufferSubData(GL_ARRAY_BUFFER, 0, static_cast<GLsizeiptr>(size), data);
	}
}
