// File:       sandbox.cpp
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

#include "sandbox/sandbox.hpp"

namespace sandbox {
	void application_initialize(citadel::application* application) { }

	citadel::exit_code application_run(citadel::application* application) {
		return citadel::exit_code::success;
	}

	void application_shutdown(citadel::application* application) { }

	void layer_attach(citadel::layer* layer) { }
	void layer_detach(citadel::layer* layer) { }

	bool layer_update(citadel::layer* layer, double delta) {
		return true;
	}

	bool layer_render(citadel::layer* layer, const citadel::scope<citadel::surface>& surface) {
		return true;
	}
}
