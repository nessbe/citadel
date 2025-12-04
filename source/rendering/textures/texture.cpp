// File:       texture.cpp
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
#include "citadel/rendering/textures/texture.hpp"

namespace citadel {
	texture::texture(const image& image)
		: image_(image) { }

	void texture::bind(slot_type slot) {
		_bind(slot);
	}

	const image& texture::get_image() const noexcept {
		return image_;
	}

	void texture::set_image(const image& value) {
		image_ = value;
	}

	std::size_t texture::get_channel_count() const noexcept {
		return image_.get_channel_count();
	}

	image::dimension_type texture::get_width() const noexcept {
		return image_.get_width();
	}

	image::dimension_type texture::get_height() const noexcept {
		return image_.get_height();
	}
}
