// File:       index_buffer.cpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#include "citadel/pch.hpp"
#include "citadel/rendering/vertices/index_buffer.hpp"

namespace citadel {
	index_buffer::index_buffer(std::size_t size)
		: size_(size) { }

	void index_buffer::bind() {
		_bind();
	}

	void index_buffer::unbind() {
		_unbind();
	}

	std::size_t index_buffer::size() const noexcept {
		return size_;
	}
}
