// File:       binary_reader.cpp
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
#include "citadel/io/binary/binary_reader.hpp"

namespace citadel {
	binary_reader::binary_reader(const reference<file>& file)
		: reader(file) { }

	std::int8_t binary_reader::read_int8() {
		std::int8_t value = 0;
		CITADEL_POINTER_CALL(file_, read, &value, sizeof(std::int8_t));
		return value;
	}

	std::uint8_t binary_reader::read_uint8() {
		std::uint8_t value = 0;
		CITADEL_POINTER_CALL(file_, read, &value, sizeof(std::uint8_t));
		return value;
	}

	std::int16_t binary_reader::read_int16() {
		std::int16_t value = 0;
		CITADEL_POINTER_CALL(file_, read, &value, sizeof(std::int16_t));
		return value;
	}

	std::uint16_t binary_reader::read_uint16() {
		std::uint16_t value = 0;
		CITADEL_POINTER_CALL(file_, read, &value, sizeof(std::uint16_t));
		return value;
	}

	std::int32_t binary_reader::read_int32() {
		std::int32_t value = 0;
		CITADEL_POINTER_CALL(file_, read, &value, sizeof(std::int32_t));
		return value;
	}

	std::uint32_t binary_reader::read_uint32() {
		std::uint32_t value = 0;
		CITADEL_POINTER_CALL(file_, read, &value, sizeof(std::uint32_t));
		return value;
	}

	std::int64_t binary_reader::read_int64() {
		std::int64_t value = 0;
		CITADEL_POINTER_CALL(file_, read, &value, sizeof(std::int64_t));
		return value;
	}

	std::uint64_t binary_reader::read_uint64() {
		std::uint64_t value = 0;
		CITADEL_POINTER_CALL(file_, read, &value, sizeof(std::uint64_t));
		return value;
	}

	typename binary_reader::dynamic_buffer binary_reader::read_dynamic_buffer(std::streamsize size) {
		std::vector<std::uint8_t> buffer(static_cast<std::size_t>(size));
		CITADEL_POINTER_CALL(file_, read, buffer.data(), size);
		return buffer;
	}
}
