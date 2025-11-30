// File:       text_writer.cpp
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
#include "citadel/io/text/text_writer.hpp"

namespace citadel {
	text_writer::text_writer(const reference<file>& file)
		: writer(file) { }

	void text_writer::write_c_string(const char* buffer) {
		std::size_t size = std::strlen(buffer);
		CITADEL_POINTER_CALL(file_, write, buffer, static_cast<std::streamsize>(size));
	}

	void text_writer::write_string(const std::string& string) {
		CITADEL_POINTER_CALL(file_, write, string.data(), static_cast<std::streamsize>(string.size()));
	}
}
