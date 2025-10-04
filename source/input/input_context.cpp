// File:       input_context.cpp
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
#include "citadel/input/input_context.hpp"

namespace citadel {
	bool input_context::is_key_code() const noexcept {
		return std::holds_alternative<key_code>(code);
	}

	key_code input_context::as_key_code() const {
		CITADEL_ASSERT(is_key_code(), "Code is not a key code");
		return std::get<key_code>(code);
	}

	bool input_context::is_mouse_button_code() const noexcept {
		return std::holds_alternative<mouse_button_code>(code);
	}

	mouse_button_code input_context::as_mouse_button_code() const {
		CITADEL_ASSERT(is_mouse_button_code(), "Code is not a mouse button code");
		return std::get<mouse_button_code>(code);
	}

	bool input_context::is_key_state() const noexcept {
		return std::holds_alternative<key_state>(state);
	}

	key_state input_context::as_key_state() const {
		CITADEL_ASSERT(is_key_state(), "State is not a key state");
		return std::get<key_state>(state);
	}

	bool input_context::is_mouse_button_state() const noexcept {
		return std::holds_alternative<mouse_button_state>(state);
	}

	mouse_button_state input_context::as_mouse_button_state() const {
		CITADEL_ASSERT(is_mouse_button_state(), "State is not a mouse button state");
		return std::get<mouse_button_state>(state);
	}
}
