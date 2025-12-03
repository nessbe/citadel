// File:       texture.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/rendering/textures/image.hpp"

namespace citadel {
	class exported texture {
	public:
		using slot_type = std::uint32_t;

	public:
		texture(const image& image);

		void bind(slot_type slot);

		nodisc const image& get_image() const noexcept;
		void set_image(const image& value);

		nodisc std::size_t get_channel_count() const noexcept;

		nodisc image::dimension get_width() const noexcept;
		nodisc image::dimension get_height() const noexcept;

	private:
		image image_;

	private:
		virtual void _bind(slot_type slot) = 0;
	};
}
