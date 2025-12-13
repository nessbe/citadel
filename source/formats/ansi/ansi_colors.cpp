// File:       ansi_colors.cpp
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
#include "citadel/formats/ansi/ansi_colors.hpp"

#include "citadel/formats/ansi/ansi_color_mode.hpp"
#include "citadel/formats/ansi/ansi_color_type.hpp"

namespace citadel {
	const ansi_color ansi_colors::reset(ansi_color_type::reset);

	const ansi_color ansi_colors::black(ansi_color_type::black);
	const ansi_color ansi_colors::red(ansi_color_type::red);
	const ansi_color ansi_colors::green(ansi_color_type::green);
	const ansi_color ansi_colors::yellow(ansi_color_type::yellow);
	const ansi_color ansi_colors::blue(ansi_color_type::blue);
	const ansi_color ansi_colors::purple(ansi_color_type::purple);
	const ansi_color ansi_colors::cyan(ansi_color_type::cyan);
	const ansi_color ansi_colors::white(ansi_color_type::white);

	const ansi_color ansi_colors::bold_black(ansi_color_type::black, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_red(ansi_color_type::red, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_green(ansi_color_type::green, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_yellow(ansi_color_type::yellow, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_blue(ansi_color_type::blue, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_purple(ansi_color_type::purple, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_cyan(ansi_color_type::cyan, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_white(ansi_color_type::white, ansi_color_style::bold);

	const ansi_color ansi_colors::underline_black(ansi_color_type::black, ansi_color_style::underline);
	const ansi_color ansi_colors::underline_red(ansi_color_type::red, ansi_color_style::underline);
	const ansi_color ansi_colors::underline_green(ansi_color_type::green, ansi_color_style::underline);
	const ansi_color ansi_colors::underline_yellow(ansi_color_type::yellow, ansi_color_style::underline);
	const ansi_color ansi_colors::underline_blue(ansi_color_type::blue, ansi_color_style::underline);
	const ansi_color ansi_colors::underline_purple(ansi_color_type::purple, ansi_color_style::underline);
	const ansi_color ansi_colors::underline_cyan(ansi_color_type::cyan, ansi_color_style::underline);
	const ansi_color ansi_colors::underline_white(ansi_color_type::white, ansi_color_style::underline);

	const ansi_color ansi_colors::background_black(ansi_color_type::black, ansi_color_mode::background);
	const ansi_color ansi_colors::background_red(ansi_color_type::red, ansi_color_mode::background);
	const ansi_color ansi_colors::background_green(ansi_color_type::green, ansi_color_mode::background);
	const ansi_color ansi_colors::background_yellow(ansi_color_type::yellow, ansi_color_mode::background);
	const ansi_color ansi_colors::background_blue(ansi_color_type::blue, ansi_color_mode::background);
	const ansi_color ansi_colors::background_purple(ansi_color_type::purple, ansi_color_mode::background);
	const ansi_color ansi_colors::background_cyan(ansi_color_type::cyan, ansi_color_mode::background);
	const ansi_color ansi_colors::background_white(ansi_color_type::white, ansi_color_mode::background);

	const ansi_color ansi_colors::high_intensity_black(ansi_color_type::black, ansi_color_mode::high_intensity);
	const ansi_color ansi_colors::high_intensity_red(ansi_color_type::red, ansi_color_mode::high_intensity);
	const ansi_color ansi_colors::high_intensity_green(ansi_color_type::green, ansi_color_mode::high_intensity);
	const ansi_color ansi_colors::high_intensity_yellow(ansi_color_type::yellow, ansi_color_mode::high_intensity);
	const ansi_color ansi_colors::high_intensity_blue(ansi_color_type::blue, ansi_color_mode::high_intensity);
	const ansi_color ansi_colors::high_intensity_purple(ansi_color_type::purple, ansi_color_mode::high_intensity);
	const ansi_color ansi_colors::high_intensity_cyan(ansi_color_type::cyan, ansi_color_mode::high_intensity);
	const ansi_color ansi_colors::high_intensity_white(ansi_color_type::white, ansi_color_mode::high_intensity);

	const ansi_color ansi_colors::bold_high_intensity_black(ansi_color_type::black, ansi_color_mode::high_intensity, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_high_intensity_red(ansi_color_type::red, ansi_color_mode::high_intensity, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_high_intensity_green(ansi_color_type::green, ansi_color_mode::high_intensity, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_high_intensity_yellow(ansi_color_type::yellow, ansi_color_mode::high_intensity, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_high_intensity_blue(ansi_color_type::blue, ansi_color_mode::high_intensity, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_high_intensity_purple(ansi_color_type::purple, ansi_color_mode::high_intensity, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_high_intensity_cyan(ansi_color_type::cyan, ansi_color_mode::high_intensity, ansi_color_style::bold);
	const ansi_color ansi_colors::bold_high_intensity_white(ansi_color_type::white, ansi_color_mode::high_intensity, ansi_color_style::bold);

	const ansi_color ansi_colors::high_intensity_background_black(ansi_color_type::black, ansi_color_mode::high_intensity | ansi_color_mode::background);
	const ansi_color ansi_colors::high_intensity_background_red(ansi_color_type::red, ansi_color_mode::high_intensity | ansi_color_mode::background);
	const ansi_color ansi_colors::high_intensity_background_green(ansi_color_type::green, ansi_color_mode::high_intensity | ansi_color_mode::background);
	const ansi_color ansi_colors::high_intensity_background_yellow(ansi_color_type::yellow, ansi_color_mode::high_intensity | ansi_color_mode::background);
	const ansi_color ansi_colors::high_intensity_background_blue(ansi_color_type::blue, ansi_color_mode::high_intensity | ansi_color_mode::background);
	const ansi_color ansi_colors::high_intensity_background_purple(ansi_color_type::purple, ansi_color_mode::high_intensity | ansi_color_mode::background);
	const ansi_color ansi_colors::high_intensity_background_cyan(ansi_color_type::cyan, ansi_color_mode::high_intensity | ansi_color_mode::background);
	const ansi_color ansi_colors::high_intensity_background_white(ansi_color_type::white, ansi_color_mode::high_intensity | ansi_color_mode::background);
}
