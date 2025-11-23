// File:       rendering_context.hpp
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

#include <memory>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/rendering/rendering_api_type.hpp"

namespace citadel {
	class window;

	class exported rendering_context {
	public:
		nodisc static std::unique_ptr<rendering_context> create(rendering_api_type api, window* window);
		nodisc static std::unique_ptr<rendering_context> create(window* window);

		virtual ~rendering_context() = default;

		void bind();
		void unbind();

		void swap_buffers();

	private:
		virtual void _bind() = 0;
		virtual void _unbind() = 0;

		virtual void _swap_buffers() = 0;
	};
}
