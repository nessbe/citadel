// File:       vertex_array.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/rendering/rendering_api_type.hpp"

#include "citadel/rendering/vertices/index_buffer.hpp"
#include "citadel/rendering/vertices/vertex_buffer.hpp"

namespace citadel {
	class exported vertex_array {
	public:
		nodisc static std::unique_ptr<vertex_array> create(rendering_api_type api);
		nodisc static std::unique_ptr<vertex_array> create();

		vertex_array() = default;
		virtual ~vertex_array() = default;

		vertex_array(const vertex_array&) = delete;
		vertex_array& operator=(const vertex_array&) = delete;

		void bind();
		void unbind();

		void add_vertex_buffer(const std::unique_ptr<vertex_buffer>& buffer);

		nodisc index_buffer& get_index_buffer() const;
		void set_index_buffer(const std::shared_ptr<index_buffer>& buffer);

	private:
		std::shared_ptr<index_buffer> index_buffer_;

	private:
		virtual void _bind() = 0;
		virtual void _unbind() = 0;

		virtual void _add_vertex_buffer(const std::unique_ptr<vertex_buffer>& buffer) = 0;
		virtual void _set_index_buffer(const std::shared_ptr<index_buffer>& buffer) = 0;
	};
}
