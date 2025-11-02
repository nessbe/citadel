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

#include "citadel/core/extensions/extension_loader.hpp"

namespace citadel {
	class api opengl_loader : public extension_loader {
	public:
		static void* get_procedure_address(const char* name) noexcept;

		opengl_loader() = default;

	private:
		virtual int _load() override;
		virtual void _unload() override;

		virtual int _get_version_major() const override;
		virtual int _get_version_minor() const override;
	};
}
