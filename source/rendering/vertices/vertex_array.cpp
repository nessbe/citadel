// File:       vertex_array.cpp
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
#include "citadel/rendering/vertices/vertex_array.hpp"

#include "citadel/rendering/render_command.hpp"

#include "citadel/drivers/opengl/opengl_vertex_array.hpp"

namespace citadel {
CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_UNREACHABLE_CODE)

	std::unique_ptr<vertex_array> vertex_array::create(rendering_api_type api) {
		switch (api) {
		case rendering_api_type::none:
			CITADEL_PANIC("Rendering API cannot be none");
			return nullptr;

		case rendering_api_type::opengl:
			return std::make_unique<opengl_vertex_array>();
		}

		CITADEL_PANIC("Unknown rendering API");
		return nullptr;
	}

CITADEL_IGNORE_WARNING_POP()

	std::unique_ptr<vertex_array> vertex_array::create() {
		return create(render_command::get_api());	
	}

	void vertex_array::bind() {
		_bind();
	}

	void vertex_array::unbind() {
		_unbind();
	}

	void vertex_array::add_vertex_buffer(const std::unique_ptr<vertex_buffer>& buffer) {
		_add_vertex_buffer(buffer);
	}

	index_buffer& vertex_array::get_index_buffer() const {
		CITADEL_ASSERT(index_buffer_, "Index buffer is null");
		return *index_buffer_;
	}

	void vertex_array::set_index_buffer(const std::shared_ptr<index_buffer>& buffer) {
		_set_index_buffer(buffer);
		index_buffer_ = buffer;
	}
}
