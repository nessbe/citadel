// File:       callable.inl
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
	template <typename Result, typename... Arguments>
	Result callable<Result(Arguments...)>::call(Arguments&&... arguments) {
		return _call(arguments);
	}

	template <typename Result, typename... Arguments>
	bool callable<Result(Arguments...)>::valid() const noexcept {
		return _valid();
	}

	template <typename Result, typename... Arguments>
	Result callable<Result(Arguments...)>::operator()(Arguments&&... arguments) {
		return call(arguments);
	}
}
