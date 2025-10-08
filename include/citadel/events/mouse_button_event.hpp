// File:       mouse_button_event.hpp
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

#include "citadel/export.hpp"

#include "citadel/events/event.hpp"

#include "citadel/input/mouse_button_code.hpp"
#include "citadel/input/mouse_button_state.hpp"

namespace citadel {
	class mouse_button_event : public event {
	public:
		mouse_button_event(mouse_button_code code, mouse_button_state state)
			: code_(code), state_(state) { }

		virtual ~mouse_button_event() override = default;

		CITADEL_GETTER CITADEL_API mouse_button_code get_code() const noexcept;
		CITADEL_GETTER CITADEL_API mouse_button_state get_state() const noexcept;

		CITADEL_GETTER CITADEL_API bool is_released() const noexcept;
		CITADEL_GETTER CITADEL_API bool is_pressed() const noexcept;
		CITADEL_GETTER CITADEL_API bool is_held() const noexcept;
		CITADEL_GETTER CITADEL_API bool is_double_clicked() const noexcept;

	private:
		mouse_button_code code_;
		mouse_button_state state_;

	private:
		CITADEL_API virtual void _consume();
	};
}
