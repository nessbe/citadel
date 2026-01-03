// File:       stl_file.cpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#include "citadel/pch.hpp"
#include "citadel/platforms/stl/stl_file.hpp"

namespace citadel {
	stl_file::stl_file(const std::string& path, file_open_mode open_mode)
		: file(path, open_mode)
	{
		if (!std::filesystem::exists(path)) {
			throw std::invalid_argument(formatter::format("File '{0}' does not exist", path));
		}

		std::ios::openmode stl_open_mode = file_open_mode_to_stl(open_mode);
		stl_open_mode |= std::ios::binary;

		stream_.open(path, stl_open_mode);

		if (!stream_.is_open()) {
			throw std::runtime_error(formatter::format("Failed to open file '{0}'", path));
		}
	}

	stl_file::~stl_file() {
		if (stream_.is_open()) {
			stream_.close();
		}
	}

	stream::size_type stl_file::_read(void* buffer, size_type size) {
		if (buffer) {
			stream_.read(reinterpret_cast<char*>(buffer), size);
		}
		return stream_.gcount();
	}

	stream::size_type stl_file::_write(const void* buffer, size_type size) {
		flush();

		position_type previous_position = tell();
		stream_.write(reinterpret_cast<const char*>(buffer), size);

		if (!good()) {
			position_type current_position = tell();
			return static_cast<size_type>(current_position - previous_position);
		}

		return static_cast<size_type>(size);
	}

	stream::position_type stl_file::_tell() {
		file_open_mode open_mode = this->open_mode();

		if (file_open_mode_use_read(open_mode)) {
			return stream_.tellg();
		}
		else if (file_open_mode_use_write(open_mode)) {
			return stream_.tellp();
		}

		return -1;
	}

	stream::offset_type stl_file::_size() {
		position_type position = tell();
		seek(0, stream_direction::end);

		position_type size_position = tell();
		seek(position);

		return static_cast<offset_type>(size_position);
	}

	int stl_file::_peek() {
		return stream_.peek();
	}

	bool stl_file::_seek(position_type position) {
		stream_.clear();

		file_open_mode open_mode = this->open_mode();

		if (file_open_mode_use_read(open_mode)) {
			stream_.seekg(position);
		}

		if (file_open_mode_use_write(open_mode)) {
			stream_.seekp(position);
		}

		return good();
	}

	bool stl_file::_seek(offset_type offset, stream_direction direction) {
		stream_.clear();

		file_open_mode open_mode = this->open_mode();
		std::ios::seekdir seek_direction = stream_direction_to_stl(direction);

		if (file_open_mode_use_read(open_mode)) {
			stream_.seekg(offset, seek_direction);
		}

		if (file_open_mode_use_write(open_mode)) {
			stream_.seekp(offset, seek_direction);
		}

		return good();
	}

	void stl_file::_flush() {
		stream_.flush();
	}

	bool stl_file::_good() const {
		return stream_.good();
	}

	bool stl_file::_eof() const {
		return stream_.eof();
	}

	void* stl_file::_native_handle() const {
		return nullptr;
	}
}
