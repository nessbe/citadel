// File:       mesh.hpp
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

#pragma once

#include <memory>
#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/rendering/vertices/index_buffer.hpp"
#include "citadel/rendering/vertices/vertex.hpp"
#include "citadel/rendering/vertices/vertex_array.hpp"
#include "citadel/rendering/vertices/vertex_buffer.hpp"

namespace citadel {
	class api mesh {
	public:
		mesh(const std::vector<vertex>& vertices, const std::vector<index_buffer::index>& indices);
		mesh(const void* data, std::size_t size, const std::vector<index_buffer::index>& indices);

		~mesh();

		mesh(const mesh&) = delete;
		mesh& operator=(const mesh&) = delete;

		void bind();
		void unbind();

		void render();

		nodisc vertex_array& get_vertex_array() const;
		nodisc vertex_buffer& get_vertex_buffer() const;
		nodisc index_buffer& get_index_buffer() const;

	private:
		std::unique_ptr<vertex_array> vertex_array_;
		std::unique_ptr<vertex_buffer> vertex_buffer_;
		std::shared_ptr<index_buffer> index_buffer_;
	};
}
