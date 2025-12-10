// File:       logger.cpp
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
#include "citadel/logging/logger.hpp"

namespace citadel {
	logger::logger(const std::string& name, log_level level, std::initializer_list<sink_reference> sinks)
		: sinks_(sinks), name_(name), level_(level) { }

	logger::logger(const std::string& name, std::initializer_list<sink_reference> sinks)
		: logger(name, log_level::debug, sinks) { }

	void logger::log(const std::string& message, log_level level) const {
		if (is_off()) {
			return;
		}

		if (!is_level_valid(level)) {
			return;
		}

		std::ostringstream out;
		out << "[" << name_ << "] ";
		out << "[" << level << "] ";
		out << message << std::endl;

		std::string formatted_message = out.str();
		const char* formatted_message_buffer = formatted_message.data();
		std::size_t formatted_message_size = formatted_message.size();

		for (const sink_reference& sink : sinks_) {
			CITADEL_POINTER_CALL(sink, write, formatted_message_buffer, static_cast<stream::size_type>(formatted_message_size));
		}
	}

	bool logger::is_level_valid(log_level value) const noexcept {
		return value >= level_;
	}

	bool logger::is_off() const noexcept {
		return level_ >= log_level::off;
	}

	const std::vector<sink_reference>& logger::get_sinks() const noexcept {
		return sinks_;
	}

	std::size_t logger::sink_count() const noexcept {
		return sinks_.size();
	}

	void logger::push_sink(const sink_reference& sink) {
		sinks_.push_back(sink);
	}

	void logger::clear_sinks() {
		sinks_.clear();
	}

	const std::string& logger::get_name() const noexcept {
		return name_;
	}

	log_level logger::get_level() const noexcept {
		return level_;
	}

	void logger::set_level(log_level value) noexcept {
		level_ = value;
	}
}
