// File:       scripting_engine.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	class exported scripting_engine {
	public:
		nodisc static bool has() noexcept;
		nodisc static scripting_engine& get() noexcept;

		virtual ~scripting_engine() = default;

		void bind();
		void unbind();

		nodisc void* native_handle() const noexcept;

	private:
		static scripting_engine* current_;

	private:
		virtual void _bind() = 0;
		virtual void _unbind() = 0;

		nodisc virtual void* _native_handle() const noexcept = 0;
	};
}
