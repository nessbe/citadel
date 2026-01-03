// File:       random_access_stream.cpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#include "citadel/pch.hpp"
#include "citadel/io/random_access_stream.hpp"

namespace citadel {
	stream::position_type random_access_stream::tell() {
		return _tell();
	}

	stream::offset_type random_access_stream::size() {
		return _size();
	}

	int random_access_stream::peek() {
		return _peek();
	}

	bool random_access_stream::seek(position_type position) {
		return _seek(position);
	}

	bool random_access_stream::seek(offset_type offset, stream_direction direction) {
		return _seek(offset, direction);
	}

	bool random_access_stream::eol() {
		return peek() == '\n';
	}
}
