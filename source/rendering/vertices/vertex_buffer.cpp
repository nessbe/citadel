// File:       vertex_buffer.cpp
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
#include "citadel/rendering/vertices/vertex_buffer.hpp"

#include "citadel/drivers/opengl/opengl_vertex_buffer.hpp"

namespace citadel {
CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_UNREACHABLE_CODE)

	std::unique_ptr<vertex_buffer> vertex_buffer::create(rendering_api::api api, std::size_t size) {
		switch (api) {
		case rendering_api::api::none:
			CITADEL_PANIC("Rendering API cannot be none");
			return nullptr;

		case rendering_api::api::opengl:
			return std::make_unique<opengl_vertex_buffer>(size);
		}

		CITADEL_PANIC("Unknown rendering API");
		return nullptr;
	}

	std::unique_ptr<vertex_buffer> vertex_buffer::create(rendering_api::api api, const std::vector<vertex>& vertices) {
		switch (api) {
		case rendering_api::api::none:
			CITADEL_PANIC("Rendering API cannot be none");
			return nullptr;

		case rendering_api::api::opengl:
			return std::make_unique<opengl_vertex_buffer>(vertices);
		}

		CITADEL_PANIC("Unknown rendering API");
		return nullptr;
	}

	std::unique_ptr<vertex_buffer> vertex_buffer::create(rendering_api::api api, const void* data, std::size_t size) {
		switch (api) {
		case rendering_api::api::none:
			CITADEL_PANIC("Rendering API cannot be none");
			return nullptr;

		case rendering_api::api::opengl:
			return std::make_unique<opengl_vertex_buffer>(data, size);
		}

		CITADEL_PANIC("Unknown rendering API");
		return nullptr;
	}

CITADEL_IGNORE_WARNING_POP()

	vertex_buffer::vertex_buffer(std::size_t size)
		: size_(size) { }

	void vertex_buffer::bind() {
		_bind();
	}

	void vertex_buffer::unbind() {
		_unbind();
	}

	void vertex_buffer::set_data(const std::vector<vertex>& vertices) {
		_set_data(vertices.data(), vertices.size() * sizeof(vertex));
	}

	std::size_t vertex_buffer::size() const noexcept {
		return size_;
	}
}
