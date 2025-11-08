// File:       vertex_array.cpp
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
#include "citadel/rendering/meshes/vertex_array.hpp"

namespace citadel {
	vertex_array::~vertex_array() {
		destroy();
	}

	void vertex_array::construct() {
		_construct();
	}

	void vertex_array::destroy() {
		_destroy();
	}

	void vertex_array::bind() {
		_bind();
	}

	void vertex_array::unbind() {
		_unbind();
	}

	void vertex_array::add_buffer(const std::unique_ptr<vertex_buffer>& buffer) {
		_add_buffer(buffer);
	}
}
