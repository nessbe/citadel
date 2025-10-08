// File:       viewport.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// For more details, see the LICENSE file at the root of the project.

#pragma once

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/memory/scope.hpp"

#include "citadel/rendering/color.hpp"

namespace citadel {
	class viewport {
	public:
		using dimension = unsigned int;

	public:
		CITADEL_API viewport(dimension x, dimension y, dimension width, dimension height, color clear_color);
		CITADEL_API viewport(dimension width, dimension height, color clear_color);

		virtual ~viewport() = default;

		CITADEL_GETTER CITADEL_API dimension get_x() const noexcept;
		CITADEL_SETTER CITADEL_API void set_x(dimension value) noexcept;

		CITADEL_GETTER CITADEL_API dimension get_y() const noexcept;
		CITADEL_SETTER CITADEL_API void set_y(dimension value) noexcept;

		CITADEL_GETTER CITADEL_API dimension get_width() const noexcept;
		CITADEL_SETTER CITADEL_API void set_width(dimension value) noexcept;

		CITADEL_GETTER CITADEL_API dimension get_height() const noexcept;
		CITADEL_SETTER CITADEL_API void set_height(dimension value) noexcept;

		CITADEL_GETTER CITADEL_API color get_clear_color() const noexcept;
		CITADEL_SETTER CITADEL_API void set_clear_color(color value) noexcept;

		CITADEL_NODISCARD CITADEL_API scope<viewport> create(dimension x, dimension y, dimension width, dimension height, color clear_color);
		CITADEL_NODISCARD CITADEL_API scope<viewport> create(dimension width, dimension height, color clear_color);

	private:
		dimension x_, y_, width_, height_;
		color clear_color_;

	private:
		virtual void _set_x(dimension value) noexcept = 0;
		virtual void _set_y(dimension value) noexcept = 0;
		virtual void _set_width(dimension value) noexcept = 0;
		virtual void _set_height(dimension value) noexcept = 0;
		virtual void _set_clear_color(color value) noexcept = 0;
	};
}
