// File:       pch.hpp
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

#include <algorithm>
#include <cinttypes>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>

#include "citadel/architectures.hpp"
#include "citadel/assert.hpp"
#include "citadel/attributes.hpp"
#include "citadel/compilers.hpp"
#include "citadel/export.hpp"
#include "citadel/platforms.hpp"
#include "citadel/pragma.hpp"
#include "citadel/type_traits.hpp"
#include "citadel/warnings.hpp"

#include "citadel/drivers/opengl.hpp"

#include "citadel/math/vectors/vec2.hpp"
#include "citadel/math/vectors/vec3.hpp"

#include "citadel/platforms/windows.hpp"

#include <glad/glad.h>
#include <glad/glad_wgl.h>
