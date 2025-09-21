// File:        benchmarking_macros.h
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

#include <chrono>

#include "citadel/export.h"
#include "citadel/function.h"
#include "citadel/utility.h"

#include "citadel/functional/function_callable.h"

#include "citadel/memory/reference.h"

#include "citadel/profiling/scoped_benchmarker.h"

namespace citadel::detail
{
	using benchmark_duration_t = std::chrono::nanoseconds;
	using benchmark_callback_t = void(const std::string&, benchmark_duration_t duration);

	CITADEL_API void benchmark_callback(const std::string& name, benchmark_duration_t duration);
}

#define CITADEL_BENCHMARK_LINE(name, line)                                                                                                                                         \
	auto benchmark_callback_##line = ::citadel::make_referenced<::citadel::function_callable<::citadel::detail::benchmark_callback_t>>(::citadel::detail::benchmark_callback); \
	::citadel::scoped_benchmarker<::citadel::detail::benchmark_callback_t, ::citadel::detail::benchmark_duration_t> benchmarker_##line(name, benchmark_callback_##line);

#define CITADEL_BENCHMARK_SCOPE() CITADEL_BENCHMARK_LINE(CITADEL_FUNCTION_CONTEXT, __LINE__)
#define CITADEL_BENCHMARK_FUNCTION() CITADEL_BENCHMARK_LINE("'" CITADEL_FUNCTION_SIGNATURE "'", __LINE__)
