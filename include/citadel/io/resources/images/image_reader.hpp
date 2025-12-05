// File:       image_reader.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/io/reader.hpp"
#include "citadel/io/stream.hpp"

#include "citadel/memory/reference.hpp"

#include "citadel/rendering/textures/image.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported image_reader : public reader {
	public:
		explicit image_reader(const stream_reference& stream);

		image read_image();

		nodisc bool should_flip_vertically() const noexcept;
		void set_flip_vertically(bool value) noexcept;

	private:
		bool flip_vertically_ = false;

	private:
		virtual image _read_image() = 0;
	};
}

CITADEL_WARNING_IGNORE_POP
