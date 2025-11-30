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
		for (const reference<layer>& layer : layers_) {
			CITADEL_POINTER_CALL(layer, detach);
		}
	}

	void layer_stack::update(double delta) {
		for (const reference<layer>& layer : layers_) {
			if (CITADEL_POINTER_CALL_OR_FALSE(layer, update, delta)) {
				break;
			}
		}
	}

	void layer_stack::render(const scope<surface>& surface) {
		for (const reference<layer>& layer : layers_) {
			if (CITADEL_POINTER_CALL_OR_FALSE(layer, render, surface)) {
				break;
			}
		}
	}

	void layer_stack::push(const reference<layer>& layer) {
		CITADEL_SOFT_ASSERT(layer, "The given layer is null");
		layers_.push_back(layer);
		CITADEL_POINTER_CALL(layer, attach);
	}

	reference<layer> layer_stack::pop() {
		reference<layer> layer = layers_.back();
		layers_.pop_back();
		CITADEL_POINTER_CALL(layer, detach);
		return layer;
	}
}
