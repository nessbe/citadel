// File:       handle_factory.hpp
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

#include <cinttypes>

#include "citadel/attributes.hpp"

#include "citadel/core/handles/handle.hpp"

namespace citadel {
	template <typename Tag, typename Policy>
	class handle_factory {
	public:
		using handle_type = handle<Tag, typename Policy::value_type>;

	public:
		CITADEL_NODISCARD handle_type acquire();
		void release(handle_type handle);

	private:
		Policy policy_;
	};
}

#include "citadel/core/handles/handle_factory.inl"
