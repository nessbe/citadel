// File:       mouse_button_code.cpp
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

#include "citadel/pch.hpp"
#include "citadel/input/mouse_button_code.hpp"

namespace citadel {
	const std::unordered_map<mouse_button_code, std::string> mouse_button_names = {
		{ mouse_button_code::none,         "None" },
		{ mouse_button_code::left_button,  "Left Button" },
		{ mouse_button_code::right_button, "Right Button" },
		{ mouse_button_code::button_4,     "Button 4" },
		{ mouse_button_code::button_5,     "Button 5" },
		{ mouse_button_code::button_6,     "Button 6" },
		{ mouse_button_code::button_7,     "Button 7" },
		{ mouse_button_code::button_8,     "Button 8" },
	};

	std::string get_mouse_button_name(mouse_button_code code) noexcept {
		if (mouse_button_names.find(code) != mouse_button_names.end()) {
			return mouse_button_names.at(code);
		}

		return "UNKNOWN";
	}

	std::ostream& operator<<(std::ostream& out, mouse_button_code value) {
		return out << get_mouse_button_name(value);
	}
}
