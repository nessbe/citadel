// File:       engine.cpp
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

#include "citadel/pch.hpp"
#include "citadel/core/engine.hpp"

#include "citadel/io/console/console.hpp"

namespace citadel {
	void engine::initialize() {
		sink_reference console_sink = make_referenced<sink>(console::pointer());
		this_logger::initialize("CITADEL", log_level::debug);
		this_logger::push_sink(console_sink);

		this_logger::log("Citadel core logger initialized successfully", log_level::trace);
	}

	exit_code engine::run() {
		return exit_code::success;
	}

	void engine::shutdown() { }
}
