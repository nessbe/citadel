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
	binary_writer::binary_writer(const std::shared_ptr<file>& file)
		: file_(file)
	{
		CITADEL_ASSERT(file_, "The given file is null");
	}

	void binary_writer::write_int8(std::int8_t value) {
		file_->write(&value, sizeof(std::int8_t));
	}

	void binary_writer::write_uint8(std::uint8_t value) {
		file_->write(&value, sizeof(std::uint8_t));
	}

	void binary_writer::write_int16(std::int16_t value) {
		file_->write(&value, sizeof(std::int16_t));
	}

	void binary_writer::write_uint16(std::uint16_t value) {
		file_->write(&value, sizeof(std::uint16_t));
	}

	void binary_writer::write_int32(std::int32_t value) {
		file_->write(&value, sizeof(std::int32_t));
	}

	void binary_writer::write_uint32(std::uint32_t value) {
		file_->write(&value, sizeof(std::uint32_t));
	}

	void binary_writer::write_int64(std::int64_t value) {
		file_->write(&value, sizeof(std::int64_t));
	}

	void binary_writer::write_uint64(std::uint64_t value) {
		file_->write(&value, sizeof(std::uint64_t));
	}

	void binary_writer::write_dynamic_buffer(const dynamic_buffer& buffer) {
		file_->write(buffer.data(), static_cast<std::streamsize>(buffer.size()));
	}

	file& binary_writer::get_file() const noexcept {
		return *file_;
	}
}
