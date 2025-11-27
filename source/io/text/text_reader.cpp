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
	char text_reader::read_character() {
		char value;
		file_->read(&value, sizeof(char));
		return value;
	}

	text_reader::text_reader(const std::shared_ptr<file>& file)
		: reader(file) { }

	std::string text_reader::read_c_string() {
		return read_while([](char character) {
			return character != '\0';
		});
	}

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

	std::string text_reader::read_word() {
		return read_while([](char character) {
			return std::isalpha(static_cast<unsigned char>(character));
		});
	}

	std::string text_reader::read_integer() {
		return read_while([](char character) {
			return std::isdigit(static_cast<unsigned char>(character));
		});
	}

	std::string text_reader::read_floating_point() {
		bool has_sign = false;
		bool has_point = false;

		return read_while([&has_sign, &has_point](char character) {
			if (!has_sign && (character == '-' || character == '+')) {
				has_sign = true;
				return true;
			}

			if (character == '.') {
				if (has_point) {
					return false;
				}
				has_point = true;
				return true;
			}

			return static_cast<bool>(std::isdigit(static_cast<unsigned char>(character)));
		});
	}

	std::string text_reader::read_group() {
		return read_while([](char character) {
			return std::isalnum(static_cast<unsigned char>(character));
		});
	}

	std::string text_reader::read_whitespace() {
		return read_while([](char character) {
			return character == ' ' || character == '\t';
		});
	}

	std::string text_reader::read_line() {
		return read_while([](char character) {
			return character != '\n';
		});
	}

	std::string text_reader::read_text() {
		std::streamsize size = file_->size();

		if (size <= 0) {
			return "";
		}

		return read_string(static_cast<std::size_t>(size));
	}

CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_SPECTRE)

	std::string text_reader::read_while(std::function<bool(char)> condition) {
		std::string result;
		result.reserve(64);

		while (!file_->is_eof()) {
			char character;
			std::streamsize bytes_read = file_->read(&character, sizeof(char));

			if (bytes_read <= 0) {
				break;
			}

			if (character == '\n' || character == '\r') {
				break;
			}

			if (!condition(character)) {
				file_->seek(file_->tell() - static_cast<std::streamsize>(1));
				break;
			}

			result.push_back(character);
		}
		
		return result;
	}

CITADEL_IGNORE_WARNING_POP()
}
