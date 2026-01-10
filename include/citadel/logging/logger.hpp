// File:       logger.hpp
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

#include <initializer_list>
#include <string>
#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/io/sinks/sink.hpp"

#include "citadel/logging/log_level.hpp"
#include "citadel/logging/log_level_palette.hpp"
#include "citadel/logging/log_message.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class CITADEL_API logger {
	public:
		logger(const std::string& name, log_level level, std::initializer_list<sink_reference> sinks = { });
		logger(const std::string& name, std::initializer_list<sink_reference> sinks = { });

		template <typename... Arguments>
		std::string format_message(const log_message<Arguments...>& message) const;

		template <typename... Arguments>
		void log(log_level level, const std::string& message, Arguments&&... arguments) const;

		template <typename... Arguments>
		void log_debug(const std::string& message, Arguments&&... arguments) const;

		template <typename... Arguments>
		void log_trace(const std::string& message, Arguments&&... arguments) const;

		template <typename... Arguments>
		void log_info(const std::string& message, Arguments&&... arguments) const;

		template <typename... Arguments>
		void log_warning(const std::string& message, Arguments&&... arguments) const;

		template <typename... Arguments>
		void log_error(const std::string& message, Arguments&&... arguments) const;

		template <typename... Arguments>
		void log_fatal(const std::string& message, Arguments&&... arguments) const;

		CITADEL_NODISCARD bool is_level_valid(log_level value) const noexcept;
		CITADEL_NODISCARD bool is_off() const noexcept;

		CITADEL_NODISCARD log_level_palette& palette() noexcept;

		CITADEL_NODISCARD const std::string& get_name() const noexcept;

		CITADEL_NODISCARD const std::vector<sink_reference>& get_sinks() const noexcept;
		CITADEL_NODISCARD std::size_t sink_count() const noexcept;

		void push_sink(const sink_reference& sink);
		void clear_sinks();

		CITADEL_NODISCARD log_level get_level() const noexcept;
		void set_level(log_level value) noexcept;

	private:
		log_level_palette palette_;

		std::string name_;
		std::vector<sink_reference> sinks_;
		log_level level_;

	private:
		template <typename... Arguments>
		void log(const log_message<Arguments...>& message) const;
	};
}

CITADEL_WARNING_IGNORE_POP

#include "citadel/logging/logger.inl"
