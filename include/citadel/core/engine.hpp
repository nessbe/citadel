// File:       engine.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#include "citadel/export.hpp"

#include "citadel/core/exit_code.hpp"

namespace citadel {
	class CITADEL_API engine {
	public:
		engine() = default;
		~engine() = default;

		void initialize();
		exit_code run();
		void shutdown();
	};
}
