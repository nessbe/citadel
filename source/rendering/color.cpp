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
	color::color(channel red, channel green, channel blue, channel alpha)
		: red_(red), green_(green), blue_(blue), alpha_(alpha) { }

	color::color(channel red, channel green, channel blue)
		: color(red, green, blue, max_channel) { }

	color::channel color::get_red() const noexcept {
		return red_;
	}

	void color::set_red(channel value) noexcept {
		red_ = value;
	}

	color::channel color::get_green() const noexcept {
		return green_;
	}

	void color::set_green(channel value) noexcept {
		green_ = value;
	}

	color::channel color::get_blue() const noexcept {
		return blue_;
	}

	void color::set_blue(channel value) noexcept {
		blue_ = value;
	}

	color::channel color::get_alpha() const noexcept {
		return alpha_;
	}

	void color::set_alpha(channel value) noexcept {
		alpha_ = value;
	}

	void color::get_channels(channel& red, channel& green, channel& blue, channel& alpha) const noexcept {
		red = red_;
		green = green_;
		blue = blue_;
		alpha = alpha_;
	}

	void color::get_channels(channel& red, channel& green, channel& blue) const noexcept {
		red = red_;
		green = green_;
		blue = blue_;
	}
}
