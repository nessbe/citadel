// File:       logger.inl
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

#include "citadel/utils/format/formatter.hpp"

namespace citadel {
	template <typename... Arguments>
	std::string logger::format_message(const std::string& message, Arguments&&... arguments) const {
		formatter formatter(message);
		return formatter.format(std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void logger::log(const std::string& message, log_level level, Arguments&&... arguments) const {
		if (is_off()) {
			return;
		}

		if (!is_level_valid(level)) {
			return;
		}

		std::string formatted_message = format_message(message, std::forward<Arguments>(arguments)...);
		std::string enriched_message = enrich_message(formatted_message, level);

		const char* message_buffer = enriched_message.data();
		std::size_t message_size = enriched_message.size();

		for (const sink_reference& sink : sinks_) {
			CITADEL_POINTER_CALL(sink, write, message_buffer, static_cast<stream::size_type>(message_size));
		}
	}

	template <typename... Arguments>
	void logger::log_debug(const std::string& message, Arguments&&... arguments) const {
		log(message, log_level::debug, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void logger::log_trace(const std::string& message, Arguments&&... arguments) const {
		log(message, log_level::trace, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void logger::log_info(const std::string& message, Arguments&&... arguments) const {
		log(message, log_level::info, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void logger::log_warning(const std::string& message, Arguments&&... arguments) const {
		log(message, log_level::warning, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void logger::log_error(const std::string& message, Arguments&&... arguments) const {
		log(message, log_level::error, std::forward<Arguments>(arguments)...);
	}

	template <typename... Arguments>
	void logger::log_fatal(const std::string& message, Arguments&&... arguments) const {
		log(message, log_level::fatal, std::forward<Arguments>(arguments)...);
	}
}
