// File:       logger.hpp
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
#include <string>
#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/io/sinks/sink.hpp"

#include "citadel/logging/log_level.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported logger {
	public:
		logger(const std::string& name, log_level level, std::initializer_list<sink_reference> sinks = { });
		logger(const std::string& name, std::initializer_list<sink_reference> sinks = { });

		template <typename... Arguments>
		std::string format_message(const std::string& message, Arguments&&... arguments) const;

		std::string enrich_message(const std::string& message, log_level level) const;

		template <typename... Arguments>
		void log(const std::string& message, log_level level, Arguments&&... arguments) const;

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

		nodisc bool is_level_valid(log_level value) const noexcept;
		nodisc bool is_off() const noexcept;

		nodisc const std::vector<sink_reference>& get_sinks() const noexcept;
		nodisc std::size_t sink_count() const noexcept;

		void push_sink(const sink_reference& sink);
		void clear_sinks();

		nodisc const std::string& get_name() const noexcept;

		nodisc log_level get_level() const noexcept;
		void set_level(log_level value) noexcept;

	private:
		std::string name_;
		std::vector<sink_reference> sinks_;
		log_level level_;
	};
}

CITADEL_WARNING_IGNORE_POP

#include "citadel/logging/logger.inl"
