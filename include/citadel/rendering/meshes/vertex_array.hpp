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

#include "citadel/rendering/meshes/vertex_buffer.hpp"

namespace citadel {
	class vertex_array {
	public:
		static std::unique_ptr<vertex_array> create();

		vertex_array() = default;
		virtual ~vertex_array() = default;

		vertex_array(const vertex_array&) = delete;
		vertex_array& operator=(const vertex_array&) = delete;

		void bind();
		void unbind();

		void add_buffer(const std::unique_ptr<vertex_buffer>& buffer);

	private:
		virtual void _bind() = 0;
		virtual void _unbind() = 0;

		virtual void _add_buffer(const std::unique_ptr<vertex_buffer>& buffer) = 0;
	};
}
