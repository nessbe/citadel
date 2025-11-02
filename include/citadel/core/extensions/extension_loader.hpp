// File:       extension_loader.hpp
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
	class extension_loader {
	public:
		extension_loader() = default;
		virtual ~extension_loader();

		int load();
		void unload();

		nodisc int get_version_major() const;
		nodisc int get_version_minor() const;

	private:
		virtual int _load() = 0;
		virtual void _unload() = 0;

		nodisc virtual int _get_version_major() const = 0;
		nodisc virtual int _get_version_minor() const = 0;
	};
}
