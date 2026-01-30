// File:       sequential_policy.cpp
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
#include "citadel/core/policies/sequential_policy.hpp"

namespace citadel {
	sequencial_policy::value_type sequencial_policy::acquire() noexcept {
		return current_++;
	}

	void sequencial_policy::release(value_type value) noexcept { }
}
