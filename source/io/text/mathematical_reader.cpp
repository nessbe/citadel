// File:       mathematical_reader.cpp
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
#include "citadel/io/text/mathematical_reader.hpp"

namespace citadel {
	mathematical_reader::mathematical_reader(const stream_reference& stream)
		: reader(stream), reader_(stream) { }

	vec2 mathematical_reader::read_vec2(const std::string& separator) {
		return read_basic_vec2<float>(separator);
	}

	ivec2 mathematical_reader::read_ivec2(const std::string& separator) {
		return read_basic_vec2<int>(separator);
	}

	vec3 mathematical_reader::read_vec3(const std::string& separator) {
		return read_basic_vec3<float>(separator);
	}

	ivec3 mathematical_reader::read_ivec3(const std::string& separator) {
		return read_basic_vec3<int>(separator);
	}
}
