// File:       binary_writer.hpp
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

#include "citadel/io/writer.hpp"

#include "citadel/io/sinks/sink.hpp"

#include "citadel/memory/reference.hpp"

namespace citadel {
	class exported binary_writer : public writer {
	public:
		using dynamic_buffer_type = std::vector<std::uint8_t>;

		template <stream::size_type N>
		using static_buffer_type = std::array<std::uint8_t, N>;

	public:
		explicit binary_writer(const sink_reference& sink);

		void write_int8(std::int8_t value);
		void write_uint8(std::uint8_t value);

		void write_int16(std::int16_t value);
		void write_uint16(std::uint16_t value);

		void write_int32(std::int32_t value);
		void write_uint32(std::uint32_t value);

		void write_int64(std::int64_t value);
		void write_uint64(std::uint64_t value);

		void write_dynamic_buffer(const dynamic_buffer_type& buffer);

		template <stream::size_type N>
		void write_static_buffer(const static_buffer_type<N>& buffer);
	};
}

#include "citadel/io/binary/binary_writer.inl"
