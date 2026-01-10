// File:       loggers.hpp
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

#include <mutex>
#include <string>
#include <unordered_map>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/logging/log_level.hpp"
#include "citadel/logging/log_level_palette.hpp"
#include "citadel/logging/logger.hpp"

#include "citadel/memory/reference.hpp"

namespace citadel {
	namespace loggers {
		CITADEL_NODISCARD CITADEL_API std::unordered_map<std::string, reference<logger>>& instances() noexcept;
		CITADEL_NODISCARD CITADEL_API std::mutex& mutex() noexcept;

		CITADEL_NODISCARD CITADEL_API logger& get(const std::string& name);
		CITADEL_API logger& add(const std::string& name);

		template <typename... Arguments>
		inline void log(const std::string& name, log_level level, const std::string& message, Arguments&&... arguments);

		template <typename... Arguments>
		inline void log_debug(const std::string& name, const std::string& message, Arguments&&... arguments);

		template <typename... Arguments>
		inline void log_trace(const std::string& name,const std::string& message, Arguments&&... arguments);

		template <typename... Arguments>
		inline void log_info(const std::string& name, const std::string& message, Arguments&&... arguments);

		template <typename... Arguments>
		inline void log_warning(const std::string& name, const std::string& message, Arguments&&... arguments);

		template <typename... Arguments>
		inline void log_error(const std::string& name, const std::string& message, Arguments&&... arguments);

		template <typename... Arguments>
		inline void log_fatal(const std::string& name, const std::string& message, Arguments&&... arguments);

		CITADEL_NODISCARD CITADEL_API bool is_level_valid(const std::string& name, log_level level);
		CITADEL_NODISCARD CITADEL_API bool is_off(const std::string& name);

		CITADEL_NODISCARD CITADEL_API log_level_palette& palette(const std::string& name);

		CITADEL_NODISCARD CITADEL_API const std::string& get_name(const std::string& name);

		CITADEL_NODISCARD CITADEL_API const std::vector<sink_reference>& get_sinks(const std::string& name);
		CITADEL_NODISCARD CITADEL_API std::size_t sink_count(const std::string& name);

		CITADEL_API void push_sink(const std::string& name, const sink_reference& sink);
		CITADEL_API void clear_sinks(const std::string& name);

		CITADEL_NODISCARD CITADEL_API log_level get_level(const std::string& name);
		CITADEL_API void set_level(const std::string& name, log_level value);
	}
}

#include "citadel/logging/loggers.inl"
