// File:       reference.inl
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
	reference<T>::reference() noexcept
		: handle_(nullptr) { }

	template <typename T>
	reference<T>::reference(std::nullptr_t) noexcept
		: handle_(nullptr) { }

	template <typename T>
	reference<T>::reference(T* handle) noexcept
		: handle_(handle) { }

	template <typename T>
	reference<T>::reference(std::shared_ptr<T> handle) noexcept
		: handle_(handle) { }

	template <typename T>
	template <typename U>
	reference<T>::reference(const std::shared_ptr<U>& other) noexcept
		: handle_(std::static_pointer_cast<T>(other)) { }

	template <typename T>
	T* reference<T>::get() noexcept {
		return handle_.get();
	}

	template <typename T>
	T* reference<T>::operator->() noexcept {
		return handle_.get();
	}

	template <typename T>
	const T* reference<T>::operator->() const noexcept {
		return handle_.get();
	}

	template <typename T>
	T& reference<T>::operator*() noexcept {
		return *handle_;
	}

	template <typename T>
	const T& reference<T>::operator*() const noexcept {
		return *handle_;
	}

	template <typename T>
	void reference<T>::reset() noexcept {
		handle_.reset();
	}

	template <typename T>
	void reference<T>::reset(T* handle) noexcept {
		handle_.reset(handle);
	}

	template <typename T>
	reference<T>::operator bool() const noexcept {
		return static_cast<bool>(handle_);
	}

	template <typename T>
	long reference<T>::use_count() const noexcept {
		return handle_.use_count();
	}

	template <typename T>
	std::shared_ptr<T>& reference<T>::raw() noexcept {
		return handle_;
	}

	template <typename T>
	const std::shared_ptr<T>& reference<T>::raw() const noexcept {
		return handle_;
	}

	template <typename T>
	template <typename... Arguments>
	reference<T> reference<T>::create(Arguments&&... arguments) {
		return reference(std::make_shared<T>(std::forward<Arguments>(arguments)...));
	}

	template <typename T, typename... Arguments>
	reference<T> make_referenced(Arguments&&... arguments) {
		return reference<T>::create(std::forward<T>(arguments)...);
	}
}
