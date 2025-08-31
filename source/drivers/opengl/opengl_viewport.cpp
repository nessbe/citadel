// File:        opengl_viewport.cpp
// Project:     citadel
// Repository:  https://github.com/nessbe/citadel
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

#include "citadelpch.h"
#include "drivers/opengl/opengl_viewport.h"

namespace citadel
{
	void opengl_viewport::_bind() const
	{
		dimension_t width = get_width();
		dimension_t height = get_height();

		glViewport(0, 0, static_cast<GLsizei>(width), static_cast<GLsizei>(height));

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		double window_aspect = static_cast<double>(width) / static_cast<double>(height);

		if (window_aspect >= 1.0)
		{
			glOrtho(-window_aspect, window_aspect, -1.0, 1.0, -1.0, 1.0);
		}
		else
		{
			glOrtho(-1.0, 1.0, -1.0 / window_aspect, 1.0 / window_aspect, -1.0, 1.0);
		}

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void opengl_viewport::_clear() const
	{
		float clear_red, clear_green, clear_blue, clear_alpha;
		get_clear_color().to_float(clear_red, clear_green, clear_blue, clear_alpha);

		glClearColor(clear_red, clear_green, clear_blue, clear_alpha);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}
