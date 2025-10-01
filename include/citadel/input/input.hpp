// File:       input.hpp
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

#include <string>
#include <unordered_map>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/input/key_code.hpp"
#include "citadel/input/key_state.hpp"
#include "citadel/input/mouse_button_code.hpp"
#include "citadel/input/mouse_button_state.hpp"

#include "citadel/memory/scope.hpp"

namespace citadel {
	class input {
	public:
		virtual ~input() = default;

		CITADEL_API void update();

		CITADEL_API CITADEL_NODISCARD key_state get_key_state(key_code code) const;
		CITADEL_API CITADEL_GETTER bool is_key_pressed(key_code code) const;
		CITADEL_API CITADEL_GETTER bool is_key_released(key_code code) const;
		CITADEL_API CITADEL_GETTER bool is_key_repeated(key_code code) const;
		CITADEL_API CITADEL_GETTER bool is_key_held(key_code code) const;

		CITADEL_API CITADEL_NODISCARD mouse_button_state get_mouse_button_state(mouse_button_code code) const;
		CITADEL_API CITADEL_GETTER bool is_mouse_button_pressed(mouse_button_code code) const;
		CITADEL_API CITADEL_GETTER bool is_mouse_button_released(mouse_button_code code) const;
		CITADEL_API CITADEL_GETTER bool is_mouse_button_held(mouse_button_code code) const;

		CITADEL_API CITADEL_GETTER const std::string& get_character_buffer() const noexcept;
		CITADEL_API CITADEL_INLINE void clear_character_buffer() noexcept;

		CITADEL_API CITADEL_GETTER static scope<input> create();

	protected:
		CITADEL_API void press_key(key_code code);
		CITADEL_API void release_key(key_code code);
		CITADEL_API void repeat_key(key_code code);

		CITADEL_API void press_mouse_button(mouse_button_code code);
		CITADEL_API void release_mouse_button(mouse_button_code code);

		CITADEL_API CITADEL_INLINE void push_character(char character);

	private:
		std::string character_buffer_;

		std::unordered_map<key_code, key_state> keys_;
		std::unordered_map<mouse_button_code, mouse_button_state> mouse_buttons_;

	private:
		virtual void _update() = 0;
	};
}
