// File:       basic_layer.cpp
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

#include "basic_application/basic_layer.hpp"

namespace basic_application {
	void basic_layer::_attach() { }
	void basic_layer::_detach() { }

	bool basic_layer::_update(double delta) {
		return false;
	}

	bool basic_layer::_render(const citadel::scope<citadel::surface>& surface) {
		return false;
	}

	bool basic_layer::_handle(const citadel::event_reference& event) {
		return false;
	}
}
