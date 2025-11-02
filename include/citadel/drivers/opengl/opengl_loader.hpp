// File:       opengl_loader.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	class api opengl_loader {
	public:
		static void* get_procedure_address(const char* name);

		opengl_loader() = default;
		~opengl_loader() = default;

		int load();
		void unload();

		nodisc int get_version_major() const noexcept;
		nodisc int get_version_minor() const noexcept;

	private:
		int version_major_ = 0;
		int version_minor_ = 0;
	};
}
