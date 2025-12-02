// File:       stream.cpp
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
#include "citadel/io/stream.hpp"

namespace citadel {
	stream::size_type stream::read(void* buffer, size_type size) {
		return _read(buffer, size);
	}

	stream::size_type stream::write(const void* buffer, size_type size) {
		return _write(buffer, size);
	}

	stream::position_type stream::tell() {
		return _tell();
	}

	stream::offset_type stream::size() {
		return _size();
	}

	int stream::peek() {
		return _peek();
	}

	bool stream::seek(position_type position) {
		return _seek(position);
	}

	bool stream::seek(offset_type offset, stream_direction_t direction) {
		return _seek(offset, direction);
	}

	void stream::flush() {
		_flush();
	}

	bool stream::is_good() const {
		return _is_good();
	}

	bool stream::is_eof() const {
		return _is_eof();
	}
}
