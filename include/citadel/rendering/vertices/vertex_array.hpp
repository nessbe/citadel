// File:       vertex_array.hpp
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

#pragma once

#include <memory>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/memory/reference.hpp"

#include "citadel/rendering/rendering_api_type.hpp"

#include "citadel/rendering/indices/index_buffer.hpp"

#include "citadel/rendering/vertices/vertex_buffer.hpp"

namespace citadel {
	class CITADEL_API vertex_array {
	public:
		CITADEL_NODISCARD static reference<vertex_array> create(rendering_api_type api);
		CITADEL_NODISCARD static reference<vertex_array> create();

		vertex_array() = default;
		virtual ~vertex_array() = default;

		vertex_array(const vertex_array&) = delete;
		vertex_array& operator=(const vertex_array&) = delete;

		void bind() const;
		void unbind() const;

		void add_vertex_buffer(const reference<vertex_buffer>& buffer);

		CITADEL_NODISCARD index_buffer& index_buffer() const;
		void set_index_buffer(const reference<class index_buffer>& buffer);

	private:
		reference<class index_buffer> index_buffer_;

	private:
		virtual void _bind() const = 0;
		virtual void _unbind() const = 0;

		virtual void _add_vertex_buffer(const reference<vertex_buffer>& buffer) = 0;
		virtual void _set_index_buffer(const reference<class index_buffer>& buffer) = 0;
	};
}
