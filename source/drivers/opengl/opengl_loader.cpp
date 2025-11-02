// File:       opengl_loader.cpp
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

#include "citadel/pch.hpp"
#include "citadel/drivers/opengl/opengl_loader.hpp"

namespace citadel {
	void* opengl_loader::get_procedure_address(const char* name) {
#if CITADEL_PLATFORM_WINDOWS
		void* address = wglGetProcAddress(name);

		if (address) {
			return address;
		}

		static HMODULE opengl32_module = LoadLibraryA("opengl32");
		return GetProcAddress(opengl32_module, name);
#endif
	}

	int opengl_loader::_load() {
		return gladLoadGLLoader((GLADloadproc)get_procedure_address);
	}

	void opengl_loader::_unload() { }

	int opengl_loader::_get_version_major() const {
		return GLVersion.major;
	}

	int opengl_loader::_get_version_minor() const {
		return GLVersion.minor;
	}
}
