// File:       obj_header.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
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

#include "citadel/formats/obj/obj_face.hpp"
#include "citadel/formats/obj/obj_vertex.hpp"

#include "citadel/io/random_access_stream.hpp"

#include "citadel/io/text/mathematical_reader.hpp"
#include "citadel/io/text/text_reader.hpp"

#include "citadel/io/resources/meshes/mesh_reader.hpp"

#include "citadel/memory/reference.hpp"

#include "citadel/rendering/meshes/mesh.hpp"

namespace citadel {
	class CITADEL_API obj_reader : public mesh_reader {
	public:
		explicit obj_reader(const reference<random_access_stream>& stream);

	private:
		text_reader text_reader_;
		mathematical_reader mathematical_reader_;

	private:
		obj_vertex read_vertex();
		obj_face read_face();

		virtual mesh _read_mesh() override;
	};
}
