// File:       opengl_index_buffer.cpp
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
#include "citadel/drivers/opengl/opengl_index_buffer.hpp"

namespace citadel {
	opengl_index_buffer::opengl_index_buffer(const std::vector<index>& indices)
		: index_buffer(indices) {
		glGenBuffers(1, &id_);
		CITADEL_SOFT_ASSERT(id_, "Failed to generate OpenGL index buffer");

		glBindBuffer(GL_ARRAY_BUFFER, id_);
		glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(indices.size() * sizeof(index)), indices.data(), GL_STATIC_DRAW);
	}

	opengl_index_buffer::opengl_index_buffer(const index* data, std::size_t size)
		: index_buffer(data, size) {
		glGenBuffers(1, &id_);
		CITADEL_SOFT_ASSERT(id_, "Failed to generate OpenGL index buffer");

		glBindBuffer(GL_ARRAY_BUFFER, id_);
		glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(size * sizeof(index)), data, GL_STATIC_DRAW);
	}

	opengl_index_buffer::~opengl_index_buffer() {
		glDeleteBuffers(1, &id_);
	}

	opengl_index_buffer::opengl_index_buffer(opengl_index_buffer&& other) noexcept
		: index_buffer(other.data(), other.size()) {
		id_ = other.id_;
		set_data(other.data(), other.size());

		other.id_ = 0;
		other.set_data(nullptr, 0);
	}

	opengl_index_buffer& opengl_index_buffer::operator=(opengl_index_buffer&& other) noexcept {
		if (this !=  &other) {
			glDeleteBuffers(1, &id_);

			id_ = other.id_;
			set_data(other.data(), other.size());

			other.id_ = 0;
			other.set_data(nullptr, 0);
		}

		return *this;
	}

	void opengl_index_buffer::_bind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
	}

	void opengl_index_buffer::_unbind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void opengl_index_buffer::_set_data(const index* data, std::size_t size) {
		bind();
		glBufferSubData(GL_ARRAY_BUFFER, 0, static_cast<GLsizeiptr>(size), data);
	}
}
