// File:        benchmarking_macros.cpp
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
#include "citadel/profiling/benchmarking_macros.h"

namespace citadel::detail
{
	void benchmark_callback(const std::string& name, benchmark_duration_t duration)
	{
		double duration_s = double(duration.count()) / double(benchmark_duration_t::period::den);
		this_logger::log_info(name + " benchmark result: " + std::to_string(duration_s) + 's');
	}
}
