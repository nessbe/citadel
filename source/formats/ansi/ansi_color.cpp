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

	ansi_color::ansi_color(ansi_color_type type, ansi_color_mode mode, ansi_color_style style) {
		std::uint8_t color_code = static_cast<std::uint8_t>(type);
		std::uint8_t style_code = static_cast<std::uint8_t>(style);

		if (type != ansi_color_type::reset) {
			if (static_cast<std::uint8_t>(mode & ansi_color_mode::background) > 0) {
				color_code += ansi_background_signature;
			}

			if (static_cast<std::uint8_t>(mode & ansi_color_mode::high_intensity) > 0) {
				color_code += ansi_high_intensity_signature;
			}
		}

		formatter formatter("\033[{0};{1}m");
		code_ = formatter.format(style_code, color_code);
	}

	ansi_color::ansi_color(ansi_color_type type, ansi_color_style style)
		: ansi_color(type, ansi_color_mode::none, style) { }

	ansi_color::ansi_color(ansi_color_type type, ansi_color_mode mode)
		: ansi_color(type, mode, ansi_color_style::none) { }

	ansi_color::ansi_color(ansi_color_type type)
		: ansi_color(type, ansi_color_mode::none, ansi_color_style::none) { }

	const std::string& ansi_color::code() const noexcept {
		return code_;
	}

	std::ostream& operator<<(std::ostream& out, const ansi_color& value) {
		return out << value.code();
	}
}
