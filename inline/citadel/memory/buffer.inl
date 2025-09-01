// File:        buffer.inl
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

#ifndef CITADEL_BUFFER_INL
#define CITADEL_BUFFER_INL

namespace citadel
{
	template<typename T>
	buffer<T>::buffer(std::size_t size, std::size_t offset)
		: size_(size), offset_(offset), stride_(sizeof(T) + offset), raw_memory_(nullptr)
	{
		construct();
	}

	template<typename T>
	buffer<T>::buffer(buffer<T>&& other) noexcept :
		is_good_(other.is_good_),
		size_(other.size_),
		offset_(other.offset_),
		stride_(other.stride_),
		raw_memory_(other.raw_memory_)
	{
		other.reset();
	}

	template<typename T>
	buffer<T>& buffer<T>::operator=(buffer<T>&& other) noexcept
	{
		if (this != &other)
		{
			destroy();

			is_good_ = other.is_good_;
			size_ = other.size_;
			offset_ = other.offset_;
			stride_ = other.stride_;
			raw_memory_ = other.raw_memory_;

			other.reset();
		}

		return *this;
	}

	template<typename T>
	buffer<T>::~buffer()
	{
		destroy();
	}

	template<typename T>
	T& buffer<T>::operator[](std::size_t index)
	{
		CITADEL_EXCEPT_OUT_OF_RANGE(index < size_, "Index is out of buffer range");
		return get(index);
	}

	template<typename T>
	const T& buffer<T>::operator[](std::size_t index) const
	{
		CITADEL_EXCEPT_OUT_OF_RANGE(index < size_, "Index is out of buffer range");
		return get(index);
	}

	template<typename T>
	std::vector<T> buffer<T>::data() const
	{
		std::vector<T> data;
		data.reserve(size_);

		for (std::size_t i = 0; i < size_; i++)
		{
			data.push_back(get(i));
		}

		return data;
	}

	template<typename T>
	T* buffer<T>::raw_data() const
	{
		return get_pointer(0);
	}

	template<typename T>
	bool buffer<T>::is_good() const noexcept
	{
		return is_good_;
	}

	template<typename T>
	std::size_t buffer<T>::size() const noexcept
	{
		return size_;
	}

	template<typename T>
	std::size_t buffer<T>::offset() const noexcept
	{
		return offset_;
	}

	template<typename T>
	std::size_t buffer<T>::stride() const noexcept
	{
		return stride_;
	}

	template<typename T>
	std::size_t buffer<T>::type_size() const noexcept
	{
		return sizeof(T);
	}

	template<typename T>
	std::size_t buffer<T>::memory_size() const noexcept
	{
		return size_ * stride_;
	}

	template<typename T>
	void buffer<T>::construct()
	{
		raw_memory_ = ::operator new(memory_size());

		for (std::size_t i = 0; i < size_; i++)
		{
			new (get_raw_pointer(i)) T();
		}
	}

	template<typename T>
	void buffer<T>::destroy()
	{
		for (std::size_t i = 0; i < size_; i++)
		{
			get(i).~T();
		}

		::operator delete(raw_memory_);
	}

	template<typename T>
	void buffer<T>::reset()
	{
		is_good_ = false;
		size_ = 0;
		offset_ = 0;
		stride_ = 0;
		raw_memory_ = nullptr;
	}

	template<typename T>
	void* buffer<T>::get_raw_pointer(std::size_t index) const
	{
		return static_cast<char*>(raw_memory_) + index * stride_;
	}

	template<typename T>
	T* buffer<T>::get_pointer(std::size_t index) const
	{
		return reinterpret_cast<T*>(get_raw_pointer(index));
	}

	template<typename T>
	T& buffer<T>::get(std::size_t index) const
	{
		return *get_pointer(index);
	}
}

#endif
