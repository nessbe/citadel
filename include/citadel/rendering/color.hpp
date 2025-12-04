// File:       color.hpp
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
#include <limits>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	class exported color {
	public:
		using channel_type = std::uint8_t;
		using channel_normalized_type = float;

	public:
		static constexpr channel_type max_channel = std::numeric_limits<channel_type>::max();

		channel_type red, green, blue, alpha;

	public:
		static channel_normalized_type normalize_channel(channel_type value) noexcept;
		static channel_type unnormalize_channel(channel_normalized_type value) noexcept;

		color(channel_type red, channel_type green, channel_type blue, channel_type alpha);
		color(channel_type red, channel_type green, channel_type blue);

		nodisc channel_type get_red() const noexcept;
		void set_red(channel_type value) noexcept;

		nodisc channel_normalized_type get_red_normalized() const noexcept;
		void set_red_normalized(channel_normalized_type value) noexcept;

		nodisc channel_type get_green() const noexcept;
		void set_green(channel_type value) noexcept;

		nodisc channel_normalized_type get_green_normalized() const noexcept;
		void set_green_normalized(channel_normalized_type value) noexcept;

		nodisc channel_type get_blue() const noexcept;
		void set_blue(channel_type value) noexcept;

		nodisc channel_normalized_type get_blue_normalized() const noexcept;
		void set_blue_normalized(channel_normalized_type value) noexcept;

		nodisc channel_type get_alpha() const noexcept;
		void set_alpha(channel_type value) noexcept;

		nodisc channel_normalized_type get_alpha_normalized() const noexcept;
		void set_alpha_normalized(channel_normalized_type value) noexcept;

		void get_channels(channel_type& out_red, channel_type& out_green, channel_type& out_blue, channel_type& out_alpha) const noexcept;
		void get_channels(channel_type& out_red, channel_type& out_green, channel_type& out_blue) const noexcept;

		void get_channels_normalized(channel_normalized_type& out_red, channel_normalized_type& out_green, channel_normalized_type& out_blue, channel_normalized_type& out_alpha) const noexcept;
		void get_channels_normalized(channel_normalized_type& out_red, channel_normalized_type& out_green, channel_normalized_type& out_blue) const noexcept;
	};
}
