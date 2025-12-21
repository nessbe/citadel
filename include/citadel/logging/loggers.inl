// File:       loggers.inl
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

namespace citadel {
	template <typename... Arguments>
	void loggers::log(const std::string& name, log_level level, const std::string& message, Arguments&&... arguments) {
		get(name).log(level, message, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void loggers::log_debug(const std::string& name, const std::string& message, Arguments&&... arguments) {
		get(name).log_debug(message, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void loggers::log_trace(const std::string& name, const std::string& message, Arguments&&... arguments) {
		get(name).log_trace(message, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void loggers::log_info(const std::string& name, const std::string& message, Arguments&&... arguments) {
		get(name).log_info(message, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void loggers::log_warning(const std::string& name, const std::string& message, Arguments&&... arguments) {
		get(name).log_warning(message, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void loggers::log_error(const std::string& name, const std::string& message, Arguments&&... arguments) {
		get(name).log_error(message, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void loggers::log_fatal(const std::string& name, const std::string& message, Arguments&&... arguments) {
		get(name).log_fatal(message, std::forward<Arguments>(arguments)...);
	}
}
