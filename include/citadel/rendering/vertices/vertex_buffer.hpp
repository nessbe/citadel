// File:       vertex_buffer.hpp
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

#include "citadel/rendering/vertices/vertex.hpp"

namespace citadel {
	class exported vertex_buffer {
	public:
		nodisc static std::unique_ptr<vertex_buffer> create(std::size_t size);
		nodisc static std::unique_ptr<vertex_buffer> create(const std::vector<vertex>& vertices);
		nodisc static std::unique_ptr<vertex_buffer> create(const void* data, std::size_t size);

		vertex_buffer(std::size_t size);
		virtual ~vertex_buffer() = default;

		vertex_buffer(const vertex_buffer&) = delete;
		vertex_buffer& operator=(const vertex_buffer&) = delete;

		void bind();
		void unbind();

		void set_data(const std::vector<vertex>& vertices);

		nodisc std::size_t size() const noexcept;

	private:
		std::size_t size_;

	private:
		virtual void _bind() = 0;
		virtual void _unbind() = 0;

		virtual void _set_data(const void* data, std::size_t size) = 0;
	};
}
