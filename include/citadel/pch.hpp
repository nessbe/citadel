// File:       pch.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
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
#include <array>
#include <charconv>
#include <chrono>
#include <cinttypes>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

#include "citadel/architectures.hpp"
#include "citadel/assert.hpp"
#include "citadel/attributes.hpp"
#include "citadel/compilers.hpp"
#include "citadel/exceptions.hpp"
#include "citadel/export.hpp"
#include "citadel/packing.hpp"
#include "citadel/platforms.hpp"
#include "citadel/pointers.hpp"
#include "citadel/pragma.hpp"
#include "citadel/warnings.hpp"

#include "citadel/debug/exceptions/exception.hpp"
#include "citadel/debug/exceptions/invalid_argument_error.hpp"
#include "citadel/debug/exceptions/invalid_member_error.hpp"
#include "citadel/debug/exceptions/invalid_operation_error.hpp"
#include "citadel/debug/exceptions/invalid_result_error.hpp"
#include "citadel/debug/exceptions/null_reference_error.hpp"

#include "citadel/debug/exceptions/rendering/invalid_texture_pixel_format_error.hpp"
#include "citadel/debug/exceptions/rendering/shader_uniform_not_found_error.hpp"

#include "citadel/drivers/opengl.hpp"

#include "citadel/formats/ansi/ansi_colors.hpp"

#include "citadel/logging/log_macros.hpp"
#include "citadel/logging/loggers.hpp"
#include "citadel/logging/this_logger.hpp"

#include "citadel/math/angles.hpp"
#include "citadel/math/epsilon.hpp"

#include "citadel/math/matrices/mat3.hpp"
#include "citadel/math/matrices/mat4.hpp"

#include "citadel/math/vectors/vec2.hpp"
#include "citadel/math/vectors/vec3.hpp"
#include "citadel/math/vectors/vec4.hpp"

#include "citadel/memory/reference.hpp"
#include "citadel/memory/scope.hpp"

#include "citadel/platforms/windows.hpp"

#include "citadel/utils/string/string_convertion.hpp"
#include "citadel/utils/string/stringifier.hpp"

#include "citadel/utils/format/formatter.hpp"
