// File:       color.cpp
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

#include "citadel/rendering/color.hpp"

namespace citadel {
	color::channel_normalized_type color::normalize_channel(channel_type value) noexcept {
		return value / static_cast<channel_normalized_type>(max_channel);
	}

	color::channel_type color::unnormalize_channel(channel_normalized_type value) noexcept {
		return static_cast<channel_type>(value * max_channel + 0.5f);
	}

	color::color(channel_type red, channel_type green, channel_type blue, channel_type alpha)
		: red(red), green(green), blue(blue), alpha(alpha) { }

	color::color(channel_type red, channel_type green, channel_type blue)
		: color(red, green, blue, max_channel) { }

	color::channel_type color::get_red() const noexcept {
		return red;
	}

	void color::set_red(channel_type value) noexcept {
		red = value;
	}

	color::channel_normalized_type color::get_red_normalized() const noexcept {
		return normalize_channel(red);
	}

	void color::set_red_normalized(channel_normalized_type value) noexcept {
		red = unnormalize_channel(value);
	}

	color::channel_type color::get_green() const noexcept {
		return green;
	}

	void color::set_green(channel_type value) noexcept {
		green = value;
	}

	color::channel_normalized_type color::get_green_normalized() const noexcept {
		return normalize_channel(green);
	}

	void color::set_green_normalized(channel_normalized_type value) noexcept {
		green = unnormalize_channel(value);
	}

	color::channel_type color::get_blue() const noexcept {
		return blue;
	}

	void color::set_blue(channel_type value) noexcept {
		blue = value;
	}

	color::channel_normalized_type color::get_blue_normalized() const noexcept {
		return normalize_channel(blue);
	}

	void color::set_blue_normalized(channel_normalized_type value) noexcept {
		blue = unnormalize_channel(value);
	}

	color::channel_type color::get_alpha() const noexcept {
		return alpha;
	}

	void color::set_alpha(channel_type value) noexcept {
		alpha = value;
	}

	color::channel_normalized_type color::get_alpha_normalized() const noexcept {
		return normalize_channel(alpha);
	}

	void color::set_alpha_normalized(channel_normalized_type value) noexcept {
		alpha = unnormalize_channel(value);
	}

	void color::get_channels(channel_type& out_red, channel_type& out_green, channel_type& out_blue, channel_type& out_alpha) const noexcept {
		out_red = red;
		out_green = green;
		out_blue = blue;
		out_alpha = alpha;
	}

	void color::get_channels(channel_type& out_red, channel_type& out_green, channel_type& out_blue) const noexcept {
		out_red = red;
		out_green = green;
		out_blue = blue;
	}

	void color::get_channels_normalized(channel_normalized_type& out_red, channel_normalized_type& out_green, channel_normalized_type& out_blue, channel_normalized_type& out_alpha) const noexcept {
		out_red = get_red_normalized();
		out_green = get_green_normalized();
		out_blue = get_blue_normalized();
		out_alpha = get_alpha_normalized();
	}

	void color::get_channels_normalized(channel_normalized_type& out_red, channel_normalized_type& out_green, channel_normalized_type& out_blue) const noexcept {
		out_red = get_red_normalized();
		out_green = get_green_normalized();
		out_blue = get_blue_normalized();
	}
}
