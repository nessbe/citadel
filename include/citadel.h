// File:        citadel.h
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

#ifndef CITADEL_H
#define CITADEL_H

#include "citadel/architectures.h"
#include "citadel/assert.h"
#include "citadel/attributes.h"
#include "citadel/compilers.h"
#include "citadel/exceptions.h"
#include "citadel/export.h"
#include "citadel/platforms.h"
#include "citadel/utilities.h"

#include "citadel/cli/command_line.h"

#include "citadel/core/application.h"
#include "citadel/core/entry_point.h"
#include "citadel/core/main_loop.h"
#include "citadel/core/platform_window.h"
#include "citadel/core/window.h"

#include "citadel/math/vectors/basic_vec2.h"
#include "citadel/math/vectors/vec2.h"

#include "citadel/memory/buffer.h"
#include "citadel/memory/reference.h"
#include "citadel/memory/scope.h"

#include "citadel/rendering/color.h"
#include "citadel/rendering/rendering_context.h"
#include "citadel/rendering/rendering_types.h"
#include "citadel/rendering/viewport.h"

#include "citadel/rendering/retained/index_buffer.h"
#include "citadel/rendering/retained/vertex_array.h"
#include "citadel/rendering/retained/vertex_buffer.h"
#include "citadel/rendering/retained/vertex_buffer_element.h"
#include "citadel/rendering/retained/vertex_buffer_layout.h"

#include "citadel/string/const_string.h"

#include "drivers/opengl/opengl_context.h"
#include "drivers/opengl/opengl_defines.h"
#include "drivers/opengl/opengl_loader.h"
#include "drivers/opengl/opengl_types.h"
#include "drivers/opengl/opengl_viewport.h"

#include "drivers/opengl/retained/opengl_index_buffer.h"
#include "drivers/opengl/retained/opengl_vertex_array.h"
#include "drivers/opengl/retained/opengl_vertex_buffer.h"

#include "platforms/windows/windows_window.h"

#endif
