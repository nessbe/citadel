// File:       opengl_vertex_buffer.cpp
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
#include "citadel/drivers/opengl/opengl_vertex_buffer.hpp"

namespace citadel {
	opengl_vertex_buffer::opengl_vertex_buffer(std::size_t size)
		: vertex_buffer(size) { }

	opengl_vertex_buffer::opengl_vertex_buffer(opengl_vertex_buffer&& other) noexcept
		: opengl_vertex_buffer(other.size()) {
		id_ = other.id_;
		other.id_ = 0;
	}

	opengl_vertex_buffer& opengl_vertex_buffer::operator=(opengl_vertex_buffer&& other) noexcept {
		if (this != &other) {
			destroy();

			id_ = other.id_;
			other.id_ = 0;
		}

		return *this;
	}

	opengl_vertex_buffer::id opengl_vertex_buffer::get_id() const noexcept {
		return id_;
	}

	void opengl_vertex_buffer::_construct() {
		glGenBuffers(1, &id_);
		CITADEL_ASSERT(id_, "Failed to create OpenGL vertex buffer");
	}

	void opengl_vertex_buffer::_destroy() noexcept {
		if (id_) {
			glDeleteBuffers(1, &id_);
		}
	}

	void opengl_vertex_buffer::_bind() {
		CITADEL_ASSERT(id_, "Vertex buffer is not yet constructed");
		glBindBuffer(GL_ARRAY_BUFFER, id_);
	}

	void opengl_vertex_buffer::_unbind() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void opengl_vertex_buffer::_set_data(const void* data, std::size_t size) {
		bind();
		glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(size), data, GL_STATIC_DRAW);
	}
}
