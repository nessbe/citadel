// File:       texture.frag
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

uniform sampler2D texture_sampler;
uniform vec3 ambient_color;

uniform vec3 light_position;
uniform float light_intensity;
uniform float light_max_distance;

in vec3 vertex_normal;
in vec2 vertex_uv;
in vec3 vertex_world_position;

out vec4 fragment_color;

void main() {
	vec3 normal = normalize(vertex_normal);
	vec3 direction = normalize(light_position - vertex_world_position);
	float difference = max(dot(normal, direction), 0.0);

	float distance = length(light_position - vertex_world_position);
	float attenuation = 1.0 - clamp(distance / light_max_distance, 0.0, 1.0);

	float lighting = difference * attenuation * light_intensity;

	vec4 texture_color = texture(texture_sampler, vertex_uv);
	vec3 out_color = ambient_color + texture_color.rgb * max(lighting, 0.0);

	fragment_color = vec4(out_color, texture_color.a);
}
