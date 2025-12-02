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
#include <vector>

#include "citadel/export.hpp"

#include "citadel/io/reader.hpp"
#include "citadel/io/stream.hpp"

#include "citadel/memory/reference.hpp"

namespace citadel {
	class exported binary_reader : public reader {
	public:
		using dynamic_buffer = std::vector<std::uint8_t>;

		template <stream::size_type N>
		using static_buffer = std::array<std::uint8_t, N>;

	public:
		explicit binary_reader(const reference<class stream>& stream);

		std::int8_t read_int8();
		std::uint8_t read_uint8();

		std::int16_t read_int16();
		std::uint16_t read_uint16();

		std::int32_t read_int32();
		std::uint32_t read_uint32();

		std::int64_t read_int64();
		std::uint64_t read_uint64();

		dynamic_buffer read_dynamic_buffer(stream::size_type size);

		template <stream::size_type N>
		static_buffer<N> read_static_buffer();
	};
}

#include "citadel/io/binary/binary_reader.inl"
