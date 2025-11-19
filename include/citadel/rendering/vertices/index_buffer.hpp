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
#include <memory>
#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	class api index_buffer {
	public:
		using index = std::uint32_t;

	public:
		nodisc static std::shared_ptr<index_buffer> create(const std::vector<index>& indices);
		nodisc static std::shared_ptr<index_buffer> create(const index* data, std::size_t size);

		index_buffer(const std::vector<index>& indices);
		index_buffer(const index* data, std::size_t size);

		virtual ~index_buffer() = default;

		index_buffer(const index_buffer&) = delete;
		index_buffer& operator=(const index_buffer&) = delete;

		void bind();
		void unbind();

		void set_data(const std::vector<index>& indices);
		void set_data(const index* data, std::size_t size);

		nodisc index* data() noexcept;
		nodisc const index* data() const noexcept;

		nodisc std::size_t size() const noexcept;

	private:
		std::vector<index> indices_;

	private:
		virtual void _bind() = 0;
		virtual void _unbind() = 0;

		virtual void _set_data(const index* data, std::size_t size) = 0;
	};
}
