// File:        vertex_buffer.cpp
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
#include "citadel/rendering/retained/vertex_buffer.h"

namespace citadel
{
	void vertex_buffer::bind()
	{
		_bind();
	}

	void vertex_buffer::unbind()
	{
		_unbind();
	}

	std::vector<vertex_buffer::data_t> vertex_buffer::data() const
	{
		return data_.data();
	}

	vertex_buffer::data_t* vertex_buffer::raw_data() const
	{
		return data_.raw_data();
	}

	std::size_t vertex_buffer::size() const noexcept
	{
		return data_.size();
	}

	std::size_t vertex_buffer::memory_size() const noexcept
	{
		return data_.memory_size();
	}

	vertex_buffer::buffer_t& vertex_buffer::get_data()
	{
		return data_;
	}

	void vertex_buffer::set_data(buffer_t data)
	{
		data_ = std::move(data);
		_set_data(data_);
	}

	const vertex_buffer_layout& vertex_buffer::get_layout() const noexcept
	{
		return layout_;
	}

	void vertex_buffer::set_layout(const vertex_buffer_layout& layout) noexcept
	{
		layout_ = layout;
	}
}
