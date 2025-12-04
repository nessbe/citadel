// File:       image_reader.cpp
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
#include "citadel/io/resources/images/image_reader.hpp"

namespace citadel {
	image_reader::image_reader(const reference<class stream>& stream)
		: reader(stream) { }

	image image_reader::read_image() {
		return _read_image();
	}

	bool image_reader::should_flip_vertically() const noexcept {
		return flip_vertically_;
	}

	void image_reader::set_flip_vertically(bool value) noexcept {
		flip_vertically_ = value;
	}
}
