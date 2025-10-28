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

#include "citadel/display/window.hpp"

namespace citadel {
	std::unique_ptr<rendering_context> rendering_context::create() {
		return nullptr;
	}

	rendering_context::~rendering_context() {
		destroy();
	}

	void rendering_context::construct(window* window) {
		_construct(window);
	}

	void rendering_context::destroy() {
		_destroy();
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
