// File:        timer.h
// Project:     citadel
// Repository:  https://github.com/nessbe/citadel
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

#include <chrono>

#include "citadel/attributes.h"
#include "citadel/export.h"

namespace citadel
{
	class timer
	{
	public:
		using time_clock_t = std::chrono::high_resolution_clock;
		using time_point_t = time_clock_t::time_point;

	public:
		timer() = default;
		~timer() = default;

		CITADEL_API void start();
		CITADEL_API void stop();

		CITADEL_API CITADEL_GETTER bool is_running() const;

		template<typename Duration>
		CITADEL_NODISCARD Duration elapsed() const;

		template<typename Rep, typename Period>
		CITADEL_GETTER std::chrono::duration<Rep, Period> elapsed() const;

	public:
		time_point_t start_time;
		time_point_t end_time;
	};
}

#include "citadel/time/timer.inl"
