// File:       vertex_buffer_element.cpp
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
#include "citadel/rendering/vertices/vertex_buffer_element.hpp"

namespace citadel {
	vertex_buffer_element::vertex_buffer_element(const std::string& name, shader_data_type::enumeration data_type, bool is_normalized)
		: name(name), data_type(data_type), is_normalized(is_normalized), offset_(0) { }

	std::size_t vertex_buffer_element::size() const noexcept {
		return shader_data_type::size(data_type);
	}

	std::size_t vertex_buffer_element::offset() const noexcept {
		return offset_;
	}
}
