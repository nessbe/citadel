// File:        const_string.h
// Project:     citadel
// Repository:  https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// For more details, see the LICENSE file at the root of the project.

#pragma once

#ifndef CITADEL_CONST_STRING_H
#define CITADEL_CONST_STRING_H

#include <cstddef>
#include <ostream>
#include <string>
#include <string_view>

#include "citadel/attributes.h"

namespace citadel
{
	template<typename Char, std::size_t N>
	struct const_string
	{
	public:
		constexpr const_string(const Char(&data)[N]);

		CITADEL_GETTER constexpr std::size_t size() const noexcept;
		CITADEL_GETTER constexpr Char* data() const;

		CITADEL_GETTER constexpr std::basic_string_view<Char> view() const;
		CITADEL_GETTER constexpr std::basic_string<Char> to_string() const;

	private:
		Char data_[N];
	};

	template<typename Char, std::size_t N>
	CITADEL_INLINE constexpr std::ostream& operator<<(std::ostream& out, const_string<Char, N> string);

	template<std::size_t N>
	constexpr const_string<char, N> make_const_string(const char(&string)[N]);

	template<std::size_t N>
	constexpr const_string<wchar_t, N> make_const_string(const wchar_t(&string)[N]);
}

#include "citadel/string/const_string.inl"

#define CITADEL_CONST_STRING(string) citadel::make_const_string<sizeof(string)>(string)

#endif
