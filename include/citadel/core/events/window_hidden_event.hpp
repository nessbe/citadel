// File:       window_hidden_event.hpp
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
#include "citadel/warnings.hpp"

#include "citadel/core/display/window.hpp"

#include "citadel/core/events/event.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class CITADEL_API window_hidden_event final : public event {
	public:
		explicit window_hidden_event(window_handle window);

		CITADEL_NODISCARD window_handle window() const noexcept;

	private:
		window_handle window_;

	private:
		virtual void _consume() noexcept override;
	};
}

CITADEL_WARNING_IGNORE_POP
