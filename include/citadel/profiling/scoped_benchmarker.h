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

#include "citadel/functional/callable.h"

#include "citadel/memory/reference.h"

#include "citadel/profiling/benchmark_result.h"
#include "citadel/profiling/benchmarker.h"

namespace citadel
{
	template<typename Signature, typename Duration>
	class scoped_benchmarker;

	template<typename Duration, typename R, typename... Arguments>
	class scoped_benchmarker<R(Arguments...), Duration> : public benchmarker<R(Arguments...)>
	{
	public:
		using callback_t = callable<void(Duration)>;

	public:
		scoped_benchmarker(const std::string& name);

		scoped_benchmarker(const std::string& name, reference<typename benchmarker<R(Arguments...)>::task_t> task);

		virtual ~scoped_benchmarker() override;

		void set_callback(reference<callback_t> value);
		reference<callback_t> get_callback() const;

	private:
		reference<callback_t> callback_;
	};
}

#include "citadel/profiling/scoped_benchmarker.inl"
