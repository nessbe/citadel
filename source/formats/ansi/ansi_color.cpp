// File:       ansi_color.cpp
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
#include "citadel/formats/ansi/ansi_color.hpp"

namespace citadel {
	ansi_color::ansi_color(const std::string& code)
		: code_(code) { }

	const std::string& ansi_color::code() const noexcept {
		return code_;
	}

	std::ostream& operator<<(std::ostream& out, const ansi_color& value) {
		return out << value.code();
	}
}
