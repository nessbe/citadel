// File:        timer.inl
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

namespace citadel
{
	template<typename Duration>
	Duration timer::elapsed() const
	{
		if (is_running())
		{
			time_point_t current_time = time_clock_t::now();
			return std::chrono::duration_cast<Duration>(current_time - start_time);
		}

		return std::chrono::duration_cast<Duration>(end_time - start_time);
	}

	template<typename Rep, typename Period>
	std::chrono::duration<Rep, Period> timer::elapsed() const
	{
		using duration_t = std::chrono::duration<Rep, Period>;
		return elapsed<duration_t>();
	}
}
