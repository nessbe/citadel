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
	const std::uint8_t color::max_value = std::numeric_limits<std::uint8_t>::max();
	const float color::max_value_normalized = 1.0f;

	float color::normalize_channel(std::uint8_t value) noexcept {
		return value / static_cast<float>(max_value);
	}

	std::uint8_t color::unnormalize_channel(float value) noexcept {
		return static_cast<std::uint8_t>(value * max_value + 0.5f);
	}

	color color::from_normalized(float red, float green, float blue, float alpha) {
		return color(
			unnormalize_channel(red),
			unnormalize_channel(green),
			unnormalize_channel(blue),
			unnormalize_channel(alpha)
		);
	}

	color color::from_normalized(float red, float green, float blue) {
		return from_normalized(red, green, blue, 1.0f);
	}

	color::color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha)
		: red(red), green(green), blue(blue), alpha(alpha) { }

	color::color(std::uint8_t red, std::uint8_t green, std::uint8_t blue)
		: color(red, green, blue, max_value) { }

	std::uint8_t color::get_red() const noexcept {
		return red;
	}

	void color::set_red(std::uint8_t value) noexcept {
		red = value;
	}

	float color::get_red_normalized() const noexcept {
		return normalize_channel(red);
	}

	void color::set_red_normalized(float value) noexcept {
		red = unnormalize_channel(value);
	}

	std::uint8_t color::get_green() const noexcept {
		return green;
	}

	void color::set_green(std::uint8_t value) noexcept {
		green = value;
	}

	float color::get_green_normalized() const noexcept {
		return normalize_channel(green);
	}

	void color::set_green_normalized(float value) noexcept {
		green = unnormalize_channel(value);
	}

	std::uint8_t color::get_blue() const noexcept {
		return blue;
	}

	void color::set_blue(std::uint8_t value) noexcept {
		blue = value;
	}

	float color::get_blue_normalized() const noexcept {
		return normalize_channel(blue);
	}

	void color::set_blue_normalized(float value) noexcept {
		blue = unnormalize_channel(value);
	}

	std::uint8_t color::get_alpha() const noexcept {
		return alpha;
	}

	void color::set_alpha(std::uint8_t value) noexcept {
		alpha = value;
	}

	float color::get_alpha_normalized() const noexcept {
		return normalize_channel(alpha);
	}

	void color::set_alpha_normalized(float value) noexcept {
		alpha = unnormalize_channel(value);
	}

	void color::get_channels(std::uint8_t& out_red, std::uint8_t& out_green, std::uint8_t& out_blue, std::uint8_t& out_alpha) const noexcept {
		out_red = red;
		out_green = green;
		out_blue = blue;
		out_alpha = alpha;
	}

	void color::get_channels(std::uint8_t& out_red, std::uint8_t& out_green, std::uint8_t& out_blue) const noexcept {
		out_red = red;
		out_green = green;
		out_blue = blue;
	}

	void color::get_channels_normalized(float& out_red, float& out_green, float& out_blue, float& out_alpha) const noexcept {
		out_red = get_red_normalized();
		out_green = get_green_normalized();
		out_blue = get_blue_normalized();
		out_alpha = get_alpha_normalized();
	}

	void color::get_channels_normalized(float& out_red, float& out_green, float& out_blue) const noexcept {
		out_red = get_red_normalized();
		out_green = get_green_normalized();
		out_blue = get_blue_normalized();
	}
}
