// File:        benchmarker.inl
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
	template<typename R, typename... Arguments>
	bool benchmarker<R(Arguments...)>::is_good() const noexcept
	{
		return (bool)(&task_);
	}

	template<typename R, typename... Arguments>
	bool benchmarker<R(Arguments...)>::is_running() const noexcept
	{
		return total_timer_.is_running();
	}

	template<typename R, typename... Arguments>
	void benchmarker<R(Arguments...)>::start()
	{
		total_timer_.start();
	}

	template<typename R, typename... Arguments>
	void benchmarker<R(Arguments...)>::stop()
	{
		total_timer_.stop();
	}

	template<typename R, typename... Arguments>
	R benchmarker<R(Arguments...)>::execute(Arguments... arguments)
	{
		static_assert(sizeof...(Arguments) >= 0, "Check arguments");
		CITADEL_ASSERT(static_cast<bool>(task_), "Benchmarker task is null");

		if (!is_running())
		{
			start();
		}

		task_timer_.start();

		if constexpr (std::is_void_v<R>)
		{
			task_->call(arguments...);
			task_timer_.stop();
		}
		else
		{
			R result = task_->call(arguments...);
			task_timer_.stop();
			return result;
		}
	}

	template<typename R, typename... Arguments>
	template<typename Duration>
	Duration benchmarker<R(Arguments...)>::duration() const
	{
		return total_timer_.elapsed<Duration>();
	}

	template<typename R, typename... Arguments>
	template<typename Rep, typename Period>
	std::chrono::duration<Rep, Period> benchmarker<R(Arguments...)>::duration() const
	{
		return total_timer_.elapsed<Rep, Period>();
	}

	template<typename R, typename... Arguments>
	void benchmarker<R(Arguments...)>::set_task(reference<task_t> value)
	{
		task_ = value;
	}

	template<typename R, typename... Arguments>
	reference<typename benchmarker<R(Arguments...)>::task_t> benchmarker<R(Arguments...)>::get_task() const
	{
		return task_;
	}
}
