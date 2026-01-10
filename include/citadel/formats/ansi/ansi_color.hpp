// File:       ansi_color.hpp
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

#include <ostream>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/formats/ansi/ansi_color_mode.hpp"
#include "citadel/formats/ansi/ansi_color_type.hpp"
#include "citadel/formats/ansi/ansi_color_style.hpp"

namespace citadel {
	class CITADEL_API ansi_color {
	public:
		ansi_color(ansi_color_type type, ansi_color_mode mode, ansi_color_style style);

		ansi_color(ansi_color_type type, ansi_color_style style);
		ansi_color(ansi_color_type type, ansi_color_mode mode);

		ansi_color(ansi_color_type type);
		ansi_color();

		CITADEL_NODISCARD ansi_color_type type() const noexcept;
		CITADEL_NODISCARD ansi_color_mode mode() const noexcept;
		CITADEL_NODISCARD ansi_color_style style() const noexcept;

		CITADEL_NODISCARD std::string escape() const;
		CITADEL_NODISCARD std::string code() const;

		ansi_color& operator|=(ansi_color_mode mode);

	private:
		ansi_color_type type_;
		ansi_color_mode mode_;
		ansi_color_style style_;
	};

	CITADEL_NODISCARD ansi_color operator|(const ansi_color& color, ansi_color_mode mode);
	std::ostream& operator<<(std::ostream& out, const ansi_color& value);
}
