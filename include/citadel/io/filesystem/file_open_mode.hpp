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
	enum class file_open_mode : std::uint8_t {
		read = 0,
		write,
		read_write,
		write_read,
	};

	nodisc exported std::ios::openmode file_open_mode_to_stl(file_open_mode value) noexcept;

	nodisc exported bool file_open_mode_use_read(file_open_mode value) noexcept;
	nodisc exported bool file_open_mode_use_write(file_open_mode value) noexcept;
}
