// File:       layer.cpp
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
#include "citadel/layers/layer.hpp"

namespace citadel {
	void layer::attach() {
		_attach();
		is_attached_ = true;
	}

	void layer::detach() {
		_detach();
		is_attached_ = false;
	}

	bool layer::update() {
		CITADEL_ASSERT(is_attached_, "Layer is not attached");
		return _update();
	}

	bool layer::render() {
		CITADEL_ASSERT(is_attached_, "Layer is not attached");
		return _render();
	}

	bool layer::propagate_event(const reference<event>& event) {
		CITADEL_ASSERT(is_attached_, "Layer is not attached");

		bool is_consumed = _propagate_event(event);

		if (is_consumed) {
			event->consume();
		}

		return is_consumed;
	}

	const std::string& layer::get_name() const noexcept {
		return name_;
	}

	bool layer::is_attached() const noexcept {
		return is_attached_;
	}
}
