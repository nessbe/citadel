// File:       mesh_reader.hpp
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

#include "citadel/io/reader.hpp"
#include "citadel/io/stream.hpp"

#include "citadel/memory/reference.hpp"

#include "citadel/rendering/meshes/mesh.hpp"

namespace citadel {
	class exported mesh_reader : public reader {
	public:
		explicit mesh_reader(const reference<class stream>& stream);

		mesh read_mesh();

	private:
		virtual mesh _read_mesh() = 0;
	};
}
