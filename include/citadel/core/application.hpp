// File:       application.hpp
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

#include <cstddef>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/core/engine.hpp"
#include "citadel/core/exit_code.hpp"

#include "citadel/memory/scope.hpp"

namespace citadel {
	int run_application(int argc, char** argv);

	class CITADEL_API application {
	public:
		friend int run_application(int argc, char** argv);

	public:
		CITADEL_NODISCARD static application& get();

		application() = default;
		virtual ~application() = default;

		application(const application&) = delete;
		application & operator=(const application&) = delete;

		void initialize();
		exit_code run();
		void shutdown();

		CITADEL_NORETURN void exit(exit_code code);

		CITADEL_NODISCARD std::size_t get_error_level() const noexcept;
		void notify_error() noexcept;

		CITADEL_NODISCARD engine& engine() const;

	private:
		static application* instance_;

		std::size_t error_level_ = 0;

		scope<class engine> engine_ = nullptr;

	private:
		virtual void _initialize() = 0;
		virtual exit_code _run() = 0;
		virtual void _shutdown() = 0;
	};

	application* create_application();
}
