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
	logger::logger(const std::string& name, log_level level)
		: name_(name), level_(level) { }

	logger::logger(const std::string& name)
		: logger(name, log_level::debug) { }

	void logger::log(const std::string& message, log_level level) const {
		if (is_off()) {
			return;
		}

		if (!is_level_valid(level)) {
			return;
		}

		std::cout << "[" << name_ << "] ";
		std::cout << "[" << level << "] ";
		std::cout << message << std::endl;
	}

	bool logger::is_level_valid(log_level value) const noexcept {
		return value >= level_;
	}

	bool logger::is_off() const noexcept {
		return level_ >= log_level::off;
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
