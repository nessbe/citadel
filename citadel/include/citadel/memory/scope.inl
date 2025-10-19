// File:       scope.inl
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

namespace citadel {
	template <typename T>
	constexpr scope<T>::scope(std::nullptr_t) noexcept
		: handle_(nullptr) { }

	template <typename T>
	constexpr scope<T>::scope(pointer handle) noexcept
		: handle_(std::move(handle)) { }

	template <typename T>
	constexpr scope<T>::scope(std::unique_ptr<T>&& handle) noexcept
		: handle_(std::move(handle)) { }

	template <typename T>
	constexpr T* scope<T>::get() const noexcept {
		return handle_.get();
	}

	template <typename T>
	constexpr T* scope<T>::operator->() const noexcept {
		return handle_.get();
	}

	template <typename T>
	constexpr T& scope<T>::operator*() const noexcept {
		return *handle_;
	}

	template <typename T>
	constexpr scope<T>::operator bool() const noexcept {
		return static_cast<bool>(handle_);
	}

	template <typename T>
	constexpr void scope<T>::reset() noexcept {
		handle_.reset();
	}

	template <typename T>
	constexpr void scope<T>::reset(pointer handle) noexcept {
		handle_.reset(handle);
	}

	template <typename T>
	constexpr typename scope<T>::pointer scope<T>::release() noexcept {
		return handle_.release();
	}

	template <typename T>
	constexpr void scope<T>::swap(scope& other) noexcept {
		handle_.swap(other.handle_);
	}

	template <typename T>
	constexpr typename scope<T>::deleter_type& scope<T>::get_deleter() noexcept {
		return handle_.get_deleter();
	}

	template <typename T>
	constexpr const typename scope<T>::deleter_type& scope<T>::get_deleter() const noexcept {
		return handle_.get_deleter();
	}

	template <typename T>
	template <typename... Arguments>
	constexpr scope<T> scope<T>::create(Arguments&&... arguments) {
		return scope(std::forward<Arguments>(arguments)...);
	}

	template <typename T, typename... Arguments>
	constexpr scope<T> make_scoped(Arguments&&... arguments) {
		return scope<T>::create(std::forward<Arguments>(arguments)...);
	}
}
