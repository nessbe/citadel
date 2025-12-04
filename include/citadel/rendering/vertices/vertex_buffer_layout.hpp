// File:       vertex_buffer_layout.hpp
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

#pragma once

#include <initializer_list>
#include <string>
#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/utility.hpp"
#include "citadel/warnings.hpp"

#include "citadel/rendering/shaders/shader_data_type.hpp"

#include "citadel/rendering/vertices/vertex_buffer_element.hpp"

namespace citadel {
	class exported vertex_buffer_layout {
	public:
		nodisc static vertex_buffer_layout begin();
		nodisc static vertex_buffer_layout begin(std::size_t size);

		vertex_buffer_layout() = default;

		vertex_buffer_layout(std::size_t size);
		vertex_buffer_layout(std::initializer_list<vertex_buffer_element> elements);

		nodisc vertex_buffer_layout& add(const vertex_buffer_element& element);
		nodisc vertex_buffer_layout& add(const std::string& name, shader_data_type data_type, bool normalized);
		nodisc vertex_buffer_layout& add(const std::string& name, shader_data_type data_type);

		vertex_buffer_layout& end();

		nodisc const std::vector<vertex_buffer_element>& get_elements() const noexcept;
		nodisc std::size_t get_stride() const noexcept;

	private:
		std::vector<vertex_buffer_element> elements_;
		std::size_t stride_ = 0;

	private:
		void update_layout();
	};
}
