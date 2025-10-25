// File:       application.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#include <memory>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/core/engine.hpp"
#include "citadel/core/exit_code.hpp"

namespace citadel {
	class api application {
	public:
		application() = default;
		virtual ~application() = default;

		void initialize();
		exit_code::enumeration run();
		void shutdown();

		nodisc engine& get_engine() const;

	private:
		std::unique_ptr<engine> engine_ = nullptr;

	private:
		virtual void _initialize() = 0;
		virtual exit_code::enumeration _run() = 0;
		virtual void _shutdown() = 0;
	};

	application* create_application();
}
