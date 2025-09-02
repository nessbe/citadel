// File:        vertex_buffer.h
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

#pragma once

#ifndef CITADEL_VERTEX_BUFFER_H
#define CITADEL_VERTEX_BUFFER_H

#include <cstddef>
#include <type_traits>
#include <vector>

#include "citadel/attributes.h"
#include "citadel/export.h"

#include "citadel/memory/buffer.h"

#include "citadel/rendering/retained/vertex_buffer_layout.h"

namespace citadel
{
	class vertex_buffer
	{
	public:
		using data_t = const void*;
		using buffer_t = buffer<data_t>;

	public:
		vertex_buffer(std::size_t size)
			: data_(size) { }

		vertex_buffer(buffer_t&& vertices)
			: data_(std::move(vertices)) { }

		virtual ~vertex_buffer() = default;

		CITADEL_API CITADEL_INLINE void bind();
		CITADEL_API CITADEL_INLINE void unbind();

		CITADEL_API CITADEL_GETTER std::vector<data_t> data() const;
		CITADEL_API CITADEL_GETTER data_t* raw_data() const;

		CITADEL_API CITADEL_GETTER std::size_t size() const noexcept;
		CITADEL_API CITADEL_GETTER std::size_t memory_size() const noexcept;

		CITADEL_API CITADEL_GETTER buffer_t& get_data();
		CITADEL_API CITADEL_SETTER void set_data(buffer_t data);

		CITADEL_API CITADEL_GETTER const vertex_buffer_layout& get_layout() const noexcept;
		CITADEL_API CITADEL_SETTER void set_layout(const vertex_buffer_layout& layout) noexcept;

	private:
		buffer_t data_;
		vertex_buffer_layout layout_;

	private:
		virtual void _bind() = 0;
		virtual void _unbind() = 0;

		virtual void _set_data(const buffer_t& data) = 0;
	};
}

#endif
