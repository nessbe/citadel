// File:       stream_direction.hpp
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

#include <ios>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	enum class stream_direction_t {
		begin = 0,
		current,
		end,
	};

	namespace stream_direction {
		nodisc exported std::ios::seekdir to_stl(stream_direction_t value);
	}
}
