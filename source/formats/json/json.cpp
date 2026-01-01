// File:       json.cpp
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
#include "citadel/formats/json/json.hpp"

namespace citadel {
	json::json(const json_value& root)
		: root_(root) { }

	std::string json::to_string(const json_serialization_context& context, std::size_t indent_level) const {
		return root_.to_string(context, indent_level);
	}
	
	json_value& json::root() noexcept {
		return root_;
	}

	std::ostream& operator<<(std::ostream& out, const json& value) {
		return out << value.to_string(json_value::default_context, 0);
	}
}
