// File:       binary_writer.cpp
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
#include "citadel/io/binary/binary_writer.hpp"

namespace citadel {
	binary_writer::binary_writer(const reference<class stream>& stream)
		: writer(stream) { }

	void binary_writer::write_int8(std::int8_t value) {
		stream().read(&value, sizeof(int8_t));
	}

	void binary_writer::write_uint8(std::uint8_t value) {
		stream().read(&value, sizeof(uint8_t));
	}

	void binary_writer::write_int16(std::int16_t value) {
		stream().read(&value, sizeof(int16_t));
	}

	void binary_writer::write_uint16(std::uint16_t value) {
		stream().read(&value, sizeof(uint16_t));
	}

	void binary_writer::write_int32(std::int32_t value) {
		stream().read(&value, sizeof(int32_t));
	}

	void binary_writer::write_uint32(std::uint32_t value) {
		stream().read(&value, sizeof(uint32_t));
	}

	void binary_writer::write_int64(std::int64_t value) {
		stream().read(&value, sizeof(int64_t));
	}

	void binary_writer::write_uint64(std::uint64_t value) {
		stream().read(&value, sizeof(uint64_t));
	}

	void binary_writer::write_dynamic_buffer(const dynamic_buffer& buffer) {
		stream().write(buffer.data(), static_cast<stream::size_type>(buffer.size()));
	}
}
