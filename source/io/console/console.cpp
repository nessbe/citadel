// File:       console.cpp
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
#include "citadel/io/console/console.hpp"

namespace citadel {
	console& console::get() noexcept {
		return *instance_;
	}

	const reference<console>& console::pointer() noexcept {
		return instance_;
	}

	reference<console> console::instance_ = make_referenced<console>();

	stream::size_type console::_read(void* buffer, size_type size) {
		if (buffer) {
			std::cin.read(reinterpret_cast<char*>(buffer), size);
		}
		return std::cin.gcount();
	}

	stream::size_type console::_write(const void* buffer, size_type size) {
		flush();

		position_type previous_position = tell();
		std::cout.write(reinterpret_cast<const char*>(buffer), size);

		if (!good()) {
			position_type current_position = tell();
			return static_cast<size_type>(current_position - previous_position);
		}

		return static_cast<size_type>(size);
	}

	stream::position_type console::_tell() {
		return std::cin.tellg();
	}

	stream::offset_type console::_size() {
		position_type position = tell();
		seek(0, stream_direction::end);

		position_type size_position = tell();
		seek(position);

		return static_cast<offset_type>(size_position);
	}

	int console::_peek() {
		return std::cin.peek();
	}

	bool console::_seek(position_type position) {
		std::cin.clear();
		std::cout.clear();

		std::cin.seekg(position);
		std::cout.seekp(position);

		return good();
	}

	bool console::_seek(offset_type offset, stream_direction direction) {
		std::cin.clear();
		std::cout.clear();

		std::ios::seekdir seek_direction = stream_direction_to_stl(direction);

		std::cin.seekg(offset, seek_direction);
		std::cout.seekp(offset, seek_direction);

		return good();
	}

	void console::_flush() {
		std::cout.flush();
	}

	bool console::_good() const {
		return std::cin.good() && std::cout.good();
	}

	bool console::_eof() const {
		return std::cin.eof() && std::cout.eof();
	}
}
