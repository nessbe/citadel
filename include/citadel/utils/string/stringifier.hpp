// File:       stringifier.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	class CITADEL_API stringifier {
	public:
		template <typename T, std::size_t N>
		static std::string stringify(const T(&array)[N]);

		template <typename T>
		static std::string stringify(const T& value);

		stringifier() = default;

		template <typename T>
		stringifier(const T& value);

		void reset();

		template <typename T>
		void reset(const T& value);

		CITADEL_NODISCARD const std::string& value() const noexcept;

	private:
		std::string value_;
	};
}

#include "citadel/utils/string/stringifier.inl"
