// File:       index_buffer.hpp
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

#include <cinttypes>
#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	class api index_buffer {
	public:
		using index = std::uint32_t;

	public:
		index_buffer(std::size_t size);
		virtual ~index_buffer() = default;

		void bind();
		void unbind();

		nodisc std::size_t size() const noexcept;

	private:
		std::size_t size_;

	private:
		virtual void _bind() = 0;
		virtual void _unbind() = 0;
	};
}
