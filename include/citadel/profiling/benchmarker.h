// File:        benchmarker.h
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
#include <functional>
#include <string>

#include "citadel/assert.h"
#include "citadel/export.h"

#include "citadel/functional/callable.h"

#include "citadel/memory/reference.h"
#include "citadel/memory/scope.h"

#include "citadel/profiling/benchmark_result.h"

#include "citadel/time/timer.h"

namespace citadel
{
	template<typename Signature>
	class benchmarker;

	template<typename R, typename... Arguments>
	class benchmarker<R(Arguments...)>
	{
	public:
		using task_t = callable<R(Arguments...)>;

		template<typename Duration>
		using result_t = benchmark_result<R, Duration>;

	public:
		benchmarker(const std::string& name)
			: name_(name), task_(nullptr) { }

		benchmarker(const std::string& name, reference<task_t> task)
			: name_(name), task_(task) { }

		virtual ~benchmarker() = default;

		CITADEL_GETTER bool is_good() const noexcept;
		CITADEL_GETTER bool is_running() const noexcept;

		void start();
		void stop();

		template<typename Duration>
		CITADEL_NODISCARD result_t<Duration> execute(Arguments... arguments);

		template<typename Rep, typename Period>
		CITADEL_NODISCARD result_t<std::chrono::duration<Rep, Period>> execute(Arguments... arguments);

		template<typename Duration>
		CITADEL_GETTER Duration duration() const;

		template<typename Rep, typename Period>
		CITADEL_GETTER std::chrono::duration<Rep, Period> duration() const;

		std::string get_name() const;

		void set_task(reference<task_t> value);
		reference<task_t> get_task() const;

	private:
		std::string name_;
		reference<task_t> task_;

		timer task_timer_;
		timer total_timer_;

	private:
		R execute_raw(Arguments... arguments);
	};
}

#include "citadel/profiling/benchmarker.inl"
