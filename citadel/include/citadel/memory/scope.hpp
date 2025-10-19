// File:       scope.hpp
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

#include <memory>
#include <type_traits>
#include <utility>

#include "citadel/attributes.hpp"

namespace citadel {
	template <typename T>
	class scope {
	public:
		using element_type = typename std::unique_ptr<T>::element_type;
		using pointer = typename std::unique_ptr<T>::pointer;
		using deleter_type = typename std::unique_ptr<T>::deleter_type;

	public:
		constexpr scope() noexcept = default;
		constexpr scope(std::nullptr_t) noexcept;

		constexpr explicit scope(pointer handle) noexcept;
		constexpr scope(std::unique_ptr<T>&& handle) noexcept;

		constexpr scope(scope&&) noexcept = default;
		constexpr scope& operator=(scope&&) noexcept = default;

		scope(const scope&) = delete;
		scope& operator=(const scope&) = delete;

		nodisc constexpr T* get() const noexcept;
		nodisc constexpr T* operator->() const noexcept;
		nodisc constexpr T& operator*() const noexcept;

		nodisc constexpr explicit operator bool() const noexcept;

		constexpr void reset() noexcept;
		constexpr void reset(pointer handle) noexcept;

		constexpr pointer release() noexcept;
		constexpr void swap(scope& other) noexcept;

		nodisc constexpr deleter_type& get_deleter() noexcept;
		nodisc constexpr const deleter_type& get_deleter() const noexcept;

		template <typename... Arguments>
		nodisc static constexpr scope create(Arguments&&... arguments);

	private:
		std::unique_ptr<T> handle_;
	};

	template <typename T, typename... Arguments>
	nodisc constexpr scope<T> make_scoped(Arguments&&... arguments);
}

#include "citadel/memory/scope.inl"
