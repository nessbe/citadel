// File:       static_string.inl
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

#include "citadel/assert.hpp"

namespace citadel {
	template <typename Char, std::size_t N>
	constexpr basic_static_string<Char, N>::basic_static_string()
		: data_{ } { }

	template <typename Char, std::size_t N>
	constexpr basic_static_string<Char, N>::basic_static_string(const Char (&data)[N]) {
		for (std::size_t i = 0; i < N; i++) {
			data_[i] = data[i];
		}
	}

	template <typename Char, std::size_t N>
	template <std::size_t M>
	constexpr basic_static_string<Char, N>::basic_static_string(const std::array<Char, M>& data) {
		CITADEL_STATIC_ASSERT(M <= N, "Trying to write data larger than the buffer");

		for (std::size_t i = 0; i < M; i++) {
			data_[i] = data[i];
		}
	}

	template <typename Char, std::size_t N>
	constexpr std::size_t basic_static_string<Char, N>::size() const noexcept {
		return N;
	}

	template <typename Char, std::size_t N>
	constexpr const Char* basic_static_string<Char, N>::data() const noexcept {
		return data_.data();
	}

	template <typename Char, std::size_t N>
	constexpr std::basic_string<Char> basic_static_string<Char, N>::to_string() const {
		return std::basic_string<Char>(data_.data(), N);
	}

	template <typename Char, std::size_t N>
	constexpr std::basic_string_view<Char> basic_static_string<Char, N>::view() const noexcept {
		return std::basic_string_view<Char>(data_.data(), N);
	}

	template <typename Char, std::size_t N>
	template <std::size_t M>
	constexpr basic_static_string<Char, N + M> basic_static_string<Char, N>::concat(const basic_static_string<Char, M>& other) const {
		std::array<Char, N + M> result = { };

		for (std::size_t i = 0; i < N; i++) {
			result[i] = data_[i];
		}

		for (std::size_t i = 0; i < M; i++) {
			result[N + i] = other.data_[i];
		}

		return basic_static_string<Char, N + M>(result);
	}

	template <typename Char, std::size_t N>
	template <std::size_t M>
	constexpr basic_static_string<Char, N + M> basic_static_string<Char, N>::operator+(const basic_static_string<Char, M>& other) const {
		return concat(other);
	}

	template <typename Char, std::size_t N>
	constexpr Char& basic_static_string<Char, N>::operator[](std::size_t index) {
		return data_[index];
	}

	template <typename Char, std::size_t N>
	constexpr Char basic_static_string<Char, N>::operator[](std::size_t index) const {
		return data_[index];
	}

	template <typename Char, std::size_t N>
	constexpr std::ostream& operator<<(std::ostream& out, const basic_static_string<Char, N>& value) {
		return out << value.to_string();
	}
}
