// File:       layer.hpp
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
	class api layer {
	public:
		virtual ~layer() = default;

		void attach();
		void detach();

		bool update();
		void render();

	private:
		virtual void _attach() = 0;
		virtual void _detach() = 0;

		virtual bool _update() = 0;
		virtual void _render() = 0;
	};
}
