// File:        vertex_array.h
// Project:     citadel
// Repository:  https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// For more details, see the LICENSE file at the root of the project.

// This file is highly inspired by this file in the Hazel GitHub repository by TheCherno:
//     - https://github.com/TheCherno/Hazel/blob/master/Hazel/src/Platform/OpenGL/OpenGLVertexArray.h

#pragma once

#ifndef CITADEL_VERTEX_ARRAY_H
#define CITADEL_VERTEX_ARRAY_H

#include <vector>

#include "citadel/attributes.h"
#include "citadel/export.h"

#include "citadel/memory/reference.h"

#include "citadel/rendering/retained/index_buffer.h"
#include "citadel/rendering/retained/vertex_buffer.h"

namespace citadel
{
	class vertex_array
	{
	public:
		vertex_array() = default;
		virtual ~vertex_array() = default;

		CITADEL_API void bind();
		CITADEL_API void unbind();

		CITADEL_API CITADEL_GETTER bool is_bound() const noexcept;

		CITADEL_API CITADEL_GETTER const reference<index_buffer>& get_index_buffer() const noexcept;
		CITADEL_API void set_index_buffer(const reference<index_buffer>& index_buffer);

		CITADEL_API CITADEL_GETTER const std::vector<reference<vertex_buffer>>& get_vertex_buffers() const noexcept;
		CITADEL_API void add_vertex_buffer(const reference<vertex_buffer>& vertex_buffer);

		CITADEL_API void clear();

	private:
		bool is_bound_ = false;

		reference<index_buffer> index_buffer_;
		std::vector<reference<vertex_buffer>> vertex_buffers_;

	private:
		virtual void _bind() = 0;
		virtual void _unbind() = 0;

		virtual void _set_index_buffer(const reference<index_buffer>& index_buffer) = 0;
		virtual void _add_vertex_buffer(const reference<vertex_buffer>& vertex_buffer, std::size_t vertex_buffer_count) = 0;
	};
}

#endif
