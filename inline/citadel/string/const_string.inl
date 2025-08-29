// File:        const_string.inl
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

#ifndef CITADEL_CONST_STRING_INL
#define CITADEL_CONST_STRING_INL

namespace citadel
{
	template<typename Char, std::size_t N>
	constexpr const_string<Char, N>::const_string(const Char(&data)[N])
	{
		for (std::size_t i = 0; i < N; i++)
		{
			data_[i] = data[i];
		}
	}

	template<typename Char, std::size_t N>
	constexpr std::size_t const_string<Char, N>::size() const noexcept
	{
		return N;
	}

	template<typename Char, std::size_t N>
	constexpr Char* const_string<Char, N>::data() const
	{
		return data_;
	}

	template<typename Char, std::size_t N>
	constexpr std::basic_string_view<Char> const_string<Char, N>::view() const
	{
		return { data_, N };
	}

	template<typename Char, std::size_t N>
	constexpr std::basic_string<Char> const_string<Char, N>::to_string() const
	{
		return std::basic_string<Char>(view());
	}

	template<typename Char, std::size_t N>
	constexpr std::ostream& operator<<(std::ostream& out, const_string<Char, N> string)
	{
		out << string.to_string();
		return out;
	}

	template<std::size_t N>
	constexpr const_string<char, N> make_const_string(const char(&string)[N])
	{
		return const_string<char, N>(string);
	}

	template<std::size_t N>
	constexpr const_string<wchar_t, N> make_const_string(const wchar_t(&string)[N])
	{
		return const_string<wchar_t, N>(string);
	}
}

#endif
