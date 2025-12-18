// File:       log_level_palette.cpp
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
#include "citadel/logging/log_level_palette.hpp"

namespace citadel {
	log_level_palette log_level_palette::placeholder() {
		return log_level_palette({
			{ log_level::debug, ansi_colors::cyan },
			{ log_level::trace, ansi_colors::high_intensity_black },
			{ log_level::info, ansi_colors::green },
			{ log_level::warning, ansi_colors::yellow },
			{ log_level::error, ansi_colors::red },
			{ log_level::fatal, ansi_colors::high_intensity_red },
		});
	}

	log_level_palette::log_level_palette(const std::unordered_map<log_level, ansi_color>& palette)
		: palette_(palette)
	{
		CITADEL_SOFT_ASSERT(palette_.size() == log_levels.size(), "Failed to initialize log level palette successfully");
	}

	log_level_palette::log_level_palette()
		: log_level_palette(std::unordered_map<log_level, ansi_color>()) { }

	const ansi_color& log_level_palette::get(log_level key) const {
		return palette_.at(key);
	}

	void log_level_palette::set(log_level key, const ansi_color& value) {
		if (palette_.find(key) != palette_.end()) {
			palette_[key] = value;
		}
	}

	ansi_color& log_level_palette::operator[](log_level key) {
		return palette_[key];
	}
}
