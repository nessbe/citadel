// File:       json.hpp
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

#include <ostream>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/formats/json/json_value.hpp"

namespace citadel {
	class exported json {
	public:
		json(const json_value& root);

		nodisc std::string to_string(const json_serialization_context& context, std::size_t indent_level = 0) const;

		nodisc json_value& root() noexcept;

	private:
		json_value root_;
	};

	std::ostream& operator<<(std::ostream& out, const json& value);
}
