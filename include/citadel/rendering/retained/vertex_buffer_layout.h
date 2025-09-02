// File:        vertex_buffer_layout.h
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
//     - https://github.com/TheCherno/Hazel/blob/master/Hazel/src/Hazel/Renderer/Buffer.h

#pragma once

#ifndef CITADEL_VERTEX_BUFFER_LAYOUT_H
#define CITADEL_VERTEX_BUFFER_LAYOUT_H

#include <cstddef>
#include <initializer_list>
#include <vector>

#include "citadel/attributes.h"
#include "citadel/export.h"
#include "citadel/utilities.h"

#include "citadel/rendering/retained/vertex_buffer_element.h"

namespace citadel
{
	class vertex_buffer_layout
	{
	public:
		vertex_buffer_layout()
			: stride_(0) { }

		CITADEL_API vertex_buffer_layout(std::initializer_list<vertex_buffer_element> elements);

		~vertex_buffer_layout() = default;

		CITADEL_API CITADEL_GETTER std::size_t get_stride() const noexcept;

		CITADEL_ITERATOR_WRAPPER(elements_);

	private:
		std::vector<vertex_buffer_element> elements_;
		std::size_t stride_;

	private:
		CITADEL_API void construct();
	};
}

#endif
