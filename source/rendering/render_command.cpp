// File:       render_command.cpp
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
#include "citadel/rendering/render_command.hpp"

namespace citadel {
	static rendering_api_type default_api_ = rendering_api_type::opengl;

	std::unique_ptr<rendering_api> render_command::rendering_api_ = rendering_api::create(default_api_);
	float render_command::line_width_ = 1.0f;

	rendering_api_type render_command::get_api() {
		return rendering_api_->get_api();
	}

	void render_command::set_api(rendering_api_type value) {
		rendering_api_ = rendering_api::create(value);
		CITADEL_ASSERT(rendering_api_, "Failed to create rendering API");
	}

	void render_command::draw_indexed(const std::shared_ptr<vertex_array>& vertex_array, std::size_t vertex_count) {
		rendering_api_->draw_indexed(vertex_array, vertex_count);
	}

	void render_command::draw_indexed(const std::shared_ptr<vertex_array>& vertex_array) {
		rendering_api_->draw_indexed(vertex_array);
	}

	void render_command::draw_lines(const std::shared_ptr<vertex_array>& vertex_array, std::size_t vertex_count) {
		rendering_api_->draw_lines(vertex_array, vertex_count);
	}

	void render_command::draw_lines(const std::shared_ptr<vertex_array>& vertex_array) {
		rendering_api_->draw_lines(vertex_array);
	}

	void render_command::set_line_width(float value) {
		rendering_api_->set_line_width(value);
		line_width_ = value;
	}

	float render_command::get_line_width() noexcept {
		return line_width_;
	}
}
