// File:       text_reader.cpp
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
#include "citadel/io/text/text_reader.hpp"

namespace citadel {

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_SPECTRE)

	text_reader::text_reader(const stream_reference& stream)
		: reader(stream) { }

	std::string text_reader::read_c_string() {
		std::string result;
		result.reserve(256);

		class stream& stream = this->stream();

		while (!stream.is_eof()) {
			char character = '\0';
			stream::size_type bytes_read = stream.read(&character, sizeof(char));

			if (bytes_read <= 0) {
				break;
			}

			if (character == '\0') {
				break;
			}

			result.push_back(character);

			if (result.size() + 1 == result.capacity()) {
				result.reserve(result.capacity() * 2);
			}
		}

		return result;
	}

CITADEL_WARNING_IGNORE_POP

	std::string text_reader::read_string(std::size_t size) {
		if (size == 0) {
			return "";
		}

		std::string result;
		result.resize(size);

		stream::size_type bytes_read = stream().read(result.data(), static_cast<stream::size_type>(size));

		if (bytes_read <= 0) {
			return "";
		}

		result.resize(static_cast<std::size_t>(bytes_read));
		return result;
	}

	std::string text_reader::read_text() {
		stream::size_type size = stream().size();

		if (size <= 0) {
			return "";
		}

		return read_string(static_cast<std::size_t>(size));
	}
}
