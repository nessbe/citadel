// File:       json_value.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
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
	class CITADEL_API json_value {
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

		CITADEL_NODISCARD json_type type() const noexcept;

		template <typename T>
		CITADEL_NODISCARD bool is() const noexcept;

		CITADEL_NODISCARD bool is_null() const noexcept;
		CITADEL_NODISCARD bool is_boolean() const noexcept;
		CITADEL_NODISCARD bool is_number() const noexcept;
		CITADEL_NODISCARD bool is_string() const noexcept;
		CITADEL_NODISCARD bool is_array() const noexcept;
		CITADEL_NODISCARD bool is_object() const noexcept;

		template <typename T>
		CITADEL_NODISCARD T& as();

		template <typename T>
		CITADEL_NODISCARD const T& as() const;

		CITADEL_NODISCARD json_null& as_null();
		CITADEL_NODISCARD json_boolean& as_boolean();
		CITADEL_NODISCARD json_number& as_number();
		CITADEL_NODISCARD json_string& as_string();
		CITADEL_NODISCARD json_array& as_array();
		CITADEL_NODISCARD json_object& as_object();

		CITADEL_NODISCARD const json_null& as_null() const;
		CITADEL_NODISCARD const json_boolean& as_boolean() const;
		CITADEL_NODISCARD const json_number& as_number() const;
		CITADEL_NODISCARD const json_string& as_string() const;
		CITADEL_NODISCARD const json_array& as_array() const;
		CITADEL_NODISCARD const json_object& as_object() const;

		CITADEL_NODISCARD std::string to_string(const json_serialization_context& context, std::size_t indent_level = 0) const;

		void indent(std::ostream& out, const json_serialization_context& context, std::size_t level) const;
		void serialize(std::ostream& out, const json_serialization_context& context, std::size_t indent_level = 0) const;

	private:
		value_type value_;
	};

	std::ostream& operator<<(std::ostream& out, const json_value& value);
}

#include "citadel/formats/json/json_value.inl"
