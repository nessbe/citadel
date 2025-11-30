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
	void* opengl_loader::get_procedure_address(const char* name) noexcept {
#if CITADEL_PLATFORM_WINDOWS
		void* address = reinterpret_cast<void*>(wglGetProcAddress(name));

		if (address) {
			return address;
		}

		static HMODULE opengl32_module = LoadLibraryA("opengl32.dll");
		return reinterpret_cast<void*>(GetProcAddress(opengl32_module, name));
#else
	#error Cannot load OpenGL procedure addresses using your operating system yet
#endif
	}

	int opengl_loader::_load() {
		int status = gladLoadGLLoader((GLADloadproc)get_procedure_address);

		if (status) {
			std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
			std::cout << "OpenGL Renderer Version: " << glGetString(GL_RENDERER) << std::endl;
			std::cout << "OpenGL Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

			int profile_mask = 0;
			glGetIntegerv(GL_CONTEXT_PROFILE_MASK, &profile_mask);
			std::cout << "OpenGL Profile: ";

			if (profile_mask & GL_CONTEXT_CORE_PROFILE_BIT) {
				std::cout << "Core" << std::endl;
			}
			else if (profile_mask & GL_CONTEXT_COMPATIBILITY_PROFILE_BIT) {
				std::cout << "Compatibility" << std::endl;
			}
			else {
				std::cout << "Unknown" << std::endl;
			}
		}

		return status;
	}

	void opengl_loader::_unload() { }

	int opengl_loader::_get_version_major() const {
		return GLVersion.major;
	}

	int opengl_loader::_get_version_minor() const {
		return GLVersion.minor;
	}
}
