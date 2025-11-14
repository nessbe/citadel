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

uniform mat4 mvp;

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

out vec4 vertex_color;

void main() {
	gl_Position = mvp * vec4(position, 1.0);
	vertex_color = color;
}
