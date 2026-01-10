// File:       variadic_accessor.hpp
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

#include <tuple>

#include "citadel/attributes.hpp"

namespace citadel {
	template <typename... Arguments>
	class variadic_accessor {
	public:
		variadic_accessor(Arguments&&... arguments);

		variadic_accessor(const variadic_accessor&) = delete;
		variadic_accessor& operator=(const variadic_accessor&) = delete;

		template <typename Visitor>
		void visit(std::size_t index, Visitor&& visitor);

		CITADEL_NODISCARD std::tuple<Arguments...> values() const;
		CITADEL_NODISCARD std::size_t size() const noexcept;

	private:
		std::tuple<Arguments...> values_;

	private:
		template <typename T, typename Visitor>
		void call_if_index_matches(std::size_t index, std::size_t I, T& value, bool& matched, Visitor&& visitor);

		template <typename Visitor, std::size_t... I>
		void visit_sequence(std::size_t index, Visitor&& visitor, std::index_sequence<I...>);
	};
}

#include "citadel/utils/variadic/variadic_accessor.inl"
