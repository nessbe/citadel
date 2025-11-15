// File:       layer_stack.cpp
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
#include "citadel/core/layers/layer_stack.hpp"

namespace citadel {
	layer_stack::~layer_stack() {
		for (const std::shared_ptr<layer>& layer : layers_) {
			layer->detach();
		}
	}

	void layer_stack::update() {
		for (const std::shared_ptr<layer>& layer : layers_) {
			if (!layer->update()) {
				break;
			}
		}
	}

	void layer_stack::render(const std::unique_ptr<surface>& surface) {
		for (const std::shared_ptr<layer>& layer : layers_) {
			if (!layer->render(surface)) {
				break;
			}
		}
	}

	void layer_stack::push(const std::shared_ptr<layer>& layer) {
		CITADEL_ASSERT(layer, "The given layer is null");
		layers_.push_back(layer);
		layer->attach();
	}

	std::shared_ptr<layer> layer_stack::pop() {
		std::shared_ptr<layer> layer = layers_.back();
		layers_.pop_back();
		layer->detach();
		return layer;
	}
}
