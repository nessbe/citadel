// File:       citadel.hpp
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

#include "citadel/architectures.hpp"
#include "citadel/assert.hpp"
#include "citadel/attributes.hpp"
#include "citadel/compilers.hpp"
#include "citadel/export.hpp"
#include "citadel/platforms.hpp"
#include "citadel/pragma.hpp"
#include "citadel/warnings.hpp"

#include "citadel/core/application.hpp"
#include "citadel/core/engine.hpp"
#include "citadel/core/entry_point.hpp"
#include "citadel/core/exit_code.hpp"

#include "citadel/core/extensions/extension_loader.hpp"

#include "citadel/display/surface.hpp"
#include "citadel/display/window.hpp"

#include "citadel/drivers/opengl.hpp"
#include "citadel/drivers/opengl/opengl_context.hpp"
#include "citadel/drivers/opengl/opengl_loader.hpp"
#include "citadel/drivers/opengl/opengl_surface.hpp"

#include "citadel/platforms/windows.hpp"
#include "citadel/platforms/windows/wgl_loader.hpp"
#include "citadel/platforms/windows/windows_window.hpp"

#include "citadel/rendering/color.hpp"
#include "citadel/rendering/rendering_context.hpp"

#include "citadel/rendering/shaders/shader.hpp"
