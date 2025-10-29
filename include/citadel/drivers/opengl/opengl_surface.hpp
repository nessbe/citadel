// File:       opengl_surface.hpp
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

#include "citadel/export.hpp"

#include "citadel/display/surface.hpp"

namespace citadel {
	class api opengl_surface : public surface {
	public:
		opengl_surface(dimension x, dimension y, dimension width, dimension height, color clear_color);
		opengl_surface(dimension width, dimension height, color clear_color);

		virtual ~opengl_surface() override = default;

	private:
		virtual void _bind() override;
		virtual void _unbind() override;

		virtual void _clear() override;
		virtual void _present() override;

		virtual void _set_x(dimension value) override;
		virtual void _set_y(dimension value) override;
		virtual void _set_width(dimension value) override;
		virtual void _set_height(dimension value) override;
		virtual void _set_clear_color(color value) override;
	};
}
