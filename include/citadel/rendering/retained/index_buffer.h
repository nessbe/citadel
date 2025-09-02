// File:        index_buffer.h
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

#ifndef CITADEL_INDEX_BUFFER_H
#define CITADEL_INDEX_BUFFER_H

#include <cinttypes>
#include <cstddef>

#include "citadel/attributes.h"
#include "citadel/export.h"

#include "citadel/memory/buffer.h"

#include "drivers/opengl/opengl.h"

namespace citadel
{
	class index_buffer
	{
	public:
		using index_t = std::uint32_t;
		using buffer_t = buffer<index_t>;

	public:
		index_buffer(std::size_t size)
			: indices_(size) { }

		index_buffer(buffer_t&& indices)
			: indices_(std::move(indices)) { }

		virtual ~index_buffer() = default;

		CITADEL_API CITADEL_INLINE void bind();
		CITADEL_API CITADEL_INLINE void unbind();

		CITADEL_API CITADEL_GETTER std::vector<index_t> data() const;
		CITADEL_API CITADEL_GETTER index_t* raw_data() const;

		CITADEL_API CITADEL_GETTER std::size_t size() const noexcept;
		CITADEL_API CITADEL_GETTER std::size_t memory_size() const noexcept;

		CITADEL_API CITADEL_GETTER buffer_t& get_indices();
		CITADEL_API CITADEL_SETTER void set_indices(buffer_t indices);

	private:
		buffer_t indices_;

	private:
		virtual void _bind() = 0;
		virtual void _unbind() = 0;

		virtual void _set_indices(const buffer_t& indices) = 0;
	};
}

#endif
