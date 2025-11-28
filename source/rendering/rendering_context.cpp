// File:       rendering_context.cpp
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
#include "citadel/rendering/rendering_context.hpp"

#include "citadel/core/display/window.hpp"

#include "citadel/rendering/render_command.hpp"

#include "citadel/drivers/opengl/opengl_context.hpp"

namespace citadel {
CITADEL_IGNORE_WARNING_PUSH();
CITADEL_IGNORE_WARNING(CITADEL_WARNING_UNREACHABLE_CODE);

	std::unique_ptr<rendering_context> rendering_context::create(rendering_api_type api, window* window) {
		switch (api) {
		case rendering_api_type::none:
			CITADEL_PANIC("Rendering API cannot be none");
			return nullptr;

		case rendering_api_type::opengl:
			return std::make_unique<opengl_context>(window);
		}

		CITADEL_PANIC("Unknown rendering API");
		return nullptr;
	}

CITADEL_IGNORE_WARNING_POP();

	std::unique_ptr<rendering_context> rendering_context::create(window* window) {
		return create(render_command::get_api(), window);
	}

	void rendering_context::bind() {
		_bind();
	}

	void rendering_context::unbind() {
		_unbind();
	}

	void rendering_context::swap_buffers() {
		_swap_buffers();
	}
}
