// File:       formatter.hpp
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

#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	class CITADEL_API formatter {
	public:
		template <typename... Arguments>
		CITADEL_NODISCARD static std::string format(const std::string& source, Arguments&&... arguments);

		formatter(const std::string& source);

		template <typename... Arguments>
		CITADEL_NODISCARD std::string formatted(Arguments&&... arguments);

		CITADEL_NODISCARD const std::string& source() const noexcept;

	private:
		std::string source_;
	};
}

#include "citadel/utils/format/formatter.inl"
