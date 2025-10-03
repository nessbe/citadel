// File:       layer.hpp
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

#pragma once

#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/events/event.hpp"

#include "citadel/memory/reference.hpp"

namespace citadel {
	class layer {
	public:
		layer(const std::string& name)
			: name_(name) { }

		virtual ~layer() = default;

		CITADEL_API void attach();
		CITADEL_API void detach();

		CITADEL_API bool update();
		CITADEL_API bool render();

		CITADEL_API bool propagate_event(const reference<event>& event);

		CITADEL_API CITADEL_GETTER const std::string& get_name() const noexcept;
		CITADEL_API CITADEL_GETTER bool is_attached() const noexcept;

	private:
		std::string name_;
		bool is_attached_ = false;

	private:
		virtual void _attach() = 0;
		virtual void _detach() = 0;

		virtual bool _update() = 0;
		virtual bool _render() = 0;

		virtual bool _propagate_event(const reference<event>& event) = 0;
	};
}
