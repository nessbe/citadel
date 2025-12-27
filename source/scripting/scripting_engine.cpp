// File:       scripting_engine.cpp
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

#include "citadel/pch.hpp"
#include "citadel/scripting/scripting_engine.hpp"

namespace citadel {
	bool scripting_engine::has() noexcept {
		return current_ != nullptr;
	}

	scripting_engine& scripting_engine::get() noexcept {
		CITADEL_ASSERT(current_ != nullptr, "No scripting engine is currently bound");
		return *current_;
	}

	void scripting_engine::bind() {
		_bind();
		current_ = this;
	}

	void scripting_engine::unbind() {
		_unbind();
		current_ = nullptr;
	}

	void* scripting_engine::native_handle() const noexcept {
		return _native_handle();
	}
}
