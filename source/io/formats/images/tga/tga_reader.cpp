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

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_SPECTRE)

	image tga_reader::_read_image() {
		tga_header header;
		stream().read(&header, sizeof(tga_header));

		std::size_t channel_count = static_cast<std::size_t>(header.pixel_depth / 8);
		std::size_t size = header.width * header.height * channel_count;

		image::buffer_type buffer(size);
		stream().read(buffer.data(), static_cast<stream::size_type>(size));

		bool needs_flip = header.descriptor & (1 << 5);

		if (needs_flip) {
			std::size_t row_size = header.width * channel_count;
			image::buffer_type temporary_row(row_size);

			for (std::size_t y = 0; y < static_cast<std::size_t>(header.height) / 2; y++) {
				std::uint8_t* top_row = buffer.data() + y * row_size;
				std::uint8_t* bottom_row = buffer.data() + (header.height - 1 - y) * row_size;

				std::memcpy(temporary_row.data(), top_row, row_size);
				std::memcpy(top_row, bottom_row, row_size);
				std::memcpy(bottom_row, temporary_row.data(), row_size);
			}
		}

		if (channel_count >= 3) {
			for (std::size_t i = 0; i < static_cast<std::size_t>(header.width * header.height); i++) {
				std::swap(buffer[i * channel_count + 0], buffer[i * channel_count + 2]);
			}
		}

		return image(header.width, header.height, channel_count, buffer);
	}

CITADEL_WARNING_IGNORE_POP

}
