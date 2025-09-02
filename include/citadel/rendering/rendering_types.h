// File:        rendering_types.h
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

#ifndef CITADEL_RENDERING_TYPES_H
#define CITADEL_RENDERING_TYPES_H

#include "citadel/rendering/rendering_context.h"

#include "drivers/opengl/opengl_context.h"
#include "drivers/opengl/opengl_viewport.h"

#include "drivers/opengl/retained/opengl_index_buffer.h"
#include "drivers/opengl/retained/opengl_vertex_array.h"
#include "drivers/opengl/retained/opengl_vertex_buffer.h"

namespace citadel
{
#ifdef CITADEL_GRAPHICS_API_OPENGL
	using default_index_buffer = opengl_index_buffer;
	using default_rendering_context = opengl_context;
	using default_vertex_array = opengl_vertex_array;
	using default_vertex_buffer = opengl_vertex_buffer;
	using default_viewport = opengl_viewport;
#else
	#error Citadel does not support the given rendering API yet
#endif
}

#endif
