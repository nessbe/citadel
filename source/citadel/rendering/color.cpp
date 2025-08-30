// File:        color.cpp
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

#include "citadelpch.h"
#include "citadel/rendering/color.h"

namespace citadel
{
	void color::to_float(float& out_red, float& out_green, float& out_blue, float& out_alpha) const
	{
		out_red = red_ / float(MAX_CHANNEL_VALUE);
		out_green = green_ / float(MAX_CHANNEL_VALUE);
		out_blue = blue_ / float(MAX_CHANNEL_VALUE);
		out_alpha = alpha_ / float(MAX_CHANNEL_VALUE);
	}

	color::channel_t color::get_red() const noexcept
	{
		return red_;
	}

	void color::set_red(channel_t red) noexcept
	{
		red_ = red;
	}

	color::channel_t color::get_green() const noexcept
	{
		return green_;
	}

	void color::set_green(channel_t green) noexcept
	{
		green_ = green;
	}

	color::channel_t color::get_blue() const noexcept
	{
		return blue_;
	}

	void color::set_blue(channel_t blue) noexcept
	{
		blue_ = blue;
	}

	color::channel_t color::get_alpha() const noexcept
	{
		return alpha_;
	}

	void color::set_alpha(channel_t alpha) noexcept
	{
		alpha_ = alpha;
	}

	std::string color::to_string() const
	{
		std::ostringstream oss;
		oss << '(' << std::to_string(red_) << ", ";
		oss << std::to_string(green_) << ", ";
		oss << std::to_string(blue_) << ", ";
		oss << std::to_string(alpha_) << ')';
		return oss.str();
	}

	color::operator std::string() const
	{
		return to_string();
	}

	std::ostream& operator<<(std::ostream& out, const color& object)
	{
		return out << object.to_string();
	}
}
