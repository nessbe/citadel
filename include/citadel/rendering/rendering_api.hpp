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

#include "citadel/rendering/vertices/vertex_array.hpp"

CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_PADDING)

namespace citadel {
	class api rendering_api {
	public:
		enum class type {
			none = 0,
			opengl
		};

	public:
		nodisc static std::unique_ptr<rendering_api> create(type type);

		rendering_api(type type);
		virtual ~rendering_api() = default;

		void draw_indexed(const std::unique_ptr<vertex_array>& vertex_array, std::size_t vertex_count);
		void draw_indexed(const std::unique_ptr<vertex_array>& vertex_array);

		void draw_lines(const std::unique_ptr<vertex_array>& vertex_array, std::size_t vertex_count);
		void draw_lines(const std::unique_ptr<vertex_array>& vertex_array);

		void set_line_width(float value);

	private:
		type type_;

	private:
		virtual void _draw_indexed(const std::unique_ptr<vertex_array>& vertex_array, std::size_t vertex_count) = 0;
		virtual void _draw_lines(const std::unique_ptr<vertex_array>& vertex_array, std::size_t vertex_count) = 0;
		virtual void _set_line_width(float value) = 0;
	};
}

CITADEL_IGNORE_WARNING_POP()
