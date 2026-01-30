// File:       handle_factory.inl
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
	template <typename Tag, typename Policy>
	typename handle_factory<Tag, Policy>::handle_type handle_factory<Tag, Policy>::acquire() {
		return handle_type(policy_.acquire());
	}

	template <typename Tag, typename Policy>
	void handle_factory<Tag, Policy>::release(handle_type handle) {
		if (handle) {
			policy_.release(handle.value());
		}
	}
}
