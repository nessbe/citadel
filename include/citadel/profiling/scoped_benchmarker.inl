// File:        scoped_benchmarker.inl
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
	template<typename Duration, typename R, typename... Arguments>
	scoped_benchmarker<R(Arguments...), Duration>::scoped_benchmarker(const std::string& name)
		: name_(name), callback_(nullptr)
	{
		start();
	}

	template<typename Duration, typename R, typename... Arguments>
	scoped_benchmarker<R(Arguments...), Duration>::scoped_benchmarker(const std::string& name, reference<callback_t> callback)
		: name_(name), callback_(callback)
	{
		start();
	}

	template<typename Duration, typename R, typename... Arguments>
	scoped_benchmarker<R(Arguments...), Duration>::~scoped_benchmarker()
	{
		stop();

		CITADEL_ASSERT(callback_, "Callback is null");
		callback_->call(name_, duration());
	}

	template<typename Duration, typename R, typename... Arguments>
	bool scoped_benchmarker<R(Arguments...), Duration>::is_good() const
	{
		return static_cast<bool>(&callback_);
	}

	template<typename Duration, typename R, typename... Arguments>
	bool scoped_benchmarker<R(Arguments...), Duration>::is_running() const
	{
		return timer_.is_running();
	}

	template<typename Duration, typename R, typename... Arguments>
	void scoped_benchmarker<R(Arguments...), Duration>::start()
	{
		timer_.start();
	}

	template<typename Duration, typename R, typename... Arguments>
	void scoped_benchmarker<R(Arguments...), Duration>::stop()
	{
		timer_.stop();
	}

	template<typename Duration, typename R, typename... Arguments>
	Duration scoped_benchmarker<R(Arguments...), Duration>::duration() const
	{
		return timer_.elapsed<Duration>();
	}

	template<typename Duration, typename R, typename... Arguments>
	const std::string& scoped_benchmarker<R(Arguments...), Duration>::get_name() const noexcept
	{
		return name_;
	}

	template<typename Duration, typename R, typename... Arguments>
	void scoped_benchmarker<R(Arguments...), Duration>::set_callback(reference<callback_t> value)
	{
		callback_ = value;
	}

	template<typename Duration, typename R, typename... Arguments>
	reference<typename scoped_benchmarker<R(Arguments...), Duration>::callback_t> scoped_benchmarker<R(Arguments...), Duration>::get_callback() const
	{
		return callback_;
	}
}
