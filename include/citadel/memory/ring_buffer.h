// File:        ring_buffer.h
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

#ifndef CITADEL_RING_BUFFER_H
#define CITADEL_RING_BUFFER_H

#include <cstddef>
#include <type_traits>

#include "citadel/attributes.h"
#include "citadel/exceptions.h"

#include "citadel/memory/buffer.h"

namespace Citadel
{
	template<typename T>
	class RingBuffer
	{
	public:
		RingBuffer(std::size_t capacity, std::size_t offset = 0)
			: buffer_(capacity, offset), head_(0), tail_(0), size_(0), capacity_(capacity)
		{
			CITADEL_EXCEPT_INVALID_ARGUMENT(capacity > 0, "RingBuffer capacity must be greater than zero");
		}

		RingBuffer(RingBuffer&& other) noexcept :
			buffer_(std::move(other.buffer_)),
			head_(other.head_),
			tail_(other.tail_),
			size_(other.size_),
			capacity_(other.capacity_)
		{
			other.head_ = other.tail_ = other.size_ = other.capacity_ = 0;
		}

		RingBuffer& operator=(RingBuffer&& other) noexcept
		{
			if (this != &other)
			{
				buffer_ = std::move(other.buffer_);
				head_ = other.head_;
				tail_ = other.tail_;
				size_ = other.size_;
				capacity_ = other.capacity_;

				other.head_ = other.tail_ = other.size_ = other.capacity_ = 0;
			}

			return  *this;
		}

		RingBuffer(const RingBuffer&) = delete;
		RingBuffer& operator=(const RingBuffer&) = delete;

		~RingBuffer() = default;

		void push_back(const T& item)
		{
			CITADEL_EXCEPT_RUNTIME_ERROR(!is_full(), "RingBuffer is full");

			buffer_[tail_] = item;
			tail_ = (tail_ + 1) % capacity_;
			size_++;
		}

		void push_back(T&& item)
		{
			CITADEL_EXCEPT_RUNTIME_ERROR(!is_full(), "RingBuffer is full");

			buffer_[tail_] = std::move(item);
			tail_ = (tail_ + 1) % capacity_;
			size_++;
		}

		T pop_front()
		{
			CITADEL_EXCEPT_RUNTIME_ERROR(!is_empty(), "RingBuffer is empty");

			T& item = buffer_[head];
			T result = std::move(item);
			head_ = (head_ + 1) % capacity_;

			size_--;
			return result;
		}

		T& peek_front()
		{
			CITADEL_EXCEPT_RUNTIME_ERROR(!is_empty(), "RingBuffer is empty");

			return buffer_[head_];
		}

		const T& peek_front() const
		{
			CITADEL_EXCEPT_RUNTIME_ERROR(!is_empty(), "RingBuffer is empty");

			return buffer_[head_];
		}

		CITADEL_INLINE bool is_empty() const noexcept
		{
			return size_ <= 0;
		}

		CITADEL_INLINE bool is_full() const noexcept
		{
			return size_ >= capacity_;
		}

		CITADEL_INLINE std::size_t size() const noexcept
		{
			return size_;
		}

		CITADEL_INLINE std::size_t capacity() const noexcept
		{
			return capacity_;
		}

	private:
		std::size_t head_, tail_, size_, capacity_;
		Buffer<T> buffer_;
	};
}

#endif
