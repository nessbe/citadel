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

#include <memory>
#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/core/layers/layer.hpp"

namespace citadel {
	class exported layer_stack {
	public:
		layer_stack() = default;
		~layer_stack();

		void update();
		void render(const std::unique_ptr<surface>& surface);

		void push(const std::shared_ptr<layer>& layer);
		std::shared_ptr<layer> pop();

	private:
		std::vector<std::shared_ptr<layer>> layers_;
	};
}

