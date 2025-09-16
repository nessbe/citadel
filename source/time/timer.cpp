// File:        timer.cpp
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

#include "citadel/pch.h"
#include "citadel/time/timer.h"

namespace citadel
{
	void timer::start()
	{
		start_time = time_clock_t::now();
		end_time = time_point_t{ };
	}

	void timer::stop()
	{
		end_time = time_clock_t::now();
	}

	bool timer::is_running() const
	{
		return end_time == time_point_t{ };
	}
}
