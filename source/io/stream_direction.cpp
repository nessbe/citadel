// File:       stream_direction.cpp
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
#include "citadel/io/stream_direction.hpp"

namespace citadel {
	namespace stream_direction {

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_UNREACHABLE_CODE)

		std::ios::seekdir to_stl(stream_direction_t value) {
			switch (value) {
			case stream_direction_t::begin:
				return std::ios::beg;

			case stream_direction_t::current:
				return std::ios::cur;

			case stream_direction_t::end:
				return std::ios::end;

			default:
				CITADEL_PANIC("Unknown stream direction");
				return std::ios::cur;
			}
		}

CITADEL_WARNING_IGNORE_POP

	}
}
