// File:       layer.cpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#include "citadel/pch.hpp"
#include "citadel/core/layers/layer.hpp"

namespace citadel {
	void layer::attach() {
		_attach();
	}

	void layer::detach() {
		_detach();
	}

	bool layer::update(double delta) {
		return _update(delta);
	}

	bool layer::render(const scope<surface>& surface) {
		return _render(surface);
	}

	bool layer::handle(const event_reference& event) {
		return _handle(event);
	}
}
