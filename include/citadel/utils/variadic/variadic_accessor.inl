// File:       variadic_accessor.inl
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

#pragma once

#include <functional>
#include <stdexcept>
#include <tuple>
#include <type_traits>

namespace citadel {
	template <typename... Arguments>
	variadic_accessor<Arguments...>::variadic_accessor(Arguments&&... arguments)
		: values_(std::forward<Arguments>(arguments)...) { }

	template <typename... Arguments>
	template <typename Visitor>
	void variadic_accessor<Arguments...>::visit(std::size_t index, Visitor&& visitor) {
		visit_sequence(index, std::forward<Visitor>(visitor), std::make_index_sequence<sizeof...(Arguments)>{});
	}

	template <typename... Arguments>
	std::tuple<Arguments...> variadic_accessor<Arguments...>::values() const {
		return values_;
	}

	template <typename... Arguments>
	std::size_t variadic_accessor<Arguments...>::size() const noexcept {
		return std::tuple_size_v<std::tuple<Arguments...>>;
	}

	template<typename ...Arguments>
	template<typename T, typename Visitor>
	void variadic_accessor<Arguments...>::call_if_index_matches(std::size_t index, std::size_t I, T& value, bool& matched, Visitor&& visitor) {
		if (index == I) {
			visitor(value);
			matched = true;
		}
	}

	template <typename... Arguments>
	template <typename Visitor, std::size_t... I>
	void variadic_accessor<Arguments...>::visit_sequence(std::size_t index, Visitor&& visitor, std::index_sequence<I...>) {
		bool matched = false;

		(call_if_index_matches(index, I, std::get<I>(values_), matched, std::forward<Visitor>(visitor)), ...);

		if (!matched) {
			throw std::out_of_range("Index out of range");
		}
	}
}
