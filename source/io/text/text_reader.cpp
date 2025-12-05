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
	text_reader::text_reader(const stream_reference& stream)
		: reader(stream) { }

	char text_reader::read_character() {
		char value;
		stream().read(&value, sizeof(char));
		return value;
	}

	std::string text_reader::read_c_string() {
		return read_while([](char character) {
			return character != '\0';
		});
	}

	std::string text_reader::read_string(std::size_t size) {
		std::size_t iterator = 0;

		return read_while([&iterator, size](char character) {
			return iterator < size;
		}, size);
	}

	std::string text_reader::read_group() {
		return read_while([](char character) {
			return std::isalnum(static_cast<unsigned char>(character));
		});
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
		class stream& stream = this->stream();
		stream::size_type size = stream.size();

		return read_while([&stream](char character) {
			return !stream.is_eof();
		}, static_cast<std::size_t>(size));
	}

	std::string text_reader::read_while_matching(const std::string& match) {
		std::size_t iterator = 0;
		std::size_t size = match.size();

		return read_while([&iterator, size, &match](char character) {
			if (iterator < size && match[iterator] == character) {
				iterator++;
				return true;
			}
			return false;
		}, match.size());
	}

	bool text_reader::read_match(const std::string& match) {
		std::string result = read_while_matching(match);
		return result.size() == match.size();
	}

	std::string text_reader::read_while(condition_callback_type condition_callback, std::size_t base_capacity) {
		std::string result;
		result.reserve(base_capacity);

		class stream& stream = this->stream();

		while (!stream.is_eof() && stream.is_good()) {
			char character = static_cast<char>(stream.peek());

			if (character == '\r' || character == '\n') {
				read_character();
				break;
			}

			if (!condition_callback(character)) {
				break;
			}

			result.push_back(character);
			read_character();
		}

		return result;
	}

	std::string text_reader::read_while(condition_callback_type condition_callback) {
		return read_while(condition_callback, default_base_capacity);
	}
}
