// File:        opengl_viewport.h
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

#pragma once

#ifndef CITADEL_OPENGL_VIEWPORT_H
#define CITADEL_OPENGL_VIEWPORT_H

#include "citadel/export.h"
#include "citadel/platforms.h"

#include "citadel/rendering/viewport.h"

#if CITADEL_PLATFORM_WINDOWS
	#include <Windows.h>
	#include <gl/GL.h>
#endif

namespace citadel
{
	class opengl_viewport : public viewport
	{
	public:
		opengl_viewport(dimension_t x, dimension_t y, dimension_t width, dimension_t height)
			: viewport(x, y, width, height) { }

		virtual ~opengl_viewport() override = default;

	private:
		CITADEL_API virtual void _bind() const override;
		CITADEL_API virtual void _clear() const override;
	};
}

#endif
