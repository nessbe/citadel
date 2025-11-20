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
	namespace file_open_mode {
CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_UNREACHABLE_CODE)

		std::ios::openmode to_stl(enumeration value) {
			switch (value) {
			case read:
				return std::ios::in;

			case write:
				return std::ios::out | std::ios::trunc;

			case read_write:
				return std::ios::in | std::ios::out;

			case write_read:
				return std::ios::out | std::ios::in | std::ios::trunc;

			default:
				CITADEL_PANIC("Unknown file open mode");
				return std::ios::in;
			}
		}

CITADEL_IGNORE_WARNING_POP()
	}
}
