// File:       mesh.cpp
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
#include "citadel/rendering/meshes/mesh.hpp"

#include "citadel/rendering/render_command.hpp"

#include "citadel/rendering/shaders/shader_data_type.hpp"

namespace citadel {
	mesh::mesh(rendering_api_type api, const void* data, std::size_t size, const vertex_buffer_layout& layout, const std::vector<index>& indices) :
		vertex_array_(vertex_array::create(api)),
		vertex_buffer_(vertex_buffer::create(api, data, size, layout)),
		index_buffer_(index_buffer::create(api, indices))
	{
		CITADEL_PRECONDITION(vertex_array_, "Failed to create vertex array");
		CITADEL_PRECONDITION(vertex_buffer_, "Failed to create vertex buffer");
		CITADEL_PRECONDITION(index_buffer_, "Failed to create index buffer");

		vertex_array_->bind();
		vertex_array_->add_vertex_buffer(vertex_buffer_);
		vertex_array_->set_index_buffer(index_buffer_);
		vertex_array_->unbind();
	}

	mesh::mesh(const void* data, std::size_t size, const vertex_buffer_layout& layout, const std::vector<index>& indices)
		: mesh(render_command::get_api(), data, size, layout, indices) { }

	mesh::mesh(rendering_api_type api, const std::vector<vertex>& vertices, const std::vector<index>& indices)
		: mesh(api, vertices.data(), vertices.size() * sizeof(vertex), default_layout_, indices) { }

	mesh::mesh(const std::vector<vertex>& vertices, const std::vector<index>& indices)
		: mesh(vertices.data(), vertices.size() * sizeof(vertex), default_layout_, indices) { }

	mesh::~mesh() {
		vertex_array_->unbind();
	}

	void mesh::bind() {
		vertex_array_->bind();
	}

	void mesh::unbind() {
		vertex_array_->unbind();
	}

	void mesh::render() {
		render_command::draw_indexed(vertex_array());
	}

	vertex_array& mesh::vertex_array() {
		return *vertex_array_;
	}

	vertex_buffer& mesh::vertex_buffer() {
		return *vertex_buffer_;
	}

	index_buffer& mesh::index_buffer() {
		return *index_buffer_;
	}

	vertex_buffer_layout mesh::default_layout_ = vertex_buffer_layout::begin(3)
		.add("position", shader_data_type::type_vec3)
		.add("normal", shader_data_type::type_vec3)
		.add("uv", shader_data_type::type_vec2)
		.end();
}
