// File:       stream.cpp
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
#include "citadel/io/stream.hpp"

namespace citadel {
	const stream::size_type stream::eof_value = EOF;

	stream::size_type stream::read(void* buffer, size_type size) {
		return _read(buffer, size);
	}

	stream::size_type stream::write(const void* buffer, size_type size) {
		return _write(buffer, size);
	}

	void stream::flush() {
		_flush();
	}

	bool stream::good() const {
		return _good();
	}

	bool stream::eof() const {
		return _eof();
	}
}
