// File:        static_string.h
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

#include <cstddef>
#include <ostream>
#include <string>
#include <string_view>

#include "citadel/attributes.h"

namespace citadel
{
	template<typename Char, std::size_t N>
	class static_string
	{
	public:
		using string_view_t = std::basic_string_view<Char>;
		using string_t = std::basic_string<Char>;

	public:
		constexpr static_string(const Char(&data)[N]);

		CITADEL_GETTER constexpr std::size_t size() const noexcept;
		CITADEL_GETTER constexpr Char* data() const;

		CITADEL_GETTER constexpr string_view_t view() const;
		CITADEL_GETTER constexpr string_t to_string() const;

	private:
		Char data_[N];
	};

	template<typename Char, std::size_t N>
	CITADEL_INLINE constexpr std::ostream& operator<<(std::ostream& out, static_string<Char, N> value);

	template<std::size_t N>
	constexpr static_string<char, N> make_static_string(const char(&data)[N]);

	template<std::size_t N>
	constexpr static_string<wchar_t, N> make_static_string(const wchar_t(&data)[N]);
}

#define CITADEL_STATIC_STRING(data) ::citadel::make_static_string<sizeof(data)>(data)

#include "citadel/string/static_string.inl"
