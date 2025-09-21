// File:        static_string.inl
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

namespace citadel
{
	template<typename Char, std::size_t N>
	constexpr static_string<Char, N>::static_string(const Char(&data)[N])
	{
		for (std::size_t i = 0; i < N; i++)
		{
			data_[i] = data[i];
		}
	}

	template<typename Char, std::size_t N>
	constexpr std::size_t static_string<Char, N>::size() const noexcept
	{
		return N;
	}

	template<typename Char, std::size_t N>
	constexpr Char* static_string<Char, N>::data() const
	{
		return data_;
	}

	template<typename Char, std::size_t N>
	constexpr typename static_string<Char, N>::string_view_t static_string<Char, N>::view() const
	{
		return { data_, N };
	}

	template<typename Char, std::size_t N>
	constexpr typename static_string<Char, N>::string_t static_string<Char, N>::to_string() const
	{
		return string_t(view());
	}

	template<typename Char, std::size_t N>
	constexpr std::ostream& operator<<(std::ostream& out, static_string<Char, N> value)
	{
		return out << value.to_string();
	}

	template<std::size_t N>
	constexpr static_string<char, N> make_static_string(const char(&data)[N])
	{
		return static_string<char, N>(data);
	}

	template<std::size_t N>
	constexpr static_string<wchar_t, N> make_static_string(const wchar_t(&data)[N])
	{
		return static_string<wchar_t, N>(data);
	}
}
