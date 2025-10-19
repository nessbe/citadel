// File:       reference.hpp
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
	class reference {
	public:
		reference() noexcept;
		reference(std::nullptr_t) noexcept;

		explicit reference(T* handle) noexcept;
		explicit reference(std::shared_ptr<T> handle) noexcept;

		template <typename U>
		explicit reference(const std::shared_ptr<U>& other) noexcept;

		reference(const reference&) noexcept = default;
		reference& operator=(const reference&) = default;

		reference(reference&&) noexcept = default;
		reference& operator=(reference&&) = default;

		nodisc T* get() noexcept;
		nodisc T* operator->() noexcept;
		nodisc const T* operator->() const noexcept;

		nodisc T& operator*() noexcept;
		nodisc const T& operator*() const noexcept;

		void reset() noexcept;
		void reset(T* handle) noexcept;

		nodisc operator bool() const noexcept;
		nodisc long use_count() const noexcept;

		nodisc std::shared_ptr<T>& raw() noexcept;
		nodisc const std::shared_ptr<T>& raw() const noexcept;

		template <typename... Arguments>
		nodisc static reference create(Arguments&&... arguments);

	private:
		std::shared_ptr<T> handle_;
	};

	template <typename T, typename... Arguments>
	nodisc reference<T> make_referenced(Arguments&&... arguments);
}

#include "citadel/memory/reference.inl"
