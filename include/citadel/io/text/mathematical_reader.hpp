// File:       mathematical_reader.hpp
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

#include "citadel/export.hpp"

#include "citadel/io/reader.hpp"
#include "citadel/io/stream.hpp"

#include "citadel/io/text/text_reader.hpp"

#include "citadel/math/vectors/vec2.hpp"
#include "citadel/math/vectors/vec3.hpp"

namespace citadel {
	class exported mathematical_reader : public reader {
	public:
		explicit mathematical_reader(const stream_reference& stream);

		template <typename T>
		basic_vec2<T> read_basic_vec2(const std::string& separator);

		vec2 read_vec2(const std::string& separator);
		ivec2 read_ivec2(const std::string& separator);

		template <typename T>
		basic_vec3<T> read_basic_vec3(const std::string& separator);

		vec3 read_vec3(const std::string& separator);
		ivec3 read_ivec3(const std::string& separator);

	private:
		text_reader reader_;
	};
}

#include "citadel/io/text/mathematical_reader.inl"
