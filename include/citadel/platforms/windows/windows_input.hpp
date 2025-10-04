// File:       windows_input.hpp
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

#include "citadel/platforms.hpp"

#if CITADEL_PLATFORM_WINDOWS

#include "citadel/export.hpp"

#include "citadel/input/input.hpp"
#include "citadel/input/input_context.hpp"

namespace citadel {
	class windows_input : public input {
	public:
		windows_input() = default;
		virtual ~windows_input() override = default;

	private:
		CITADEL_API virtual void _update() override;
		CITADEL_API virtual void _give_context(const input_context& context);
	};
}

#endif
