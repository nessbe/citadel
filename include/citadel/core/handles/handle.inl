// File:       handle.inl
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

namespace citadel {
	template <typename Tag, typename Value>
	const Value handle<Tag, Value>::default_value = 0;

	template <typename Tag, typename Value>
	constexpr handle<Tag, Value>::handle() noexcept
		: value_(default_value) { }

	template <typename Tag, typename Value>
	constexpr handle<Tag, Value>::handle(Value value) noexcept
		: value_(value) { }

	template <typename Tag, typename Value>
	constexpr Value handle<Tag, Value>::value() const noexcept {
		return value_;
	}

	template <typename Tag, typename Value>
	constexpr bool handle<Tag, Value>::valid() const noexcept {
		return value_ != default_value;
	}

	template <typename Tag, typename Value>
	constexpr handle<Tag, Value>::operator bool() const noexcept {
		return valid();
	}
}
