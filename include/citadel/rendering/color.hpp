// File:       color.hpp
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

#include <cinttypes>
#include <limits>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#undef max

namespace citadel {
	struct color {
	public:
		using channel = std::uint8_t;

	public:
		CITADEL_API static channel max_value;

		channel red, green, blue, alpha;

	public:
		CITADEL_API color(channel red, channel green, channel blue, channel alpha);
		CITADEL_API color(channel red, channel green, channel blue);

		~color() = default;

		CITADEL_NODISCARD CITADEL_API static color from_rgba(channel red, channel green, channel blue, channel alpha);
		CITADEL_NODISCARD CITADEL_API static color from_rgb(channel red, channel green, channel blue);
	};
}
