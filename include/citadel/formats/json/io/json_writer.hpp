// File:       json_writer.hpp
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

#pragma once

#include <cstddef>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/formats/json/json.hpp"
#include "citadel/formats/json/json_serialization_context.hpp"

#include "citadel/io/writer.hpp"

#include "citadel/io/sinks/sink.hpp"

namespace citadel {
	class CITADEL_API json_writer : public writer {
	public:
		explicit json_writer(const sink_reference& sink);

		void write_json(const json& json);

		CITADEL_NODISCARD bool is_pretty() const noexcept;
		void set_pretty(bool value) noexcept;

		CITADEL_NODISCARD const std::string& ident() const noexcept;
		void set_indent(const std::string& value) noexcept;

		CITADEL_NODISCARD std::size_t ident_level() const noexcept;
		void set_indent_level(std::size_t value) noexcept;

	private:
		json_serialization_context context_;
		std::size_t indent_level_;
	};
}
