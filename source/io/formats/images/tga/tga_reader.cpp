// File:       tga_reader.cpp
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
#include "citadel/io/formats/images/tga/tga_reader.hpp"

#include "citadel/io/formats/images/tga/tga_header.hpp"

namespace citadel {
	tga_reader::tga_reader(const reference<class stream>& stream)
		: image_reader(stream) { }

	image tga_reader::_read_image() {
		tga_header header;
		stream().read(&header, sizeof(tga_header));

		std::size_t channel_count = header.pixel_depth / 8;
		std::size_t size = header.width * header.height * channel_count;

		image::buffer buffer(size);
		stream().read(buffer.data(), size);

		return image(
			header.width,
			header.height,
			channel_count,
			buffer
		);
	}
}
