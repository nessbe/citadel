// File:       default.vert
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

#version 460 compatibility

uniform mat4 view;
uniform mat4 projection;
uniform mat4 transform;

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;

out vec3 vertex_normal;
out vec2 vertex_uv;
out vec3 vertex_world_position;

void main() {
	vec4 world_position = transform * vec4(position, 1.0);
	vertex_world_position = world_position.xyz;

	vertex_normal = normalize(mat3(transpose(inverse(transform))) * normal);
	vertex_uv = uv;

	gl_Position = projection * view * world_position;
}
