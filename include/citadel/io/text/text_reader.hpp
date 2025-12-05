// File:       text_reader.hpp
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

#pragma once

#include <functional>
#include <string>

#include "citadel/export.hpp"

#include "citadel/io/reader.hpp"
#include "citadel/io/stream.hpp"

namespace citadel {
	class exported text_reader : public reader {
	public:
		using condition_callback_type = std::function<bool(char)>;

	public:
		static constexpr std::size_t default_base_capacity = 64;

	public:
		explicit text_reader(const stream_reference& stream);

		char read_character();

		std::string read_c_string();
		std::string read_string(std::size_t size);

		std::string read_group();
		std::string read_word();

		std::string read_integer();
		std::string read_floating_point();

		std::string read_whitespace();

		std::string read_line();
		std::string read_text();

		std::string read_while_matching(const std::string& match);
		bool read_match(const std::string& match);

		std::string read_while(condition_callback_type condition_callback, std::size_t base_capacity);
		std::string read_while(condition_callback_type condition_callback);
	};
}
