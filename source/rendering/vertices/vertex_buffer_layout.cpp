// File:       vertex_buffer_layout.cpp
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
#include "citadel/rendering/vertices/vertex_buffer_layout.hpp"

namespace citadel {
	vertex_buffer_layout vertex_buffer_layout::begin() {
		return vertex_buffer_layout();
	}

	vertex_buffer_layout vertex_buffer_layout::begin(std::size_t size) {
		return vertex_buffer_layout(size);
	}

	vertex_buffer_layout::vertex_buffer_layout(std::size_t size)
		: stride_(0)
	{
		elements_.reserve(size);
	}

	vertex_buffer_layout::vertex_buffer_layout(std::initializer_list<vertex_buffer_element> elements)
		: elements_(elements), stride_(0)
	{
		update_layout();
	}

	vertex_buffer_layout& vertex_buffer_layout::add(const vertex_buffer_element& element) {
		elements_.push_back(element);
		return *this;
	}

	vertex_buffer_layout& vertex_buffer_layout::add(const std::string& name, shader_data_type data_type, bool normalized) {
		return add({ name, data_type, normalized });
	}

	vertex_buffer_layout& vertex_buffer_layout::add(const std::string& name, shader_data_type data_type) {
		return add(name, data_type, false);
	}

	vertex_buffer_layout& vertex_buffer_layout::end() {
		update_layout();
		return *this;
	}

	const std::vector<vertex_buffer_element>& vertex_buffer_layout::get_elements() const noexcept {
		return elements_;
	}

	std::size_t vertex_buffer_layout::get_stride() const noexcept {
		return stride_;
	}

	void vertex_buffer_layout::update_layout() {
		std::size_t offset = 0;
		stride_ = 0;

		for (vertex_buffer_element& element : elements_) {
			element.offset_ = offset;
			std::size_t element_size = element.size();

			offset += element_size;
			stride_ += element_size;
		}
	}
}
