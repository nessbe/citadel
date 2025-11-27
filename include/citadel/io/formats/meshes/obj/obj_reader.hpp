// File:       obj_reader.hpp
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

#include <memory>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/filesystem/file.hpp"

#include "citadel/io/formats/meshes/mesh_reader.hpp"

#include "citadel/io/formats/meshes/obj/obj_face.hpp"
#include "citadel/io/formats/meshes/obj/obj_vertex.hpp"

#include "citadel/io/text/text_reader.hpp"

#include "citadel/math/vectors/vec3.hpp"

#include "citadel/rendering/meshes/mesh.hpp"

#include "citadel/rendering/vertices/vertex.hpp"
#include "citadel/rendering/vertices/index_buffer.hpp"

namespace citadel {
	class exported obj_reader : public mesh_reader {
	public:
		explicit obj_reader(const std::shared_ptr<file>& file);

	private:
		text_reader reader_;

	private:
		nodisc vertex build_vertex(const obj_vertex& data, const std::vector<vec3>& positions, const std::vector<vec3>& normals, const std::vector<vec2>& uvs);

		vec2 read_vec2();
		vec3 read_vec3();

		obj_vertex read_vertex();
		obj_face read_face();

		virtual mesh _read_mesh(std::vector<vertex>& vertices, std::vector<index_buffer::index>& indices) override;
	};
}
