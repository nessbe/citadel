// File:       sandbox_layer.cpp
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

#include "sandbox/sandbox_layer.hpp"

#include "sandbox/sandbox.hpp"

namespace sandbox {
	void sandbox_layer::_attach() {
		layer_attach(this);
	}

	void sandbox_layer::_detach() {
		layer_detach(this);
	}

	bool sandbox_layer::_update(double delta) {
		return layer_update(this, delta);
	}

	bool sandbox_layer::_render(const citadel::scope<citadel::surface>& surface) {
		return layer_render(this, surface);
	}

	bool sandbox_layer::_handle(const citadel::event_reference& event) {
		return layer_handle(this, event);
	}
}
