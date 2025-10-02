// File:       mouse_button_event.cpp
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
#include "citadel/events/mouse_button_event.hpp"

namespace citadel {
	mouse_button_code mouse_button_event::get_code() const noexcept {
		return code_;
	}

	mouse_button_state mouse_button_event::get_state() const noexcept {
		return state_;
	}

	bool mouse_button_event::is_released() const noexcept {
		return state_ == mouse_button_state::released;
	}

	bool mouse_button_event::is_pressed() const noexcept {
		return state_ == mouse_button_state::pressed;
	}

	bool mouse_button_event::is_held() const noexcept {
		return state_ == mouse_button_state::held;
	}

	bool mouse_button_event::is_double_clicked() const noexcept {
		return state_ == mouse_button_state::double_clicked;
	}

	void mouse_button_event::_consume() { }
}
