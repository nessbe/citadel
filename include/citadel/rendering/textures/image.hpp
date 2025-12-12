// File:       image.hpp
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
#include <initializer_list>
#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	class exported image {
	public:
		using dimension_type = std::uint32_t;
		using channel_type = std::uint8_t;
		using buffer_type = std::vector<std::uint8_t>;

	public:
		image(dimension_type width, dimension_type height, std::size_t channel_count, const buffer_type& data);
		image(dimension_type width, dimension_type height, std::size_t channel_count, std::initializer_list<channel_type> data);
		image(dimension_type width, dimension_type height, std::size_t channel_count);

		nodisc std::size_t size() const noexcept;

		nodisc buffer_type& data() noexcept;
		nodisc const buffer_type& data() const noexcept;

		nodisc std::uint8_t* raw() noexcept;
		nodisc const std::uint8_t* raw() const noexcept;

		nodisc std::size_t get_channel_count() const noexcept;

		nodisc dimension_type get_width() const noexcept;
		nodisc dimension_type get_height() const noexcept;

	private:
		buffer_type data_;
		std::size_t channel_count_;
		dimension_type width_, height_;
	};
}
