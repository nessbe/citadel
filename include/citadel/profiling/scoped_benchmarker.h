// File:        scoped_benchmarker.h
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
#include <string>

#include "citadel/attributes.h"

#include "citadel/functional/callable.h"

#include "citadel/memory/reference.h"

#include "citadel/profiling/benchmark_result.h"

#include "citadel/time/timer.h"

namespace citadel
{
	template<typename Signature, typename Duration>
	class scoped_benchmarker;

	template<typename Duration, typename R, typename... Arguments>
	class scoped_benchmarker<R(Arguments...), Duration>
	{
	public:
		using callback_t = callable<void(const std::string&, Duration)>;

	public:
		scoped_benchmarker(const std::string& name);

		scoped_benchmarker(const std::string& name, reference<callback_t> callback);

		~scoped_benchmarker();

		CITADEL_GETTER bool is_good() const;
		CITADEL_GETTER bool is_running() const;

		CITADEL_INLINE void start();
		CITADEL_INLINE void stop();

		CITADEL_GETTER Duration duration() const;

		CITADEL_GETTER const std::string& get_name() const noexcept;

		CITADEL_SETTER void set_callback(reference<callback_t> value);
		CITADEL_GETTER reference<callback_t> get_callback() const;

	private:
		std::string name_;
		reference<callback_t> callback_;

		timer timer_;
	};
}

#include "citadel/profiling/scoped_benchmarker.inl"
