// File:        index_buffer.cpp
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
#include "citadel/rendering/retained/index_buffer.h"

namespace citadel
{
	void index_buffer::bind()
	{
		_bind();
	}

	void index_buffer::unbind()
	{
		_unbind();
	}

	std::vector<index_buffer::index_t> index_buffer::data() const
	{
		return indices_.data();
	}

	index_buffer::index_t* index_buffer::raw_data() const
	{
		return indices_.raw_data();
	}

	std::size_t index_buffer::size() const noexcept
	{
		return indices_.size();
	}

	std::size_t index_buffer::memory_size() const noexcept
	{
		return indices_.memory_size();
	}

	index_buffer::buffer_t& index_buffer::get_indices()
	{
		return indices_;
	}

	void index_buffer::set_indices(buffer_t indices)
	{
		indices_ = std::move(indices);
		_set_indices(indices);
	}
}
