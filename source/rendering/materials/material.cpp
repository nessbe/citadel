// File:       material.cpp
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
#include "citadel/rendering/materials/material.hpp"

#include "citadel/rendering/render_command.hpp"

#include "citadel/rendering/shaders/shader_type.hpp"

namespace citadel {
	material::material(rendering_api_type api, const std::string& name, const std::string& vertex_source, const std::string& fragment_source) :
		vertex_shader_(shader::create(api, name + "-vertex", shader_type::vertex, vertex_source)),
		fragment_shader_(shader::create(api, name + "-fragment", shader_type::fragment, fragment_source)),
		shader_program_(shader_program::create(api, name))
	{
		CITADEL_SOFT_ASSERT(vertex_shader_, "Failed to create vertex shader");
		CITADEL_SOFT_ASSERT(fragment_shader_, "Failed to create fragent shader");
		CITADEL_SOFT_ASSERT(shader_program_, "Failed to create shader program");

		CITADEL_POINTER_CALL(vertex_shader_, compile);
		CITADEL_POINTER_CALL(fragment_shader_, compile);

		CITADEL_POINTER_CALL(shader_program_, attach, vertex_shader_);
		CITADEL_POINTER_CALL(shader_program_, attach, fragment_shader_);

		if (CITADEL_POINTER_CALL_OR_FALSE(shader_program_, link)) {
			fetch();
		}
	}

	material::material(const std::string& name, const std::string& vertex_source, const std::string& fragment_source)
		: material(render_command::get_api(), name, vertex_source, fragment_source) { }

	void material::fetch() {
		bool_uniforms_.clear();

		int_uniforms_.clear();
		ivec2_uniforms_.clear();
		ivec3_uniforms_.clear();
		ivec4_uniforms_.clear();

		float_uniforms_.clear();
		vec2_uniforms_.clear();
		vec3_uniforms_.clear();
		vec4_uniforms_.clear();

		mat3_uniforms_.clear();
		mat4_uniforms_.clear();

		CITADEL_POINTER_CALL(shader_program_, fetch_uniforms);

		using uniform_map = std::unordered_map<std::string, uniform_info>;
		const uniform_map& uniforms = CITADEL_POINTER_CALL_OR_DEFAULT(shader_program_, get_uniforms, uniform_map());

		for (const auto& [uniform_name, uniform] : uniforms) {

			switch (uniform.type) {
			case shader_data_type::type_bool:
				bool_uniforms_[uniform_name] = false;
				break;

			case shader_data_type::type_int:
				int_uniforms_[uniform_name] = 0;
				break;

			case shader_data_type::type_ivec2:
				ivec2_uniforms_[uniform_name] = ivec2(0, 0);
				break;

			case shader_data_type::type_ivec3:
				ivec3_uniforms_[uniform_name] = ivec3(0, 0, 0);
				break;

			case shader_data_type::type_ivec4:
				ivec4_uniforms_[uniform_name] = ivec4(0, 0, 0, 0);
				break;

			case shader_data_type::type_float:
				float_uniforms_[uniform_name] = 0.0f;
				break;

			case shader_data_type::type_vec2:
				vec2_uniforms_[uniform_name] = vec2(0.0f, 0.0f);
				break;

			case shader_data_type::type_vec3:
				vec3_uniforms_[uniform_name] = vec3(0.0f, 0.0f, 0.0f);
				break;

			case shader_data_type::type_vec4:
				vec4_uniforms_[uniform_name] = vec4(0.0f, 0.0f, 0.0f, 0.0f);
				break;

			case shader_data_type::type_mat3:
				mat3_uniforms_[uniform_name] = mat3::identity();
				break;

			case shader_data_type::type_mat4:
				mat4_uniforms_[uniform_name] = mat4::identity();
				break;

			case shader_data_type::unknown:
				break;
			}
		}
	}

	void material::use() {
		CITADEL_POINTER_CALL(shader_program_, use);
	}

#define CITADEL_APPLY_TYPE_UNIFORMS(type)                                                 \
	do {                                                                              \
		for (const auto& [uniform_name, uniform_value] : type##_uniforms_) {      \
			shader_program_->set_uniform_##type(uniform_name, uniform_value); \
		}                                                                         \
	} while (false)

	void material::apply() {
		use();

		CITADEL_APPLY_TYPE_UNIFORMS(bool);

		CITADEL_APPLY_TYPE_UNIFORMS(int);
		CITADEL_APPLY_TYPE_UNIFORMS(ivec2);
		CITADEL_APPLY_TYPE_UNIFORMS(ivec3);
		CITADEL_APPLY_TYPE_UNIFORMS(ivec4);

		CITADEL_APPLY_TYPE_UNIFORMS(float);
		CITADEL_APPLY_TYPE_UNIFORMS(vec2);
		CITADEL_APPLY_TYPE_UNIFORMS(vec3);
		CITADEL_APPLY_TYPE_UNIFORMS(vec4);

		CITADEL_APPLY_TYPE_UNIFORMS(mat3);
		CITADEL_APPLY_TYPE_UNIFORMS(mat4);
	}

#undef CITADEL_APPLY_TYPE_UNIFORMS

	void material::set_uniform_bool(const std::string& name, bool value) {
		CITADEL_SOFT_ASSERT(bool_uniforms_.find(name) != bool_uniforms_.end(), "Boolean uniform '" + name + "' does not exist");
		bool_uniforms_[name] = value;
	}

	void material::set_uniform_int(const std::string& name, int value) {
		CITADEL_SOFT_ASSERT(int_uniforms_.find(name) != int_uniforms_.end(), "Integer uniform '" + name + "' does not exist");
		int_uniforms_[name] = value;
	}

	void material::set_uniform_ivec2(const std::string& name, const ivec2& value) {
		CITADEL_SOFT_ASSERT(ivec2_uniforms_.find(name) != ivec2_uniforms_.end(), "Integer 2D vector uniform '" + name + "' does not exist");
		ivec2_uniforms_[name] = value;
	}

	void material::set_uniform_ivec3(const std::string& name, const ivec3& value) {
		CITADEL_SOFT_ASSERT(ivec3_uniforms_.find(name) != ivec3_uniforms_.end(), "Integer 3D vector uniform '" + name + "' does not exist");
		ivec3_uniforms_[name] = value;
	}

	void material::set_uniform_ivec4(const std::string& name, const ivec4& value) {
		CITADEL_SOFT_ASSERT(ivec4_uniforms_.find(name) != ivec4_uniforms_.end(), "Integer 4D vector uniform '" + name + "' does not exist");
		ivec4_uniforms_[name] = value;
	}

	void material::set_uniform_float(const std::string& name, float value) {
		CITADEL_SOFT_ASSERT(float_uniforms_.find(name) != float_uniforms_.end(), "Floating point uniform '" + name + "' does not exist");
		float_uniforms_[name] = value;
	}

	void material::set_uniform_vec2(const std::string& name, const vec2& value) {
		CITADEL_SOFT_ASSERT(vec2_uniforms_.find(name) != vec2_uniforms_.end(), "2D vector uniform '" + name + "' does not exist");
		vec2_uniforms_[name] = value;
	}

	void material::set_uniform_vec3(const std::string& name, const vec3& value) {
		CITADEL_SOFT_ASSERT(vec3_uniforms_.find(name) != vec3_uniforms_.end(), "3D vector uniform '" + name + "' does not exist");
		vec3_uniforms_[name] = value;
	}

	void material::set_uniform_vec4(const std::string& name, const vec4& value) {
		CITADEL_SOFT_ASSERT(vec4_uniforms_.find(name) != vec4_uniforms_.end(), "4D vector uniform '" + name + "' does not exist");
		vec4_uniforms_[name] = value;
	}

	void material::set_uniform_mat3(const std::string& name, const mat3& value) {
		CITADEL_SOFT_ASSERT(mat3_uniforms_.find(name) != mat3_uniforms_.end(), "3x3 matrix uniform '" + name + "' does not exist");
		mat3_uniforms_[name] = value;
	}

	void material::set_uniform_mat4(const std::string& name, const mat4& value) {
		CITADEL_SOFT_ASSERT(mat4_uniforms_.find(name) != mat4_uniforms_.end(), "4x4 matrix uniform '" + name + "' does not exist");
		mat4_uniforms_[name] = value;
	}

	shader& material::get_vertex_shader() const noexcept {
		CITADEL_POINTER_RETURN_REFERENCE(vertex_shader_);
	}

	shader& material::get_fragment_shader() const noexcept {
		CITADEL_POINTER_RETURN_REFERENCE(fragment_shader_);
	}

	shader_program& material::get_shader_program() const noexcept {
		CITADEL_POINTER_RETURN_REFERENCE(shader_program_);
	}
}
