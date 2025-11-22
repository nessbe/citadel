// File:       vertex_buffer_element.hpp
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

#include <cstddef>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/rendering/shaders/shader_data_type.hpp"

CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_PADDING)

namespace citadel {
	struct exported vertex_buffer_element {
	public:
		friend class vertex_buffer_layout;

	public:
		std::string name;
		shader_data_type::enumeration data_type;
		bool normalized;

	public:
		vertex_buffer_element(const std::string& name, shader_data_type::enumeration data_type, bool normalized);

		nodisc std::size_t size() const noexcept;
		nodisc std::size_t component_count() const noexcept;
		nodisc std::size_t offset() const noexcept;

	private:
		std::size_t offset_;
	};
}

CITADEL_IGNORE_WARNING_POP()
