// File:       input.cpp
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
#include "citadel/input/input.hpp"

namespace citadel {
	void input::update() {
		keys_.clear();
		mouse_buttons_.clear();

		_update();
	}

	key_state input::get_key_state(key_code code) const {
		if (keys_.find(code) == keys_.end()) {
			return key_state::none;
		}

		return keys_.at(code);
	}

	bool input::is_key_pressed(key_code code) const {
		return get_key_state(code) == key_state::pressed;
	}

	bool input::is_key_released(key_code code) const {
		return get_key_state(code) == key_state::released;
	}

	bool input::is_key_repeated(key_code code) const {
		return get_key_state(code) == key_state::repeated;
	}

	bool input::is_key_held(key_code code) const {
		return get_key_state(code) == key_state::held;
	}

	mouse_button_state input::get_mouse_button_state(mouse_button_code code) const {
		if (mouse_buttons_.find(code) != mouse_buttons_.end()) {
			return mouse_button_state::none;
		}

		return mouse_buttons_.at(code);
	}

	bool input::is_mouse_button_pressed(mouse_button_code code) const {
		return get_mouse_button_state(code) == mouse_button_state::pressed;
	}

	bool input::is_mouse_button_released(mouse_button_code code) const {
		return get_mouse_button_state(code) == mouse_button_state::released;
	}

	bool input::is_mouse_button_held(mouse_button_code code) const {
		return get_mouse_button_state(code) == mouse_button_state::held;
	}

	const std::string& input::get_character_buffer() const noexcept {
		return character_buffer_;
	}

	void input::clear_character_buffer() noexcept {
		character_buffer_.clear();
	}

	scope<input> input::create() {
		return nullptr;
	}

	void input::press_key(key_code code) {
		if (keys_.find(code) != keys_.end()) {
			if (keys_.at(code) == key_state::pressed) {
				keys_[code] = key_state::held;
				return;
			}
		}

		keys_[code] = key_state::pressed;
	}

	void input::release_key(key_code code) {
		keys_[code] = key_state::released;
	}

	void input::repeat_key(key_code code) {
		keys_[code] = key_state::repeated;
	}

	void input::press_mouse_button(mouse_button_code code) {
		if (mouse_buttons_.find(code) != mouse_buttons_.end()) {
			if (mouse_buttons_.at(code) == mouse_button_state::pressed) {
				mouse_buttons_[code] = mouse_button_state::held;
				return;
			}
		}

		mouse_buttons_[code] = mouse_button_state::pressed;
	}

	void input::release_mouse_button(mouse_button_code code) {
		mouse_buttons_[code] = mouse_button_state::released;
	}

	void input::push_character(char character) {
		character_buffer_.push_back(character);
	}
}
