// File:       event.hpp
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
#include "citadel/export.hpp"

namespace citadel {
	class CITADEL_API event {
	public:
		virtual ~event() = default;

		CITADEL_NODISCARD bool consumed() const noexcept;
		void consume() noexcept;

	private:
		bool consumed_ = false;

	private:
		virtual void _consume() noexcept = 0;
	};
}
