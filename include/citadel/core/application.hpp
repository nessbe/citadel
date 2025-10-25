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

#include <cstddef>
#include <memory>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/core/engine.hpp"
#include "citadel/core/exit_code.hpp"

namespace citadel {
	int run_application(int argc, char** argv);

	class api application {
	public:
		friend int run_application(int argc, char** argv);

	public:
		nodisc static application& get();

		application() = default;
		virtual ~application() = default;

		void initialize();
		exit_code::enumeration run();
		void shutdown();

		noret void exit(exit_code::enumeration code);

		nodisc std::size_t get_error_level() const noexcept;
		void notify_error() noexcept;

		nodisc engine& get_engine() const;

	private:
		static application* instance_;

		std::size_t error_level_ = 0;

		std::unique_ptr<engine> engine_ = nullptr;

	private:
		virtual void _initialize() = 0;
		virtual exit_code::enumeration _run() = 0;
		virtual void _shutdown() = 0;
	};

	application* create_application();
}
