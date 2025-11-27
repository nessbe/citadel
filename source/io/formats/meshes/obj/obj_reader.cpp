// File:       obj_reader.cpp
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
#include "citadel/io/formats/meshes/obj/obj_reader.hpp"

#include "citadel/rendering/shaders/shader_data_type.hpp"

#include "citadel/rendering/vertices/index_buffer.hpp"
#include "citadel/rendering/vertices/vertex_buffer_layout.hpp"

namespace citadel {
	obj_reader::obj_reader(const std::shared_ptr<file>& file)
		: mesh_reader(file), reader_(file) { }

CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_SPECTRE)

	vertex obj_reader::build_vertex(const obj_vertex& data, const std::vector<vec3>& positions, const std::vector<vec3>& normals, const std::vector<vec2>& uvs) {
		vertex vertex = { };

		if (data.position_index > 0 && data.position_index <= positions.size()) {
			vertex.position = positions[data.position_index - 1];
		}

		if (data.normal_index > 0 && data.normal_index <= normals.size()) {
			vertex.normal = normals[data.normal_index - 1];
		}

		if (data.uv_index > 0 && data.uv_index <= uvs.size()) {
			vertex.uv = uvs[data.uv_index - 1];
		}

		return vertex;
	}

	vec2 obj_reader::read_vec2() {
		vec2 vector;

		for (std::size_t i = 0; i < vec2::max_index; i++) {
			reader_.read_whitespace();

			std::string raw_component = reader_.read_floating_point();
			float component = std::stof(raw_component);

			vector[i] = component;
		}

		return vector;
	}

	vec3 obj_reader::read_vec3() {
		vec3 vector;

		for (std::size_t i = 0; i < vec3::max_index; i++) {
			reader_.read_whitespace();

			std::string raw_component = reader_.read_floating_point();
			float component = std::stof(raw_component);

			vector[i] = component;
		}

		return vector;
	}

CITADEL_IGNORE_WARNING_POP()

	obj_vertex obj_reader::read_vertex() {
		obj_vertex vertex;

		reader_.read_whitespace();
		vertex.position_index = static_cast<std::size_t>(std::stoi(reader_.read_integer()));
		reader_.read_whitespace();

		if (file_->peek() == '/') {
			reader_.read_character();
			reader_.read_whitespace();

			if (file_->peek() != '/') {
				vertex.uv_index = static_cast<std::size_t>(std::stoi(reader_.read_integer()));
			}

			reader_.read_whitespace();

			if (file_->peek() == '/') {
				reader_.read_character();
				vertex.normal_index = static_cast<std::size_t>(std::stoi(reader_.read_integer()));
			}
		}

		return vertex;
	}

	obj_face obj_reader::read_face() {
		obj_face face;
		reader_.read_whitespace();

		while (!file_->is_eol()) {
			char character = file_->peek();
			if (character == '\n' || character == '\r' || character == '\0') {
				break;
			}

			if (!std::isdigit(static_cast<unsigned char>(character))) {
				break;
			}

			obj_vertex vertex = read_vertex();
			face.vertices.push_back(vertex);

			reader_.read_whitespace();
		}

		return face;
	}

	mesh obj_reader::_read_mesh(std::vector<vertex>& vertices, std::vector<index_buffer::index>& indices) {
		std::vector<vec3> positions;
		std::vector<vec3> normals;
		std::vector<vec2> uvs;

		std::vector<obj_face> faces;

		while (!file_->is_eof() && file_->is_good()) {
			reader_.read_whitespace();
			std::string directive = reader_.read_word();

			if (directive.empty()) {
				reader_.read_line();
				continue;
			}

			if (directive == "v") {
				positions.push_back(read_vec3());
			}
			else if (directive == "vn") {
				normals.push_back(read_vec3());
			}
			else if (directive == "vt") {
				uvs.push_back(read_vec2());
			}
			else if (directive == "f") {
				faces.push_back(read_face());
			}
			else {
				reader_.read_line();
			}
		}

		for (const obj_face& face : faces) {
			for (std::size_t i = 1; i + 1 < face.vertices.size(); i++) {
				const obj_vertex& vertex0 = face.vertices[0];
				const obj_vertex& vertex1 = face.vertices[i];
				const obj_vertex& vertex2 = face.vertices[i + 1];

				vertices.push_back(build_vertex(vertex0, positions, normals, uvs));
				vertices.push_back(build_vertex(vertex1, positions, normals, uvs));
				vertices.push_back(build_vertex(vertex2, positions, normals, uvs));
			}
		}

		indices = index_buffer::linear(vertices.size());

		return mesh(
			vertices,
			indices
		);
	}
}
