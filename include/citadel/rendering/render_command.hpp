// File:       render_command.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/rendering/rendering_api.hpp"
#include "citadel/rendering/rendering_api_type.hpp"

#include "citadel/rendering/vertices/vertex_array.hpp"

namespace citadel {
	class exported render_command {
	public:
		nodisc static rendering_api_type get_api();
		static void set_api(rendering_api_type value);

		static void draw_indexed(const std::shared_ptr<vertex_array>& vertex_array, std::size_t vertex_count);
		static void draw_indexed(const std::shared_ptr<vertex_array>& vertex_array);

		static void draw_lines(const std::shared_ptr<vertex_array>& vertex_array, std::size_t vertex_count);
		static void draw_lines(const std::shared_ptr<vertex_array>& vertex_array);

		static void set_line_width(float value);
		nodisc static float get_line_width() noexcept;

	private:
		static std::unique_ptr<rendering_api> rendering_api_;
		static float line_width_;
	};
}
