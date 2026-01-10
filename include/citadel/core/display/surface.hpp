// File:       surface.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#include <cinttypes>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/memory/scope.hpp"

#include "citadel/rendering/color.hpp"
#include "citadel/rendering/rendering_api_type.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class CITADEL_API surface {
	public:
		using dimension_type = std::uint32_t;

	public:
		CITADEL_NODISCARD static scope<surface> create(rendering_api_type api, dimension_type x, dimension_type y, dimension_type width, dimension_type height, color clear_color);
		CITADEL_NODISCARD static scope<surface> create(rendering_api_type api, dimension_type width, dimension_type height, color clear_color);

		CITADEL_NODISCARD static scope<surface> create(dimension_type x, dimension_type y, dimension_type width, dimension_type height, color clear_color);
		CITADEL_NODISCARD static scope<surface> create(dimension_type width, dimension_type height, color clear_color);

		surface(dimension_type x, dimension_type y, dimension_type width, dimension_type height, color clear_color);
		surface(dimension_type width, dimension_type height, color clear_color);

		virtual ~surface() = default;

		void bind();
		void unbind();

		void clear();
		void present();

		CITADEL_NODISCARD dimension_type get_x() const noexcept;
		void set_x(dimension_type value);

		CITADEL_NODISCARD dimension_type get_y() const noexcept;
		void set_y(dimension_type value);

		CITADEL_NODISCARD dimension_type get_width() const noexcept;
		void set_width(dimension_type value);

		CITADEL_NODISCARD dimension_type get_height() const noexcept;
		void set_height(dimension_type value);

		CITADEL_NODISCARD color get_clear_color() const noexcept;
		void set_clear_color(color value) noexcept;

		CITADEL_NODISCARD bool is_bound() const noexcept;

	private:
		dimension_type x_, y_, width_, height_;
		color clear_color_;

		bool is_bound_ = false;

	private:
		virtual void _bind() = 0;
		virtual void _unbind() = 0;

		virtual void _clear() = 0;
		virtual void _present() = 0;

		virtual void _set_x(dimension_type value) = 0;
		virtual void _set_y(dimension_type value) = 0;

		virtual void _set_width(dimension_type value) = 0;
		virtual void _set_height(dimension_type value) = 0;

		virtual void _set_clear_color(color value) = 0;
	};
}

CITADEL_WARNING_IGNORE_POP
