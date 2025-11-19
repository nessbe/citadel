// File:       surface.hpp
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

#include <cinttypes>
#include <memory>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/rendering/color.hpp"
#include "citadel/rendering/rendering_api.hpp"

CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported surface {
	public:
		using dimension = std::uint32_t;

	public:
		nodisc static std::unique_ptr<surface> create(rendering_api::api api, dimension x, dimension y, dimension width, dimension height, color clear_color);
		nodisc static std::unique_ptr<surface> create(rendering_api::api api, dimension width, dimension height, color clear_color);

		surface(dimension x, dimension y, dimension width, dimension height, color clear_color);
		surface(dimension width, dimension height, color clear_color);

		virtual ~surface() = default;

		void bind();
		void unbind();

		void clear();
		void present();

		nodisc dimension get_x() const noexcept;
		void set_x(dimension value);

		nodisc dimension get_y() const noexcept;
		void set_y(dimension value);

		nodisc dimension get_width() const noexcept;
		void set_width(dimension value);

		nodisc dimension get_height() const noexcept;
		void set_height(dimension value);

		nodisc color get_clear_color() const noexcept;
		void set_clear_color(color value) noexcept;

		nodisc bool is_bound() const noexcept;

	private:
		dimension x_, y_, width_, height_;
		color clear_color_;

		bool is_bound_ = false;

	private:
		virtual void _bind() = 0;
		virtual void _unbind() = 0;

		virtual void _clear() = 0;
		virtual void _present() = 0;

		virtual void _set_x(dimension value) = 0;
		virtual void _set_y(dimension value) = 0;
		virtual void _set_width(dimension value) = 0;
		virtual void _set_height(dimension value) = 0;
		virtual void _set_clear_color(color value) = 0;
	};
}

CITADEL_IGNORE_WARNING_POP()
