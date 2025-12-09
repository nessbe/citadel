// File:       sandbox.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#include <citadel/citadel.hpp>

namespace sandbox {
	void application_initialize(citadel::application* application);
	citadel::exit_code application_run(citadel::application* application);
	void application_shutdown(citadel::application* application);

	void layer_attach(citadel::layer* layer);
	void layer_detach(citadel::layer* layer);

	bool layer_update(citadel::layer* layer, double update);
	bool layer_render(citadel::layer* layer, const citadel::scope<citadel::surface>& surface);
}
