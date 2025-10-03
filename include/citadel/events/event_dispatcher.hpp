// File:       event_dispatcher.hpp
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

#include <functional>
#include <initializer_list>
#include <type_traits>
#include <vector>

#include "citadel/events/event.hpp"

namespace citadel {
	template <typename T>
	requires std::is_base_of_v<event, T>
	class event_dispatcher {
	public:
		using callback = std::function<bool(const T&)>;

	public:
		event_dispatcher() = default;

		event_dispatcher(std::initializer_list<callback> callbacks)
			: callbacks_(callbacks) { }

		~event_dispatcher() = default;

		bool dispatch_event(T& event);

		CITADEL_SETTER void push_callback(const callback& callback);
		CITADEL_SETTER void push_callback(callback&& callback);

		CITADEL_GETTER callback pop_callback();

	private:
		std::vector<callback> callbacks_;
	};
}

#include "citadel/events/event_dispatcher.inl"
