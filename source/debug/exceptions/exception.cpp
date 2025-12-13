// File:       exception.cpp
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
#include "citadel/debug/exceptions/exception.hpp"

namespace citadel {
	exception::exception(std::string message) noexcept
		: message_(std::move(message)) { }

	const char* exception::what() const noexcept {
		return message_.c_str();
	}
}
