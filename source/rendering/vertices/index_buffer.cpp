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

#include "citadel/rendering/render_command.hpp"

#include "citadel/drivers/opengl/opengl_index_buffer.hpp"

namespace citadel {
CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_SPECTRE)

	std::vector<index_buffer::index> index_buffer::linear(std::size_t size) {
		std::vector<index_buffer::index> indices(size);
		for (std::size_t i = 0; i < size; i++) {
			indices[i] = static_cast<index_buffer::index>(i);
		}
		return indices;
	}

CITADEL_IGNORE_WARNING_POP()

CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_UNREACHABLE_CODE)

	std::shared_ptr<index_buffer> index_buffer::create(rendering_api_type api, const std::vector<index>& indices) {
		switch (api) {
		case rendering_api_type::none:
			CITADEL_PANIC("Rendering API cannot be none");
			return nullptr;

		case rendering_api_type::opengl:
			return std::make_unique<opengl_index_buffer>(indices);
		}

		CITADEL_PANIC("Unknown rendering API");
		return nullptr;
	}

	std::shared_ptr<index_buffer> index_buffer::create(rendering_api_type api, const index* data, std::size_t size) {
		switch (api) {
		case rendering_api_type::none:
			CITADEL_PANIC("Rendering API cannot be none");
			return nullptr;

		case rendering_api_type::opengl:
			return std::make_unique<opengl_index_buffer>(data, size);
		}

		CITADEL_PANIC("Unknown rendering API");
		return nullptr;
	}

CITADEL_IGNORE_WARNING_POP()

	std::shared_ptr<index_buffer> index_buffer::create(const std::vector<index>& indices) {
		return create(render_command::get_api(), indices);
	}

	std::shared_ptr<index_buffer> index_buffer::create(const index* data, std::size_t size) {
		return create(render_command::get_api(), data, size);
	}

	index_buffer::index_buffer(const std::vector<index>& indices)
		: indices_(indices) { }

	index_buffer::index_buffer(const index* data, std::size_t size)
		: indices_(data, data + size) { }

	void index_buffer::bind() {
		_bind();
	}

	void index_buffer::unbind() {
		_unbind();
	}

	void index_buffer::set_data(const std::vector<index>& indices) {
		_set_data(indices.data(), indices.size());
		indices_ = indices;
	}

	void index_buffer::set_data(const index* data, std::size_t size) {
		_set_data(data, size);
		indices_.assign(data, data + size);
	}

	index_buffer::index* index_buffer::data() noexcept {
		return indices_.data();
	}

	const index_buffer::index* index_buffer::data() const noexcept {
		return indices_.data();
	}

	std::size_t index_buffer::size() const noexcept {
		return indices_.size();
	}
}
