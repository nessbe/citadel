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

#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/logging/log_level.hpp"
#include "citadel/logging/logger.hpp"

namespace citadel {
	namespace detail {
		extern logger this_logger;
	}

	namespace this_logger {
		exported void initialize(const std::string& name, log_level level);
		exported void initialize(const std::string& name);

		exported constexpr inline logger& get() noexcept;

		exported void log(const std::string& message, log_level level);

		nodisc exported bool is_level_valid(log_level level) noexcept;
		nodisc exported bool is_off() noexcept;

		nodisc exported const std::string& get_name() noexcept;

		nodisc exported log_level get_level() noexcept;
		exported void set_level(log_level value) noexcept;
	}
}
