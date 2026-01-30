// File:       window_shown_event.cpp
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

#include "citadel/pch.hpp"
#include "citadel/core/events/window_shown_event.hpp"

namespace citadel {
	window_shown_event::window_shown_event(window_handle window)
		: window_(window) { }

	window_handle window_shown_event::window() const noexcept {
		return window_;
	}

	void window_shown_event::_consume() noexcept {}
}
