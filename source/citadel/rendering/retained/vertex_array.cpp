// File:        vertex_array.cpp
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

#include "citadelpch.h"
#include "citadel/rendering/retained/vertex_array.h"

#include "citadel/rendering/retained/vertex_buffer_element.h"
#include "citadel/rendering/retained/vertex_buffer_layout.h"

namespace citadel
{
	void vertex_array::bind()
	{
		_bind();
		is_bound_ = true;
	}

	void vertex_array::unbind()
	{
		_unbind();
		is_bound_ = false;
	}

	bool vertex_array::is_bound() const noexcept
	{
		return is_bound_;
	}

	const reference<index_buffer>& vertex_array::get_index_buffer() const noexcept
	{
		return index_buffer_;
	}

	void vertex_array::set_index_buffer(const reference<index_buffer>& index_buffer)
	{
		bind();
		index_buffer->bind();

		_set_index_buffer(index_buffer);

		index_buffer_ = index_buffer;
	}

	const std::vector<reference<vertex_buffer>>& vertex_array::get_vertex_buffers() const noexcept
	{
		return vertex_buffers_;
	}

	void vertex_array::add_vertex_buffer(const reference<vertex_buffer>& vertex_buffer)
	{
		bind();
		vertex_buffer->bind();

		_add_vertex_buffer(vertex_buffer, vertex_buffers_.size());

		vertex_buffers_.push_back(vertex_buffer);
	}

	void vertex_array::clear()
	{
		index_buffer_ = nullptr;
		vertex_buffers_.clear();
	}
}
