// File:       mouse_code.hpp
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

namespace citadel {
	enum class mouse_code : std::uint8_t {
		none =          0,

		// Buttons
		left_button   = 1,
		right_button  = 2,
		middle_button = 3,
		button_4      = 4,
		button_5      = 5,
		button_6      = 6,
		button_7      = 7,
		button_8      = 8,

		// Scroll
		wheel_up      = 20,
		wheel_down    = 21,
		wheel_left    = 22,
		wheel_right   = 23,
	};
}
