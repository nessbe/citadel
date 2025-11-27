// File:       stl_file.cpp
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
#include "citadel/platforms/stl/stl_file.hpp"

namespace citadel {
	stl_file::stl_file(const std::string& path, file_open_mode::enumeration open_mode)
		: file(path, open_mode)
	{
		std::ios::openmode stl_open_mode = file_open_mode::to_stl(open_mode);
		stl_open_mode |= std::ios::binary;

		stream_.open(path, stl_open_mode);
		CITADEL_ASSERT(stream_.is_open(), "Failed to open file '" + path + " '");
	}

	stl_file::~stl_file() {
		if (stream_.is_open()) {
			stream_.close();
		}
	}
	
	std::streamsize stl_file::_read(void* buffer, std::streamsize size) {
		stream_.read(reinterpret_cast<char*>(buffer), size);
		return stream_.gcount();
	}

	std::streamsize stl_file::_write(const void* buffer, std::streamsize size) {
		stream_.flush();

		std::streampos previous_position = tell();
		stream_.write(reinterpret_cast<const char*>(buffer), size);

		if (!stream_.good()) {
			std::streampos current_position = tell();
			return static_cast<std::streamsize>(current_position - previous_position);
		}

		return static_cast<std::streamsize>(size);
	}

	std::streampos stl_file::_tell() {
		file_open_mode::enumeration open_mode = get_open_mode();

		if (open_mode == file_open_mode::read) {
			return stream_.tellg();
		}
		else if (open_mode == file_open_mode::write) {
			return stream_.tellp();
		}

		return 0;
	}

	std::streamoff stl_file::_size() {
		file_open_mode::enumeration open_mode = get_open_mode();
		std::streampos size_position;

		if (open_mode == file_open_mode::read) {
			std::streampos position = stream_.tellg();

			stream_.seekg(0, std::ios::end);
			size_position = stream_.tellg();

			stream_.seekg(position);
		}
		else if (open_mode == file_open_mode::write) {
			std::streampos position = stream_.tellp();

			stream_.seekp(0, std::ios::end);
			size_position = stream_.tellp();

			stream_.seekp(position);
		}
		else {
			return 0;
		}

		return static_cast<std::streamoff>(size_position);
	}

	char stl_file::_peek() {
		return static_cast<char>(stream_.peek());
	}

	void stl_file::_seek(std::streamoff position) {
		file_open_mode::enumeration open_mode = get_open_mode();

		if (open_mode == file_open_mode::read) {
			stream_.seekg(position);
		}

		if (open_mode == file_open_mode::write) {
			stream_.seekp(position);
		}
	}

	bool stl_file::_is_good() const {
		return stream_.good();
	}

	bool stl_file::_is_eof() const {
		return stream_.eof();
	}

	void* stl_file::_get_native_handle() const {
		return nullptr;
	}
}
