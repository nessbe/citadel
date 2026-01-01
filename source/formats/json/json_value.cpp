// File:       json_value.cpp
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
#include "citadel/formats/json/json_value.hpp"

#include "citadel/formats/json/json_type_of.hpp"

namespace citadel {
	const json_serialization_context json_value::default_context = { true, "\t" };

	json_value::json_value(const value_type& value)
		: value_(value) { }

	json_type json_value::type() const noexcept {
		return std::visit([](auto&& value) -> json_type {
			using T = std::decay_t<decltype(value)>;
			return json_type_of_v<T>;
		}, value_);
	}

	bool json_value::is_null() const noexcept {
		return is<json_null>();
	}

	bool json_value::is_boolean() const noexcept {
		return is<json_boolean>();
	}

	bool json_value::is_number() const noexcept {
		return is<json_number>();
	}

	bool json_value::is_string() const noexcept {
		return is<json_string>();
	}

	bool json_value::is_array() const noexcept {
		return is<json_array>();
	}

	bool json_value::is_object() const noexcept {
		return is<json_object>();
	}

	json_null& json_value::as_null() {
		return as<json_null>();
	}

	json_boolean& json_value::as_boolean() {
		return as<json_boolean>();
	}

	json_number& json_value::as_number() {
		return as<json_number>();
	}

	json_string& json_value::as_string() {
		return as<json_string>();
	}

	json_array& json_value::as_array() {
		return as<json_array>();
	}

	json_object& json_value::as_object() {
		return as<json_object>();
	}

	const json_null& json_value::as_null() const {
		return as<json_null>();
	}

	const json_boolean& json_value::as_boolean() const {
		return as<json_boolean>();
	}

	const json_number& json_value::as_number() const {
		return as<json_number>();
	}

	const json_string& json_value::as_string() const {
		return as<json_string>();
	}

	const json_array& json_value::as_array() const {
		return as<json_array>();
	}

	const json_object& json_value::as_object() const {
		return as<json_object>();
	}

	std::string json_value::to_string(const json_serialization_context& context, std::size_t indent_level) const {
		std::ostringstream oss;
		indent(oss, context, indent_level);
		serialize(oss, context);
		return oss.str();
	}

	void json_value::indent(std::ostream& out, const json_serialization_context& context, std::size_t level) const {
		for (std::size_t i = 0; i < level; i++) {
			out << context.indent;
		}
	}

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_SPECTRE)

	void json_value::serialize(std::ostream& out, const json_serialization_context& context, std::size_t indent_level) const {
		if (is_null()) {
			out << "null";
		}
		else if (is_boolean()) {
			out << (as_boolean() ? "true" : "false");
		}
		else if (is_number()) {
			out << as_number();
		}
		else if (is_string()) {
			out << '"' << as_string() << '"';
		}
		else if (is_array()) {
			out << "[";

			if (context.pretty) {
				out << "\n";
			}

			const json_array& array = as_array();

			for (std::size_t i = 0; i < array.size(); i++) {
				if (context.pretty) {
					indent(out, context, indent_level + 1);
				}

				const json_value_reference& value = array[i];
				value->serialize(out, context, indent_level + 1);

				if (i + 1 < array.size()) {
					out << ",";

					if (context.pretty) {
						out << "\n";
					}
					else {
						out << " ";
					}
				}
			}

			if (context.pretty) {
				out << "\n";
				indent(out, context, indent_level);
			}

			out << "]";
		}
		else if (is_object()) {
			out << "{";

			if (context.pretty) {
				out << "\n";
			}

			const json_object& object = as_object();
			std::size_t i = 0;

			for (const auto& [key, value] : object) {
				if (context.pretty) {
					indent(out, context, indent_level + 1);
				}

				out << '"' << key << "\": ";
				value->serialize(out, context, indent_level + 1);

				if (i + 1 < object.size()) {
					out << ",";

					if (context.pretty) {
						out << "\n";
					}
					else {
						out << " ";
					}
				}

				i++;
			}

			if (context.pretty) {
				out << "\n";
				indent(out, context, indent_level);
			}

			out << "}";
		}
	}

CITADEL_WARNING_IGNORE_POP

	std::ostream& operator<<(std::ostream& out, const json_value& value) {
		value.serialize(out, json_value::default_context);
		return out;
	}
}
