// File:       mesh_reader.cpp
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
#include "citadel/io/resources/meshes/mesh_reader.hpp"

namespace citadel {
	mesh_reader::mesh_reader(const reference<class stream>& stream)
		: reader(stream) { }

	mesh mesh_reader::read_mesh() {
		return _read_mesh();
	}
}
