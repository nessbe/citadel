// File:       pch.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
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

#include <cinttypes>
#include <csignal>
#include <cstdlib>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>
#include <xhash>

#include "citadel/architectures.hpp"
#include "citadel/assert.hpp"
#include "citadel/compilers.hpp"
#include "citadel/platforms.hpp"

#include "citadel/input/key_code.hpp"
#include "citadel/input/key_state.hpp"
#include "citadel/input/mouse_button_code.hpp"
#include "citadel/input/mouse_button_state.hpp"

#include "citadel/memory/reference.hpp"
#include "citadel/memory/scope.hpp"

#if CITADEL_PLATFORM_WINDOWS
	#include <windows.h>
	#include <windowsx.h>
#endif
