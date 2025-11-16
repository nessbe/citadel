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
	mesh::mesh(const std::vector<vertex>& vertices) :
		vertex_array_(vertex_array::create()),
		vertex_buffer_(vertex_buffer::create(vertices))
	{
		CITADEL_ASSERT(vertex_array_, "Failed to create vertex array");
		CITADEL_ASSERT(vertex_buffer_, "Failed to create vertex buffer");

		if (vertex_array_) {
			vertex_array_->bind();
			vertex_array_->add_buffer(vertex_buffer_);
			vertex_array_->unbind();
		}
	}

	mesh::mesh(const void* data, std::size_t length) :
		vertex_array_(vertex_array::create()),
		vertex_buffer_(vertex_buffer::create(data, length))
	{
		CITADEL_ASSERT(vertex_array_, "Failed to create vertex array");
		CITADEL_ASSERT(vertex_buffer_, "Failed to create vertex buffer");

		if (vertex_array_) {
			vertex_array_->bind();
			vertex_array_->add_buffer(vertex_buffer_);
			vertex_array_->unbind();
		}
	}

	mesh::~mesh() {
		CITADEL_ASSERT(vertex_buffer_, "Vertex buffer is null");
		vertex_buffer_->unbind();

		CITADEL_ASSERT(vertex_array_, "Vertex array is null");
		vertex_array_->unbind();
	}

	void mesh::bind() {
		vertex_array_->bind();
	}

	void mesh::unbind() {
		vertex_array_->unbind();
	}

	vertex_array& mesh::get_vertex_array() const {
		CITADEL_ASSERT(vertex_array_, "Vertex array is null");
		return *vertex_array_;
	}

	vertex_buffer& mesh::get_vertex_buffer() const {
		CITADEL_ASSERT(vertex_buffer_, "Vertex buffer is null");
		return *vertex_buffer_;
	}
}
