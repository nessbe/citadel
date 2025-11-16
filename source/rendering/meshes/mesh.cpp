// File:       mesh.cpp
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
#include "citadel/rendering/meshes/mesh.hpp"

namespace citadel {
	mesh::mesh(const std::vector<vertex>& vertices, const std::vector<index_buffer::index>& indices) :
		vertex_array_(vertex_array::create()),
		vertex_buffer_(vertex_buffer::create(vertices)),
		index_buffer_(index_buffer::create(indices))
	{
		CITADEL_ASSERT(vertex_array_, "Failed to create vertex array");
		CITADEL_ASSERT(vertex_buffer_, "Failed to create vertex buffer");
		CITADEL_ASSERT(index_buffer_, "Failed to create index buffer");

		if (vertex_array_) {
			vertex_array_->bind();
			vertex_array_->add_vertex_buffer(vertex_buffer_);
			vertex_array_->set_index_buffer(index_buffer_);
			vertex_array_->unbind();
		}
	}

	mesh::mesh(const void* data, std::size_t size, const std::vector<index_buffer::index>& indices) :
		vertex_array_(vertex_array::create()),
		vertex_buffer_(vertex_buffer::create(data, size)),
		index_buffer_(index_buffer::create(indices))
	{
		CITADEL_ASSERT(vertex_array_, "Failed to create vertex array");
		CITADEL_ASSERT(vertex_buffer_, "Failed to create vertex buffer");
		CITADEL_ASSERT(index_buffer_, "Failed to create index buffer");

		if (vertex_array_) {
			vertex_array_->bind();
			vertex_array_->add_vertex_buffer(vertex_buffer_);
			vertex_array_->set_index_buffer(index_buffer_);
			vertex_array_->unbind();
		}
	}

	mesh::~mesh() {
		CITADEL_ASSERT(vertex_buffer_, "Vertex buffer is null");
		vertex_buffer_->unbind();

		CITADEL_ASSERT(index_buffer_, "Index buffer is null");
		index_buffer_->unbind();

		CITADEL_ASSERT(vertex_array_, "Vertex array is null");
		vertex_array_->unbind();
	}

	void mesh::bind() {
		vertex_array_->bind();
	}

	void mesh::unbind() {
		vertex_array_->unbind();
	}

	void mesh::render() {
		bind();
		CITADEL_ASSERT(index_buffer_, "Index buffer is null");
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(index_buffer_->size()), GL_UNSIGNED_INT, nullptr);
	}

	vertex_array& mesh::get_vertex_array() const {
		CITADEL_ASSERT(vertex_array_, "Vertex array is null");
		return *vertex_array_;
	}

	vertex_buffer& mesh::get_vertex_buffer() const {
		CITADEL_ASSERT(vertex_buffer_, "Vertex buffer is null");
		return *vertex_buffer_;
	}

	index_buffer& mesh::get_index_buffer() const {
		CITADEL_ASSERT(index_buffer_, "Index buffer is null");
		return *index_buffer_;
	}
}
