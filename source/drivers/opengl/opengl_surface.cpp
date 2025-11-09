// File:       opengl_surface.cpp
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
#include "citadel/drivers/opengl/opengl_surface.hpp"

namespace citadel {
	opengl_surface::opengl_surface(dimension x, dimension y, dimension width, dimension height, color clear_color)
		: surface(x, y, width, height, clear_color) { }

	opengl_surface::opengl_surface(dimension width, dimension height, color clear_color)
		: surface(width, height, clear_color) { }

	void opengl_surface::_bind() {
		glViewport(
			0,
			0,
			static_cast<GLint>(get_width()),
			static_cast<GLint>(get_height())
		);
	}

	void opengl_surface::_unbind() { }

	void opengl_surface::_clear() {
		color::channel_normalized red, green, blue, alpha;
		get_clear_color().get_channels_normalized(red, green, blue, alpha);

		glClearColor(
			static_cast<GLclampf>(red),
			static_cast<GLclampf>(green),
			static_cast<GLclampf>(blue),
			static_cast<GLclampf>(alpha)
		);

		glClear(GL_COLOR_BUFFER_BIT);
	}

	void opengl_surface::_present() { }

	void opengl_surface::_set_x(dimension value) { }
	void opengl_surface::_set_y(dimension value) { }
	void opengl_surface::_set_width(dimension value) { }
	void opengl_surface::_set_height(dimension value) { }
	void opengl_surface::_set_clear_color(color value) { }
}
