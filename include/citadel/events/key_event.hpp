// File:       key_event.hpp
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

#include "citadel/export.hpp"

#include "citadel/events/event.hpp"

#include "citadel/input/key_code.hpp"
#include "citadel/input/key_state.hpp"

namespace citadel {
	class key_event : public event {
	public:
		key_event(key_code code, key_state state, std::uint32_t repeat_count)
			: code_(code), state_(state), repeat_count_(repeat_count) { }

		key_event(key_code code, key_state state)
			: key_event(code, state, 0) { }

		virtual ~key_event() override = default;

		CITADEL_GETTER CITADEL_API key_code get_code() const noexcept;
		CITADEL_GETTER CITADEL_API key_state get_state() const noexcept;

		CITADEL_GETTER CITADEL_API bool is_released() const noexcept;
		CITADEL_GETTER CITADEL_API bool is_pressed() const noexcept;
		CITADEL_GETTER CITADEL_API bool is_held() const noexcept;
		CITADEL_GETTER CITADEL_API bool is_repeated() const noexcept;

		CITADEL_GETTER CITADEL_API std::uint32_t get_repeat_count() const noexcept;

	private:
		key_code code_;
		key_state state_;

		std::uint32_t repeat_count_;

	private:
		CITADEL_API virtual void _consume() override;
	};
}
