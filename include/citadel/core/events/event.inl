// File:       event.inl
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#include <type_traits>

namespace citadel {
	template <typename Event, typename... Arguments>
	event_reference make_event(Arguments&&... arguments) {
		static_assert(std::is_base_of_v<event, Event>, "Event must inherit from event class");
		return std::dynamic_pointer_cast<event>(
			make_referenced<Event>(std::forward<Arguments>(arguments)...)
		);
	}
}
