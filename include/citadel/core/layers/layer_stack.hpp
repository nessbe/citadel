// File:       layer_stack.hpp
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

#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/core/layers/layer.hpp"

#include "citadel/memory/reference.hpp"
#include "citadel/memory/scope.hpp"

namespace citadel {
	class exported layer_stack {
	public:
		layer_stack() = default;
		~layer_stack();

		void update(double delta);
		void render(const scope<surface>& surface);

		void push(const reference<layer>& layer);
		reference<layer> pop();

	private:
		std::vector<reference<layer>> layers_;
	};
}

