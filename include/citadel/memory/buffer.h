// File:        buffer.h
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

#ifndef CITADEL_BUFFER_H
#define CITADEL_BUFFER_H

#include <cstddef>
#include <initializer_list>
#include <new>
#include <vector>

#include "citadel/attributes.h"
#include "citadel/exceptions.h"

namespace citadel
{
	template<typename T>
	class buffer
	{
	public:
		buffer(std::size_t size, std::size_t offset);

		buffer(std::size_t size)
			: buffer(size, 0) { }

		buffer(std::initializer_list<T> data, std::size_t offset);

		buffer(std::initializer_list<T> data)
			: buffer(data, 0) { }

		buffer(buffer<T>&& other) noexcept;
		buffer& operator=(buffer<T>&& other) noexcept;

		~buffer();

		CITADEL_INLINE T& operator[](std::size_t index);
		CITADEL_INLINE const T& operator[](std::size_t index) const;

		std::vector<T> data() const;
		CITADEL_INLINE T* raw_data() const;

		CITADEL_GETTER bool is_good() const noexcept;

		CITADEL_GETTER std::size_t size() const noexcept;
		CITADEL_GETTER std::size_t offset() const noexcept;
		CITADEL_GETTER std::size_t stride() const noexcept;

		CITADEL_GETTER std::size_t type_size() const noexcept;
		CITADEL_GETTER std::size_t memory_size() const noexcept;

	private:
		bool is_good_ = false;
		std::size_t size_, offset_, stride_;
		void* raw_memory_;

	private:
		void construct();
		void construct_from_list(std::initializer_list<T>& list);

		void destroy();
		void reset();

		CITADEL_INLINE void* get_raw_pointer(std::size_t index) const;
		CITADEL_INLINE T* get_pointer(std::size_t index) const;
		CITADEL_INLINE T& get(std::size_t index) const;
	};
}

#include "citadel/memory/buffer.inl"

#endif
