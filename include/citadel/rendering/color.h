// File:        color.h
// Project:     citadel
// Repository:  https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// For more details, see the LICENSE file at the root of the project.

#pragma once

#ifndef CITADEL_COLOR_H
#define CITADEL_COLOR_H

#include <cinttypes>
#include <string>

#include "citadel/attributes.h"
#include "citadel/export.h"

namespace citadel
{
	class color
	{
	public:
		using channel_t = std::uint8_t;

	public:
		static constexpr channel_t MAX_CHANNEL_VALUE = 255;

	public:
		color(channel_t red, channel_t green, channel_t blue, channel_t alpha)
			: red_(red), green_(green), blue_(blue), alpha_(alpha) { }

		color(channel_t red, channel_t green, channel_t blue)
			: color(red, green, blue, MAX_CHANNEL_VALUE) { }

		~color() = default;

		CITADEL_API CITADEL_GETTER channel_t get_red() const noexcept;
		CITADEL_API CITADEL_SETTER void set_red(channel_t red) noexcept;

		CITADEL_API CITADEL_GETTER channel_t get_green() const noexcept;
		CITADEL_API CITADEL_SETTER void set_green(channel_t green) noexcept;

		CITADEL_API CITADEL_GETTER channel_t get_blue() const noexcept;
		CITADEL_API CITADEL_SETTER void set_blue(channel_t blue) noexcept;

		CITADEL_API CITADEL_GETTER channel_t get_alpha() const noexcept;
		CITADEL_API CITADEL_SETTER void set_alpha(channel_t alpha) noexcept;

		CITADEL_API CITADEL_NODISCARD std::string to_string() const;
		CITADEL_API CITADEL_GETTER operator std::string() const;

	private:
		std::uint8_t red_, green_, blue_, alpha_;
	};

	CITADEL_API CITADEL_INLINE std::ostream& operator<<(std::ostream& out, const color& object);
}

#endif
