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
#include <type_traits>

#include "citadel/assert.h"
#include "citadel/export.h"

#include "citadel/time/timer.h"

namespace citadel
{
	template<typename R, typename... Arguments>
	class benchmarker
	{
	public:
		using function_t = std::function<R(Arguments...)>;

	public:
		benchmarker(const std::string& name)
			: name_(name) { }

		benchmarker(const std::string& name, function_t&& function)
			: name_(name), function_(std::move(function)) { }

		~benchmarker() = default;

		CITADEL_GETTER bool is_good() const noexcept;
		R execute(Arguments... arguments);

		template<typename Duration>
		CITADEL_GETTER Duration duration() const;

		template<typename Rep, typename Period>
		CITADEL_GETTER std::chrono::duration<Rep, Period> duration() const;

		void set_function(function_t&& value);

	private:
		std::string name_;
		function_t function_;

		timer timer_;
	};
}

#include "citadel/profiling/benchmarker.inl"
