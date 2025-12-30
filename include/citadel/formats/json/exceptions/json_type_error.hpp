// File:       json_type_error.hpp
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

#include "citadel/export.hpp"

#include "citadel/formats/json/json_type.hpp"

#include "citadel/formats/json/exceptions/json_exception.hpp"

namespace citadel {
	class exported json_type_error : public json_exception {
	public:
		json_type_error(json_type expected, json_type actual);
	};
}
