// File:       tga_reader.hpp
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

#include "citadel/export.hpp"

#include "citadel/io/stream.hpp"

#include "citadel/io/formats/images/image_reader.hpp"

#include "citadel/memory/reference.hpp"

#include "citadel/rendering/textures/image.hpp"

namespace citadel {
	class exported tga_reader : public image_reader {
	public:
		tga_reader(const reference<class stream>& stream);

	private:
		virtual image _read_image() override;
	};
}
