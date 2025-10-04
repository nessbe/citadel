// File:       layer_stack.cpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// For more details, see the LICENSE file at the root of the project.

#include "citadel/pch.hpp"
#include "citadel/layers/layer_stack.hpp"

namespace citadel {
	layer_stack::layer_stack(std::initializer_list<reference<layer>> layers)
		: layers_(layers) {
		for (const reference<layer>& layer : layers) {
			layer->attach();
		}
	}

	layer_stack::~layer_stack() {
		for (const reference<layer>& layer : layers_) {
			layer->detach();
		}
	}

	void layer_stack::update() {
		for (const reference<layer>& layer : layers_) {
			if (layer->update()) {
				return;
			}
		}
	}

	void layer_stack::render() {
		for (const reference<layer>& layer : layers_) {
			if (layer->render()) {
				return;
			}
		}
	}

	bool layer_stack::propagate_event(const reference<event>& event) {
		for (const reference<layer>& layer : layers_) {
			if (layer->propagate_event(event)) {
				return true;
			}
		}

		return false;
	}

	void layer_stack::push_layer(const reference<layer>& layer) {
		CITADEL_ASSERT(layer, "Layer is null");

		if (layer) {
			layer->attach();
		}

		layers_.push_back(layer);
	}

	reference<layer> layer_stack::pop_layer() {
		reference<layer> layer = layers_.back();

		CITADEL_ASSERT(layer, "Layer is null");

		if (layer) {
			layer->detach();
		}

		layers_.pop_back();
		return layer;
	}
}
