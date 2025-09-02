// File:        vertex_buffer_layout.cpp
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
#include "citadel/rendering/retained/vertex_buffer_layout.h"

namespace citadel
{
	vertex_buffer_layout::vertex_buffer_layout(std::initializer_list<vertex_buffer_element> elements)
		: elements_(elements)
	{
		construct();
	}

	std::size_t vertex_buffer_layout::get_stride() const noexcept
	{
		return stride_;
	}

	void vertex_buffer_layout::construct()
	{
		stride_ = 0;

		for (vertex_buffer_element& element : elements_)
		{
			element.offset_ = stride_;
			stride_ += element.size();
		}
	}

}
