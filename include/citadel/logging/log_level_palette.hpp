// File:       log_level_palette.hpp
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

#include <unordered_map>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/formats/ansi/ansi_color.hpp"

#include "citadel/logging/log_level.hpp"

namespace citadel {
	class log_level_palette {
	public:
		static log_level_palette placeholder();

		log_level_palette(const std::unordered_map<log_level, ansi_color>& palette);
		log_level_palette();

		nodisc const ansi_color& get(log_level key) const;
		void set(log_level key, const ansi_color& value);

		nodisc ansi_color& operator[](log_level key);

	private:
		std::unordered_map<log_level, ansi_color> palette_;
	};
}
