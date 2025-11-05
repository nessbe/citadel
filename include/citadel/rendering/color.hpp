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
	class api color {
	public:
		using channel = std::uint8_t;
		using channel_normalized = float;

	public:
		static constexpr channel max_channel = std::numeric_limits<channel>::max();

	public:
		static channel_normalized normalize_channel(channel value) noexcept;
		static channel unnormalize_channel(channel_normalized value) noexcept;

		color(channel red, channel green, channel blue, channel alpha);
		color(channel red, channel green, channel blue);

		nodisc channel get_red() const noexcept;
		void set_red(channel value) noexcept;

		nodisc channel_normalized get_red_normalized() const noexcept;
		void set_red_normalized(channel_normalized value) noexcept;

		nodisc channel get_green() const noexcept;
		void set_green(channel value) noexcept;

		nodisc channel_normalized get_green_normalized() const noexcept;
		void set_green_normalized(channel_normalized value) noexcept;

		nodisc channel get_blue() const noexcept;
		void set_blue(channel value) noexcept;

		nodisc channel_normalized get_blue_normalized() const noexcept;
		void set_blue_normalized(channel_normalized value) noexcept;

		nodisc channel get_alpha() const noexcept;
		void set_alpha(channel value) noexcept;

		nodisc channel_normalized get_alpha_normalized() const noexcept;
		void set_alpha_normalized(channel_normalized value) noexcept;

		void get_channels(channel& red, channel& green, channel& blue, channel& alpha) const noexcept;
		void get_channels(channel& red, channel& green, channel& blue) const noexcept;

		void get_channels_normalized(channel_normalized& red, channel_normalized& green, channel_normalized& blue, channel_normalized& alpha) const noexcept;
		void get_channels_normalized(channel_normalized& red, channel_normalized& green, channel_normalized& blue) const noexcept;

	private:
		channel red_, green_, blue_, alpha_;
	};
}
