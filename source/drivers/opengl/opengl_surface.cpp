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

CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_SPECTRE)

	void opengl_surface::_bind() {
		dimension width = get_width();
		dimension height = get_height();

		if (width == 0 || height == 0) {
			return;
		}

		glViewport(0, 0, static_cast<GLsizei>(width), static_cast<GLsizei>(height));

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		double aspect_ratio = static_cast<double>(width) / static_cast<double>(height);

		double half_width = 1.0;
		double half_height = 1.0 / aspect_ratio;

		glOrtho(-half_width, half_width, -half_height, half_height, -1.0, 1.0);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

CITADEL_IGNORE_WARNING_POP()

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

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void opengl_surface::_present() { }

	void opengl_surface::_set_x(dimension value) { }
	void opengl_surface::_set_y(dimension value) { }
	void opengl_surface::_set_width(dimension value) { }
	void opengl_surface::_set_height(dimension value) { }
	void opengl_surface::_set_clear_color(color value) { }
}
