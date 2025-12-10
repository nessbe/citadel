// File:       this_logger.cpp
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
#include "citadel/logging/this_logger.hpp"

namespace citadel {
	logger detail::this_logger("CITADEL", log_level::debug);

	void this_logger::initialize(const std::string& name, log_level level, std::initializer_list<sink_reference> sinks) {
		detail::this_logger = { name, level, sinks };
	}

	void this_logger::initialize(const std::string& name, std::initializer_list<sink_reference> sinks) {
		detail::this_logger = { name, sinks };
	}

	constexpr logger& this_logger::get() noexcept {
		return detail::this_logger;
	}

	void this_logger::log(const std::string& name, log_level level) {
		get().log(name, level);
	}

	bool this_logger::is_level_valid(log_level level) noexcept {
		return get().is_level_valid(level);
	}

	bool this_logger::is_off() noexcept {
		return get().is_off();
	}

	const std::string& this_logger::get_name() noexcept {
		return get().get_name();
	}

	const std::vector<sink_reference>& this_logger::get_sinks() noexcept {
		return get().get_sinks();
	}

	std::size_t this_logger::sink_count() noexcept {
		return get().sink_count();
	}

	void this_logger::push_sink(const sink_reference& sink) {
		get().push_sink(sink);
	}

	void this_logger::clear_sinks() {
		get().clear_sinks();
	}

	log_level this_logger::get_level() noexcept {
		return get().get_level();
	}

	void this_logger::set_level(log_level value) noexcept {
		return get().set_level(value);
	}
}
