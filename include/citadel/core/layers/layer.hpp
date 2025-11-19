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

#include <memory>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/core/display/surface.hpp"

namespace citadel {
	class exported layer {
	public:
		virtual ~layer() = default;

		void attach();
		void detach();

		bool update(double delta);
		bool render(const std::unique_ptr<surface>& surface);

	private:
		virtual void _attach() = 0;
		virtual void _detach() = 0;

		virtual bool _update(double delta) = 0;
		virtual bool _render(const std::unique_ptr<surface>& surface) = 0;
	};
}
