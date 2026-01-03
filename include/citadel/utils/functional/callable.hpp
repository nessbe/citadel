// File:       callable.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#include "citadel/attributes.hpp"

namespace citadel {
	template <typename T>
	class callable;

	template <typename Result, typename... Arguments>
	class callable<Result(Arguments...)> {
	public:
		virtual ~callable() = default;

		Result call(Arguments&&... arguments);
		nodisc bool valid() const noexcept;

		Result operator()(Arguments&&... arguments);

	private:
		virtual Result _call(Arguments&&... arguments) = 0;
		nodisc virtual bool _valid() const noexcept = 0;
	};
}

#include "citadel/utils/functional/callable.inl"
