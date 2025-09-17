// File:        function_callable.h
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

#include <functional>

#include "citadel/attributes.h"

#include "citadel/functional/callable.h"

namespace citadel
{
	template<typename Signature>
	class function_callable;

	template<typename R, typename... Arguments>
	class function_callable<R(Arguments...)> : public callable<R(Arguments...)>
	{
	public:
		using function_t = std::function<R(Arguments...)>;

	public:
		function_callable(const function_t& function)
			: function_(function) { }

		function_callable(function_t&& function)
			: function_(std::move(function)) { }

		virtual ~function_callable() override = default;

		virtual R call(Arguments... arguments) override;
		CITADEL_NODISCARD virtual operator bool() const noexcept override;

	private:
		function_t function_;
	};
}

#include "citadel/functional/function_callable.inl"
