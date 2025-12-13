// File:       this_logger.inl
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

#include <type_traits>

#include "citadel/pointers.hpp"

#include "citadel/logging/loggers.hpp"

namespace citadel {
	logger& this_logger::get() {
		return loggers::get(current);
	}

	void this_logger::set(const std::string& name) {
		current = name;
	}

	template <typename... Arguments>
	void this_logger::log(const std::string& name, log_level level, Arguments&&... arguments) {
		get().log(name, level, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void this_logger::log_debug(const std::string& message, Arguments&&... arguments) {
		get().log_debug(message, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void this_logger::log_trace(const std::string& message, Arguments&&... arguments) {
		get().log_trace(message, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void this_logger::log_info(const std::string& message, Arguments&&... arguments) {
		get().log_info(message, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void this_logger::log_warning(const std::string& message, Arguments&&... arguments) {
		get().log_warning(message, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void this_logger::log_error(const std::string& message, Arguments&&... arguments) {
		get().log_error(message, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void this_logger::log_fatal(const std::string& message, Arguments&&... arguments) {
		get().log_fatal(message, std::forward<Arguments>(arguments)...);
	}
}
