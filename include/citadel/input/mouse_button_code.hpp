// File:       mouse_button_code.hpp
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
#include <ostream>
#include <string>
#include <unordered_map>

#include "citadel/export.hpp"

namespace citadel {
	enum class mouse_button_code : std::uint8_t {
		none =          0,
		left_button   = 1,
		right_button  = 2,
		middle_button = 3,
		button_4      = 4,
		button_5      = 5,
		button_6      = 6,
		button_7      = 7,
		button_8      = 8,
	};

	CITADEL_API extern const std::unordered_map<mouse_button_code, std::string> mouse_button_names;
	CITADEL_API std::string get_mouse_button_name(mouse_button_code code) noexcept;
	CITADEL_API std::ostream& operator<<(std::ostream& out, mouse_button_code value);
}
