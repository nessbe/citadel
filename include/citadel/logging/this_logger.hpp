// File:       this_logger.hpp
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

#include <initializer_list>
#include <mutex>
#include <string>
#include <unordered_map>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/sinks/sink.hpp"

#include "citadel/logging/log_level.hpp"
#include "citadel/logging/logger.hpp"

#include "citadel/memory/reference.hpp"

namespace citadel {
	namespace this_logger {
		inline thread_local reference<logger> current;

		inline std::mutex& mutex();
		inline std::unordered_map<std::string, reference<logger>>& instances();

		inline logger& initialize(const std::string& name);

		inline logger& get();
		inline bool set(const std::string& name);

		inline void log(const std::string& message, log_level level);

		inline void log_debug(const std::string& message);
		inline void log_trace(const std::string& message);
		inline void log_info(const std::string& message);
		inline void log_warning(const std::string& message);
		inline void log_error(const std::string& message);
		inline void log_fatal(const std::string& message);

		nodisc inline bool is_level_valid(log_level level) noexcept;
		nodisc inline bool is_off() noexcept;

		nodisc inline const std::vector<sink_reference>& get_sinks() noexcept;
		nodisc inline std::size_t sink_count() noexcept;

		inline void push_sink(const sink_reference& sink);
		inline void clear_sinks();

		nodisc inline const std::string& get_name() noexcept;

		nodisc inline log_level get_level() noexcept;
		inline void set_level(log_level value) noexcept;
	}
}

#include "citadel/logging/this_logger.inl"
