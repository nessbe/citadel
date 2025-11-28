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
CITADEL_IGNORE_WARNING_PUSH();
CITADEL_IGNORE_WARNING(CITADEL_WARNING_SPECTRE);

	text_reader::text_reader(const std::shared_ptr<file>& file)
		: reader(file) { }

	std::string text_reader::read_c_string() {
		std::streamsize max_size = file_->size();
		std::string result;
		result.reserve(256);

		for (std::streamsize i = 0; i < max_size; i++) {
			char character;

			if (!file_->read(&character, sizeof(char))) {
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

CITADEL_IGNORE_WARNING_POP();

	std::string text_reader::read_string(std::size_t size) {
		if (size == 0) {
			return "";
		}

		std::string result;
		result.resize(size);

		std::streamsize bytes_read = file_->read(result.data(), static_cast<std::streamsize>(size));

		if (bytes_read <= 0) {
			return "";
		}

		result.resize(static_cast<std::size_t>(bytes_read));
		return result;
	}

	std::string text_reader::read_text() {
		std::streamsize size = file_->size();

		if (size <= 0) {
			return "";
		}

		return read_string(static_cast<std::size_t>(size));
	}
}
