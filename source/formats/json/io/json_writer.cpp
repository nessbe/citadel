// File:       json_writer.cpp
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
#include "citadel/formats/json/io/json_writer.hpp"

#include "citadel/formats/json/json_value.hpp"

namespace citadel {
	json_writer::json_writer(const sink_reference& sink)
		: writer(sink), context_(json_value::default_context), indent_level_(0) { }

	void json_writer::write_json(const json& json) {
		std::string content = json.to_string(context_, indent_level_);
		sink().write(content.data(), static_cast<stream::size_type>(content.size()));
	}

	bool json_writer::is_pretty() const noexcept {
		return context_.pretty;
	}

	void json_writer::set_pretty(bool value) noexcept {
		context_.pretty = value;
	}

	const std::string& json_writer::ident() const noexcept {
		return context_.indent;
	}

	void json_writer::set_indent(const std::string& value) noexcept {
		context_.indent = value;
	}

	std::size_t json_writer::ident_level() const noexcept {
		return indent_level_;
	}

	void json_writer::set_indent_level(std::size_t value) noexcept {
		indent_level_ = value;
	}
}
