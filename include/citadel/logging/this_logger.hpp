// File:       this_logger.hpp
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

#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/sinks/sink.hpp"

#include "citadel/logging/log_level.hpp"
#include "citadel/logging/log_level_palette.hpp"
#include "citadel/logging/logger.hpp"

#include "citadel/memory/reference.hpp"

namespace citadel {
	namespace this_logger {
		inline std::string current;

		inline logger& get();
		inline void set(const std::string& name);

		template <typename... Arguments>
		inline void log(const std::string& message, log_level level, Arguments&&... arguments);

		template <typename... Arguments>
		inline void log_debug(const std::string& message, Arguments&&... arguments);

		template <typename... Arguments>
		inline void log_trace(const std::string& message, Arguments&&... arguments);

		template <typename... Arguments>
		inline void log_info(const std::string& message, Arguments&&... arguments);

		template <typename... Arguments>
		inline void log_warning(const std::string& message, Arguments&&... arguments);

		template <typename... Arguments>
		inline void log_error(const std::string& message, Arguments&&... arguments);

		template <typename... Arguments>
		inline void log_fatal(const std::string& message, Arguments&&... arguments);

		CITADEL_NODISCARD CITADEL_API bool is_level_valid(log_level level);
		CITADEL_NODISCARD CITADEL_API bool is_off();

		CITADEL_NODISCARD CITADEL_API log_level_palette& palette();

		CITADEL_NODISCARD CITADEL_API const std::string& get_name();

		CITADEL_NODISCARD CITADEL_API const std::vector<sink_reference>& get_sinks();
		CITADEL_NODISCARD CITADEL_API std::size_t sink_count();

		CITADEL_API void push_sink(const sink_reference& sink);
		CITADEL_API void clear_sinks();

		CITADEL_NODISCARD CITADEL_API log_level get_level();
		CITADEL_API void set_level(log_level value);
	}
}

#include "citadel/logging/this_logger.inl"
