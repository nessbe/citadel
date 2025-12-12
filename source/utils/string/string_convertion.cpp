// File:       string_convertion.cpp
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
#include "citadel/utils/string/string_convertion.hpp"

namespace citadel {
	std::optional<int> to_int(const std::string& string) {
		return to_arithmetic<int>(string);
	}

	std::optional<float> to_float(const std::string& string) {
		return to_arithmetic<float>(string);
	}

	std::optional<double> to_double(const std::string& string) {
		return to_arithmetic<double>(string);
	}
}
