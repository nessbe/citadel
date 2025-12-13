// File:       ansi_color.hpp
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

#include <ostream>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	class exported ansi_color {
	public:
		ansi_color(const std::string& code);

		nodisc const std::string& code() const noexcept;

	private:
		std::string code_;
	};

	std::ostream& operator<<(std::ostream& out, const ansi_color& value);
}
