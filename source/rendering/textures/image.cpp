// File:       image.cpp
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
#include "citadel/rendering/textures/image.hpp"

namespace citadel {
	image::image(dimension width, dimension height, std::size_t channel_count, const buffer& data)
		: data_(data), channel_count_(channel_count), width_(width), height_(height) { }

	image::image(dimension width, dimension height, std::size_t channel_count, std::initializer_list<channel> data)
		: data_(data), channel_count_(channel_count), width_(width), height_(height) { }

	image::image(dimension width, dimension height, std::size_t channel_count)
		: data_(width * height * channel_count), channel_count_(channel_count), width_(width), height_(height) { }

	std::size_t image::size() const noexcept {
		return width_ * height_ * channel_count_;
	}

	image::buffer& image::data() noexcept {
		return data_;
	}

	const image::buffer &image::data() const noexcept {
		return data_;
	}

    	std::size_t image::get_channel_count() const noexcept {
		return channel_count_;
	}

	image::dimension image::get_width() const noexcept {
		return width_;
	}

	image::dimension image::get_height() const noexcept {
		return height_;
	}
}
