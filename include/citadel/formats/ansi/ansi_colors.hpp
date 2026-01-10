// File:       ansi_colors.hpp
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

#include "citadel/export.hpp"

#include "citadel/formats/ansi/ansi_color.hpp"

namespace citadel {
	namespace ansi_colors {
		CITADEL_API extern const ansi_color placeholder;
		CITADEL_API extern const ansi_color reset;

		CITADEL_API extern const ansi_color black;
		CITADEL_API extern const ansi_color red;
		CITADEL_API extern const ansi_color green;
		CITADEL_API extern const ansi_color yellow;
		CITADEL_API extern const ansi_color blue;
		CITADEL_API extern const ansi_color purple;
		CITADEL_API extern const ansi_color cyan;
		CITADEL_API extern const ansi_color white;

		CITADEL_API extern const ansi_color bold_black;
		CITADEL_API extern const ansi_color bold_red;
		CITADEL_API extern const ansi_color bold_green;
		CITADEL_API extern const ansi_color bold_yellow;
		CITADEL_API extern const ansi_color bold_blue;
		CITADEL_API extern const ansi_color bold_purple;
		CITADEL_API extern const ansi_color bold_cyan;
		CITADEL_API extern const ansi_color bold_white;

		CITADEL_API extern const ansi_color underline_black;
		CITADEL_API extern const ansi_color underline_red;
		CITADEL_API extern const ansi_color underline_green;
		CITADEL_API extern const ansi_color underline_yellow;
		CITADEL_API extern const ansi_color underline_blue;
		CITADEL_API extern const ansi_color underline_purple;
		CITADEL_API extern const ansi_color underline_cyan;
		CITADEL_API extern const ansi_color underline_white;

		CITADEL_API extern const ansi_color background_black;
		CITADEL_API extern const ansi_color background_red;
		CITADEL_API extern const ansi_color background_green;
		CITADEL_API extern const ansi_color background_yellow;
		CITADEL_API extern const ansi_color background_blue;
		CITADEL_API extern const ansi_color background_purple;
		CITADEL_API extern const ansi_color background_cyan;
		CITADEL_API extern const ansi_color background_white;

		CITADEL_API extern const ansi_color high_intensity_black;
		CITADEL_API extern const ansi_color high_intensity_red;
		CITADEL_API extern const ansi_color high_intensity_green;
		CITADEL_API extern const ansi_color high_intensity_yellow;
		CITADEL_API extern const ansi_color high_intensity_blue;
		CITADEL_API extern const ansi_color high_intensity_purple;
		CITADEL_API extern const ansi_color high_intensity_cyan;
		CITADEL_API extern const ansi_color high_intensity_white;

		CITADEL_API extern const ansi_color bold_high_intensity_black;
		CITADEL_API extern const ansi_color bold_high_intensity_red;
		CITADEL_API extern const ansi_color bold_high_intensity_green;
		CITADEL_API extern const ansi_color bold_high_intensity_yellow;
		CITADEL_API extern const ansi_color bold_high_intensity_blue;
		CITADEL_API extern const ansi_color bold_high_intensity_purple;
		CITADEL_API extern const ansi_color bold_high_intensity_cyan;
		CITADEL_API extern const ansi_color bold_high_intensity_white;

		CITADEL_API extern const ansi_color high_intensity_background_black;
		CITADEL_API extern const ansi_color high_intensity_background_red;
		CITADEL_API extern const ansi_color high_intensity_background_green;
		CITADEL_API extern const ansi_color high_intensity_background_yellow;
		CITADEL_API extern const ansi_color high_intensity_background_blue;
		CITADEL_API extern const ansi_color high_intensity_background_purple;
		CITADEL_API extern const ansi_color high_intensity_background_cyan;
		CITADEL_API extern const ansi_color high_intensity_background_white;
	}
}
