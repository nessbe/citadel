// File:       material.hpp
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

#include <memory>
#include <string>
#include <unordered_map>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/math/matrices/mat3.hpp"
#include "citadel/math/matrices/mat4.hpp"

#include "citadel/math/vectors/vec2.hpp"
#include "citadel/math/vectors/vec3.hpp"
#include "citadel/math/vectors/vec4.hpp"

#include "citadel/memory/reference.hpp"
#include "citadel/memory/scope.hpp"

#include "citadel/rendering/rendering_api_type.hpp"

#include "citadel/rendering/shaders/shader.hpp"
#include "citadel/rendering/shaders/shader_program.hpp"
#include "citadel/rendering/shaders/uniform_info.hpp"

namespace citadel {
	class CITADEL_API material {
	public:
		material(rendering_api_type api, const std::string& name, const std::string& vertex_source, const std::string& fragment_source);
		material(const std::string& name, const std::string& vertex_source, const std::string& fragment_source);

		material(const material&) = delete;
		material& operator=(const material&) = delete;

		void fetch();
		void use() const;
		void apply();

		void set_uniform_bool(const std::string& name, bool value);

		void set_uniform_int(const std::string& name, int value);
		void set_uniform_ivec2(const std::string& name, const ivec2& value);
		void set_uniform_ivec3(const std::string& name, const ivec3& value);
		void set_uniform_ivec4(const std::string& name, const ivec4& value);

		void set_uniform_float(const std::string& name, float value);
		void set_uniform_vec2(const std::string& name, const vec2& value);
		void set_uniform_vec3(const std::string& name, const vec3& value);
		void set_uniform_vec4(const std::string& name, const vec4& value);

		void set_uniform_mat3(const std::string& name, const mat3& value);
		void set_uniform_mat4(const std::string& name, const mat4& value);

		CITADEL_NODISCARD shader& vertex_shader();
		CITADEL_NODISCARD shader& fragment_shader();
		CITADEL_NODISCARD shader_program& shader_program();

	private:
		std::unordered_map<std::string, bool> bool_uniforms_;

		std::unordered_map<std::string, int> int_uniforms_;
		std::unordered_map<std::string, ivec2> ivec2_uniforms_;
		std::unordered_map<std::string, ivec3> ivec3_uniforms_;
		std::unordered_map<std::string, ivec4> ivec4_uniforms_;

		std::unordered_map<std::string, float> float_uniforms_;
		std::unordered_map<std::string, vec2> vec2_uniforms_;
		std::unordered_map<std::string, vec3> vec3_uniforms_;
		std::unordered_map<std::string, vec4> vec4_uniforms_;

		std::unordered_map<std::string, mat3> mat3_uniforms_;
		std::unordered_map<std::string, mat4> mat4_uniforms_;

		reference<shader> vertex_shader_;
		reference<shader> fragment_shader_;
		scope<class shader_program> shader_program_;
	};
}
