// File:        benchmark_result.h
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
#include <type_traits>

#include "citadel/attributes.h"

namespace citadel
{
	template<typename T, typename Duration>
	class benchmark_result;

	template<typename T, typename Rep, typename Period>
	class benchmark_result<T, std::chrono::duration<Rep, Period>>
	{
	public:
		using duration_t = std::chrono::duration<Rep, Period>;

	public:
		benchmark_result(duration_t duration, const T& value)
			: duration_(duration), value_(value) { }

		benchmark_result(duration_t duration, T&& value)
			: duration_(duration), value_(std::forward<T>(value)) { }

		~benchmark_result() = default;

		CITADEL_GETTER duration_t duration() const;
		CITADEL_GETTER const T& value() const;

	private:
		T value_;
		duration_t duration_;
	};

	template<typename Rep, typename Period>
	class benchmark_result<void, std::chrono::duration<Rep, Period>>
	{
	public:
		using duration_t = std::chrono::duration<Rep, Period>;

	public:
		benchmark_result(duration_t duration)
			: duration_(duration) { }

		~benchmark_result() = default;

		CITADEL_GETTER duration_t duration() const;

	private:
		duration_t duration_;
	};
}

#include "citadel/profiling/benchmark_result.inl"
