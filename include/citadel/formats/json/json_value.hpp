// File:       json_value.hpp
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

#include <ostream>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/formats/json/json_serialization_context.hpp"
#include "citadel/formats/json/json_type.hpp"
#include "citadel/formats/json/json_types.hpp"

namespace citadel {
	class exported json_value {
	public:
		using value_type = std::variant<
			json_null,
			json_boolean,
			json_number,
			json_string,
			json_array,
			json_object
		>;

	public:
		static const json_serialization_context default_context;

	public:
		json_value(const value_type& value);

		nodisc json_type type() const noexcept;

		template <typename T>
		nodisc bool is() const noexcept;

		nodisc bool is_null() const noexcept;
		nodisc bool is_boolean() const noexcept;
		nodisc bool is_number() const noexcept;
		nodisc bool is_string() const noexcept;
		nodisc bool is_array() const noexcept;
		nodisc bool is_object() const noexcept;

		template <typename T>
		nodisc T& as();

		template <typename T>
		nodisc const T& as() const;

		nodisc json_null& as_null();
		nodisc json_boolean& as_boolean();
		nodisc json_number& as_number();
		nodisc json_string& as_string();
		nodisc json_array& as_array();
		nodisc json_object& as_object();

		nodisc const json_null& as_null() const;
		nodisc const json_boolean& as_boolean() const;
		nodisc const json_number& as_number() const;
		nodisc const json_string& as_string() const;
		nodisc const json_array& as_array() const;
		nodisc const json_object& as_object() const;

		nodisc std::string to_string(const json_serialization_context& context, std::size_t indent_level = 0) const;

		void indent(std::ostream& out, const json_serialization_context& context, std::size_t level) const;
		void serialize(std::ostream& out, const json_serialization_context& context, std::size_t indent_level = 0) const;

	private:
		value_type value_;
	};

	std::ostream& operator<<(std::ostream& out, const json_value& value);
}

#include "citadel/formats/json/json_value.inl"
