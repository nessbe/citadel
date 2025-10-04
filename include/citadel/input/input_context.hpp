// File:       input_context.hpp
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
#include <variant>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/input/key_code.hpp"
#include "citadel/input/key_state.hpp"
#include "citadel/input/mouse_button_code.hpp"
#include "citadel/input/mouse_button_state.hpp"

namespace citadel {
	struct input_context {
	public:
		using code_type = std::variant<key_code, mouse_button_code>;
		using state_type = std::variant<key_state, mouse_button_state>;

	public:
		code_type code;
		state_type state;

		std::uint32_t repeat_count;

	public:
		input_context(code_type code, state_type state, std::uint32_t repeat_count)
			: code(code), state(state), repeat_count(repeat_count) { }

		input_context(code_type code, state_type state)
			: input_context(code, state, 0) { }

		~input_context() = default;

		CITADEL_API CITADEL_GETTER bool is_key_code() const noexcept;
		CITADEL_API CITADEL_GETTER key_code as_key_code() const;

		CITADEL_API CITADEL_GETTER bool is_mouse_button_code() const noexcept;
		CITADEL_API CITADEL_GETTER mouse_button_code as_mouse_button_code() const;

		CITADEL_API CITADEL_GETTER bool is_key_state() const noexcept;
		CITADEL_API CITADEL_GETTER key_state as_key_state() const;

		CITADEL_API CITADEL_GETTER bool is_mouse_button_state() const noexcept;
		CITADEL_API CITADEL_GETTER mouse_button_state as_mouse_button_state() const;
	};
}
