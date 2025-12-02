// File:       file_open_mode.hpp
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

#include <cinttypes>
#include <ios>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	namespace file_open_mode {
		using type = std::uint8_t;

		enum enumeration : type {
			read = 0,
			write,
			read_write,
			write_read,
		};

		nodisc exported std::ios::openmode to_stl(enumeration value);

		nodisc exported bool use_read(enumeration value);
		nodisc exported bool use_write(enumeration value);
	}
}
