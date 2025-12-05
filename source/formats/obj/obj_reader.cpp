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
#include "citadel/formats/obj/obj_reader.hpp"

#include "citadel/rendering/indices/index.hpp"
#include "citadel/rendering/indices/index_buffer.hpp"

#include "citadel/rendering/vertices/vertex.hpp"

namespace citadel {
	obj_reader::obj_reader(const stream_reference& stream)
		: mesh_reader(stream), text_reader_(stream), mathematical_reader_(stream) { }

	obj_vertex obj_reader::read_vertex() {
		obj_vertex vertex;
		class stream& stream = this->stream();

		text_reader_.read_whitespace();

		if (std::optional<int> position_index = to_int(text_reader_.read_integer())) {
			vertex.position_index = static_cast<std::size_t>(position_index.value());
		}

		text_reader_.read_whitespace();

		if (stream.peek() == '/') {
			text_reader_.read_character();
			text_reader_.read_whitespace();

			if (stream.peek() != '/') {
				if (std::optional<int> uv_index = to_int(text_reader_.read_integer())) {
					vertex.uv_index = static_cast<std::size_t>(uv_index.value());
				}

				text_reader_.read_whitespace();
			}

			if (stream.peek() == '/') {
				text_reader_.read_character();

				if (std::optional<int> normal_index = to_int(text_reader_.read_integer())) {
					vertex.uv_index = static_cast<std::size_t>(normal_index.value());
				}
			}
		}

		return vertex;
	}

	obj_face obj_reader::read_face() {
		obj_face face;
		class stream& stream = this->stream();

		text_reader_.read_whitespace();

		while (!stream.is_eol()) {
			char character = static_cast<char>(stream.peek());

			if (character == '\n' || character == '\r' || character == '\0') {
				break;
			}

			if (!std::isdigit(static_cast<unsigned char>(character))) {
				break;
			}

			obj_vertex vertex = read_vertex();
			face.vertices.push_back(vertex);

			text_reader_.read_whitespace();
		}

		return face;
	}

	mesh obj_reader::_read_mesh() {
		class stream& stream = this->stream();

		std::vector<vec3> positions;
		std::vector<vec3> normals;
		std::vector<vec2> uvs;

		std::vector<obj_face> faces;

		while (!stream.is_eof() && stream.is_good()) {
			text_reader_.read_whitespace();
			std::string directive = text_reader_.read_word();

			if (directive.empty()) {
				text_reader_.read_line();
				continue;
			}

			text_reader_.read_whitespace();

			if (directive == "v") {
				positions.push_back(mathematical_reader_.read_vec3(" "));
			}
			else if (directive == "vn") {
				normals.push_back(mathematical_reader_.read_vec3(" "));
			}
			else if (directive == "vt") {
				uvs.push_back(mathematical_reader_.read_vec2(" "));
			}
			else if (directive == "f") {
				faces.push_back(read_face());
			}
			else {
				text_reader_.read_line();
			}
		}

		std::vector<vertex> vertices;

		for (const obj_face& face : faces) {
			for (std::size_t i = 1; i + 1 < face.vertices.size(); i++) {
				const obj_vertex& vertex_a = face.vertices[0];
				const obj_vertex& vertex_b = face.vertices[i];
				const obj_vertex& vertex_c = face.vertices[i + 1];

				auto build_vertex = [&positions, &normals, &uvs](const obj_vertex& data) {
					vertex vertex;

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
				};

				vertices.push_back(build_vertex(vertex_a));
				vertices.push_back(build_vertex(vertex_b));
				vertices.push_back(build_vertex(vertex_c));
			}
		}

		std::vector<index> indices = index_buffer::linear(vertices.size());
		return mesh(vertices, indices);
	}
}
