// File:       ansi_colors.hpp
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

#include "citadel/export.hpp"

#include "citadel/formats/ansi/ansi_color.hpp"

namespace citadel {
	namespace ansi_colors {
		exported extern const ansi_color placeholder;
		exported extern const ansi_color reset;

		exported extern const ansi_color black;
		exported extern const ansi_color red;
		exported extern const ansi_color green;
		exported extern const ansi_color yellow;
		exported extern const ansi_color blue;
		exported extern const ansi_color purple;
		exported extern const ansi_color cyan;
		exported extern const ansi_color white;

		exported extern const ansi_color bold_black;
		exported extern const ansi_color bold_red;
		exported extern const ansi_color bold_green;
		exported extern const ansi_color bold_yellow;
		exported extern const ansi_color bold_blue;
		exported extern const ansi_color bold_purple;
		exported extern const ansi_color bold_cyan;
		exported extern const ansi_color bold_white;

		exported extern const ansi_color underline_black;
		exported extern const ansi_color underline_red;
		exported extern const ansi_color underline_green;
		exported extern const ansi_color underline_yellow;
		exported extern const ansi_color underline_blue;
		exported extern const ansi_color underline_purple;
		exported extern const ansi_color underline_cyan;
		exported extern const ansi_color underline_white;

		exported extern const ansi_color background_black;
		exported extern const ansi_color background_red;
		exported extern const ansi_color background_green;
		exported extern const ansi_color background_yellow;
		exported extern const ansi_color background_blue;
		exported extern const ansi_color background_purple;
		exported extern const ansi_color background_cyan;
		exported extern const ansi_color background_white;

		exported extern const ansi_color high_intensity_black;
		exported extern const ansi_color high_intensity_red;
		exported extern const ansi_color high_intensity_green;
		exported extern const ansi_color high_intensity_yellow;
		exported extern const ansi_color high_intensity_blue;
		exported extern const ansi_color high_intensity_purple;
		exported extern const ansi_color high_intensity_cyan;
		exported extern const ansi_color high_intensity_white;

		exported extern const ansi_color bold_high_intensity_black;
		exported extern const ansi_color bold_high_intensity_red;
		exported extern const ansi_color bold_high_intensity_green;
		exported extern const ansi_color bold_high_intensity_yellow;
		exported extern const ansi_color bold_high_intensity_blue;
		exported extern const ansi_color bold_high_intensity_purple;
		exported extern const ansi_color bold_high_intensity_cyan;
		exported extern const ansi_color bold_high_intensity_white;

		exported extern const ansi_color high_intensity_background_black;
		exported extern const ansi_color high_intensity_background_red;
		exported extern const ansi_color high_intensity_background_green;
		exported extern const ansi_color high_intensity_background_yellow;
		exported extern const ansi_color high_intensity_background_blue;
		exported extern const ansi_color high_intensity_background_purple;
		exported extern const ansi_color high_intensity_background_cyan;
		exported extern const ansi_color high_intensity_background_white;
	}
}
