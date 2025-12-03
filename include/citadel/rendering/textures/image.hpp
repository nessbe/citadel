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
		using dimension = std::uint32_t;

		using channel = std::uint8_t;
		using buffer = std::vector<channel>;

	public:
		image(dimension width, dimension height, std::size_t channel_count, const buffer& data);
		image(dimension width, dimension height, std::size_t channel_count, std::initializer_list<channel> data);
		image(dimension width, dimension height, std::size_t channel_count);

		nodisc std::size_t size() const noexcept;

		nodisc buffer& data() noexcept;
		nodisc const buffer& data() const noexcept;

		nodisc std::size_t get_channel_count() const noexcept;

		nodisc dimension get_width() const noexcept;
		nodisc dimension get_height() const noexcept;

	private:
		buffer data_;
		std::size_t channel_count_;
		dimension width_, height_;
	};
}
