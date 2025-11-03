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

#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/logging/log_level.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported logger {
	public:
		logger(const std::string& name, log_level level);
		logger(const std::string& name);

		void log(const std::string& message, log_level level) const;

		nodisc bool is_level_valid(log_level value) const noexcept;
		nodisc bool is_off() const noexcept;

		nodisc const std::string& get_name() const noexcept;

		nodisc log_level get_level() const noexcept;
		void set_level(log_level value) noexcept;

	private:
		std::string name_;
		log_level level_;
	};
}

CITADEL_WARNING_IGNORE_POP
