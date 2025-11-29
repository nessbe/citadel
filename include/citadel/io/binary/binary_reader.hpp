// File:       binary_reader.hpp
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

#include <array>
#include <cinttypes>
#include <iosfwd>
#include <memory>
#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/reader.hpp"

#include "citadel/io/filesystem/file.hpp"

#include "citadel/memory/reference.hpp"

namespace citadel {
	class exported binary_reader : public reader {
	public:
		using dynamic_buffer = std::vector<std::uint8_t>;

		template <std::streamsize N>
		using static_buffer = std::array<std::uint8_t, N>;

	public:
		explicit binary_reader(const reference<file>& file);

		nodisc std::int8_t read_int8();
		nodisc std::uint8_t read_uint8();

		nodisc std::int16_t read_int16();
		nodisc std::uint16_t read_uint16();

		nodisc std::int32_t read_int32();
		nodisc std::uint32_t read_uint32();

		nodisc std::int64_t read_int64();
		nodisc std::uint64_t read_uint64();

		nodisc dynamic_buffer read_dynamic_buffer(std::streamsize size);

		template <std::streamsize N>
		nodisc static_buffer<N> read_static_buffer();
	};
}

#include "citadel/io/binary/binary_reader.inl"
