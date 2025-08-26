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
#include <new>

#include "citadel/assert.h"
#include "citadel/attributes.h"
#include "citadel/exceptions.h"

namespace Citadel
{
	template<typename T>
	class Buffer
	{
	public:
		Buffer(std::size_t size, std::size_t offset)
			: size_(size), offset_(offset), stride_(sizeof(T) + offset), raw_memory_(nullptr)
		{
			CITADEL_EXCEPT_INVALID_ARGUMENT(size > 0, "Buffer size must be greater than zero");
			construct();
		}

		Buffer(std::size_t size)
			: Buffer(size, 0) { }

		Buffer(const Buffer&) = delete;
		Buffer& operator=(const Buffer&) = delete;

		Buffer(Buffer&& other) noexcept :
			size_(other.size_),
			offset_(other.offset_),
			stride_(other.stride_),
			raw_memory_(other.raw_memory_)
		{
			other.raw_memory_ = nullptr;
			other.size_ = other.offset_ = other.stride_ = 0;
		}

		Buffer& operator=(Buffer&& other) noexcept
		{
			if (this != &other)
			{
				destroy();

				size_ = other.size_;
				offset_ = other.offset_;
				stride_ = other.stride_;
				raw_memory_ = other.raw_memory_;

				other.raw_memory_ = nullptr;
				other.size_ = other.offset_ = other.stride_ = 0;
			}
		}

		~Buffer()
		{
			destroy();
		}

		CITADEL_INLINE T& operator[](const std::size_t index)
		{
			CITADEL_EXCEPT_OUT_OF_RANGE(index < size_, "Buffer index is out of range");
			return get(index);
		}

		CITADEL_INLINE const T& operator[](const std::size_t index) const
		{
			CITADEL_EXCEPT_OUT_OF_RANGE(index < size_, "Buffer index is out of range");
			return get(index);
		}

		CITADEL_INLINE std::size_t size() const noexcept
		{
			return size_;
		}

		CITADEL_INLINE std::size_t offset() const noexcept
		{
			return offset_;
		}

		CITADEL_INLINE std::size_t stride() const noexcept
		{
			return stride_;
		}

		CITADEL_INLINE std::size_t memory_size() const noexcept
		{
			return size_ * stride_;
		}

	private:
		std::size_t size_, offset_, stride_;
		void* raw_memory_;

	private:
		CITADEL_INLINE void* get_raw_pointer(std::size_t index) const
		{
			return static_cast<char*>(raw_memory_) + index * stride_;
		}

		CITADEL_INLINE T& get(std::size_t index) const
		{
			return *reinterpret_cast<T*>(get_raw_pointer(index));
		}

		void construct()
		{
			raw_memory_ = ::operator new(size_ * stride_);

			for (std::size_t i = 0; i < size_; i++)
			{
				new (get_raw_pointer(i)) T();
			}
		}

		void destroy()
		{
			for (std::size_t i = 0; i < size_; i++)
			{
				get(i).~T();
			}

			::operator delete(raw_memory_);
		}
	};
}

#endif
