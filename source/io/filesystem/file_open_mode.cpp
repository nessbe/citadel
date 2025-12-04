// File:       file_open_mode.cpp
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
#include "citadel/io/filesystem/file_open_mode.hpp"

namespace citadel {

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_UNREACHABLE_CODE)

	std::ios::openmode file_open_mode_to_stl(file_open_mode value) noexcept {
		switch (value) {
		case file_open_mode::read:
			return std::ios::in;

		case file_open_mode::write:
			return std::ios::out | std::ios::trunc;

		case file_open_mode::read_write:
			return std::ios::in | std::ios::out;

		case file_open_mode::write_read:
			return std::ios::in | std::ios::out | std::ios::trunc;

		default:
			CITADEL_PANIC("Unknown file open mode");
			return std::ios::in;
		}
	}

CITADEL_WARNING_IGNORE_POP

	bool file_open_mode_use_read(file_open_mode value) noexcept {
		return (
			value == file_open_mode::read ||
			value == file_open_mode::read_write ||
			value == file_open_mode:: write_read
		);
	}

	bool file_open_mode_use_write(file_open_mode value) noexcept {
		return (
			value == file_open_mode::write ||
			value == file_open_mode::write_read ||
			value == file_open_mode::read_write
		);
	}
}
