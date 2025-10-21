// File:       static_string.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
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

#include <array>
#include <cstddef>
#include <ostream>
#include <string>
#include <string_view>

namespace citadel {
	template <typename Char, std::size_t N>
	class basic_static_string {
	public:
		constexpr basic_static_string(const Char (&data)[N]);

		template <std::size_t M>
		constexpr explicit basic_static_string(const std::array<Char, M>& data);

		constexpr std::size_t size() const noexcept;

		constexpr const Char* data() const noexcept;
		constexpr std::basic_string<Char> to_string() const;
		constexpr std::basic_string_view<Char> view() const noexcept;

		template <std::size_t M>
		constexpr basic_static_string<Char, N + M> concat(const basic_static_string<Char, M>& other) const;

		template <std::size_t M>
		constexpr basic_static_string<Char, N + M> operator+(const basic_static_string<Char, M>& other) const;

		constexpr Char& operator[](std::size_t index);
		constexpr Char operator[](std::size_t index) const;

	private:
		std::array<Char, N> data_;
	};

	template <typename Char, std::size_t N>
	basic_static_string(const Char (&)[N]) -> basic_static_string<Char, N>;

	template <typename Char, std::size_t N>
	constexpr std::ostream& operator<<(std::ostream& out, const basic_static_string<Char, N>& value);

	template <std::size_t N>
	using static_string = basic_static_string<char, N>;

	template <std::size_t N>
	using static_wstring = basic_static_string<wchar_t, N>;
}

#define CITADEL_STATIC_STRING(data)  ::citadel::static_string<sizeof(data)>(data)
#define CITADEL_STATIC_WSTRING(data) ::citadel::static_wstring<sizeof(data) / 2>(data)

#include "citadel/string/static_string.inl"
