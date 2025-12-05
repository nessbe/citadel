// File:       rendering_api.hpp
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
#include "citadel/warnings.hpp"

#include "citadel/memory/scope.hpp"

#include "citadel/rendering/rendering_api_type.hpp"

#include "citadel/rendering/vertices/vertex_array.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported rendering_api {
	public:
		nodisc static scope<rendering_api> create(rendering_api_type api);

		rendering_api(rendering_api_type api);
		virtual ~rendering_api() = default;

		void draw_indexed(const reference<vertex_array>& vertex_array, std::size_t vertex_count);
		void draw_indexed(const reference<vertex_array>& vertex_array);

		void draw_lines(const reference<vertex_array>& vertex_array, std::size_t vertex_count);
		void draw_lines(const reference<vertex_array>& vertex_array);

		void set_line_width(float value);

		nodisc rendering_api_type get_api() const noexcept;

	private:
		rendering_api_type api_;

	private:
		virtual void _draw_indexed(const reference<vertex_array>& vertex_array, std::size_t vertex_count) = 0;

		virtual void _draw_lines(const reference<vertex_array>& vertex_array, std::size_t vertex_count) = 0;
		virtual void _set_line_width(float value) = 0;
	};
}

CITADEL_WARNING_IGNORE_POP
