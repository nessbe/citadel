// File:       color.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
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
	class CITADEL_API color {
	public:
		static const std::uint8_t max_value;
		static const float max_value_normalized;

		std::uint8_t red, green, blue, alpha;

	public:
		CITADEL_NODISCARD static float normalize_channel(std::uint8_t value) noexcept;
		CITADEL_NODISCARD static std::uint8_t unnormalize_channel(float value) noexcept;

		CITADEL_NODISCARD static color from_normalized(float red, float green, float blue, float alpha);
		CITADEL_NODISCARD static color from_normalized(float red, float green, float blue);

		color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha);
		color(std::uint8_t red, std::uint8_t green, std::uint8_t blue);

		CITADEL_NODISCARD std::uint8_t get_red() const noexcept;
		void set_red(std::uint8_t value) noexcept;

		CITADEL_NODISCARD float get_red_normalized() const noexcept;
		void set_red_normalized(float value) noexcept;

		CITADEL_NODISCARD std::uint8_t get_green() const noexcept;
		void set_green(std::uint8_t value) noexcept;

		CITADEL_NODISCARD float get_green_normalized() const noexcept;
		void set_green_normalized(float value) noexcept;

		CITADEL_NODISCARD std::uint8_t get_blue() const noexcept;
		void set_blue(std::uint8_t value) noexcept;

		CITADEL_NODISCARD float get_blue_normalized() const noexcept;
		void set_blue_normalized(float value) noexcept;

		CITADEL_NODISCARD std::uint8_t get_alpha() const noexcept;
		void set_alpha(std::uint8_t value) noexcept;

		CITADEL_NODISCARD float get_alpha_normalized() const noexcept;
		void set_alpha_normalized(float value) noexcept;

		void get_channels(std::uint8_t& out_red, std::uint8_t& out_green, std::uint8_t& out_blue, std::uint8_t& out_alpha) const noexcept;
		void get_channels(std::uint8_t& out_red, std::uint8_t& out_green, std::uint8_t& out_blue) const noexcept;

		void get_channels_normalized(float& out_red, float& out_green, float& out_blue, float& out_alpha) const noexcept;
		void get_channels_normalized(float& out_red, float& out_green, float& out_blue) const noexcept;
	};
}
