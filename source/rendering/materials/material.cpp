// File:       material.cpp
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
		CITADEL_PRECONDITION(vertex_shader_, "Failed to create vertex shader");
		CITADEL_PRECONDITION(fragment_shader_, "Failed to create fragment shader");
		CITADEL_PRECONDITION(shader_program_, "Failed to create shader program");

		vertex_shader_->compile();
		fragment_shader_->compile();

		shader_program_->attach(vertex_shader_);
		shader_program_->attach(fragment_shader_);

		if (shader_program_->link()) {
			CITADEL_LOG_ERROR("Failed to link shader program. TODO: Replace this log with an exception");
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

		shader_program_->fetch_uniforms();

		using uniform_map = std::unordered_map<std::string, uniform_info>;
		uniform_map uniforms = shader_program_->get_uniforms();

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
				CITADEL_UNREACHABLE("Shader data type must not be unknown");
				break;

			default:
				CITADEL_UNREACHABLE("Unknown shader data type: {0}", uniform.type);
				break;
			}
		}
	}

	void material::use() const {
		shader_program_->use();
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
		if (bool_uniforms_.find(name) == bool_uniforms_.end()) {
			CITADEL_LOG_WARNING("Boolean uniform '{0}' not found", name);
			return;
		}
		bool_uniforms_[name] = value;
	}

	void material::set_uniform_int(const std::string& name, int value) {
		if (int_uniforms_.find(name) == int_uniforms_.end()) {
			CITADEL_LOG_WARNING("Integer uniform '{0}' not found", name);
			return;
		}
		int_uniforms_[name] = value;
	}

	void material::set_uniform_ivec2(const std::string& name, const ivec2& value) {
		if (ivec2_uniforms_.find(name) == ivec2_uniforms_.end()) {
			CITADEL_LOG_WARNING("Integer 2D vector uniform '{0}' not found", name);
			return;
		}
		ivec2_uniforms_[name] = value;
	}

	void material::set_uniform_ivec3(const std::string& name, const ivec3& value) {
		if (ivec3_uniforms_.find(name) == ivec3_uniforms_.end()) {
			CITADEL_LOG_WARNING("Integer 3D vector uniform '{0}' not found", name);
			return;
		}
		ivec3_uniforms_[name] = value;
	}

	void material::set_uniform_ivec4(const std::string& name, const ivec4& value) {
		if (ivec4_uniforms_.find(name) == ivec4_uniforms_.end()) {
			CITADEL_LOG_WARNING("Integer 4D vector uniform '{0}' not found", name);
			return;
		}
		ivec4_uniforms_[name] = value;
	}

	void material::set_uniform_float(const std::string& name, float value) {
		if (float_uniforms_.find(name) == float_uniforms_.end()) {
			CITADEL_LOG_WARNING("Floating point uniform '{0}' not found", name);
			return;
		}
		float_uniforms_[name] = value;
	}

	void material::set_uniform_vec2(const std::string& name, const vec2& value) {
		if (vec2_uniforms_.find(name) == vec2_uniforms_.end()) {
			CITADEL_LOG_WARNING("2D vector uniform '{0}' not found", name);
			return;
		}
		vec2_uniforms_[name] = value;
	}

	void material::set_uniform_vec3(const std::string& name, const vec3& value) {
		if (vec3_uniforms_.find(name) == vec3_uniforms_.end()) {
			CITADEL_LOG_WARNING("3D vector uniform '{0}' not found", name);
			return;
		}
		vec3_uniforms_[name] = value;
	}

	void material::set_uniform_vec4(const std::string& name, const vec4& value) {
		if (vec4_uniforms_.find(name) == vec4_uniforms_.end()) {
			CITADEL_LOG_WARNING("3D vector uniform '{0}' not found", name);
			return;
		}
		vec4_uniforms_[name] = value;
	}

	void material::set_uniform_mat3(const std::string& name, const mat3& value) {
		if (mat3_uniforms_.find(name) == mat3_uniforms_.end()) {
			CITADEL_LOG_WARNING("3x3 matrix uniform '{0}' not found", name);
			return;
		}
		mat3_uniforms_[name] = value;
	}

	void material::set_uniform_mat4(const std::string& name, const mat4& value) {
		if (mat4_uniforms_.find(name) == mat4_uniforms_.end()) {
			CITADEL_LOG_WARNING("4x4 matrix uniform '{0}' not found", name);
			return;
		}
		mat4_uniforms_[name] = value;
	}

	shader& material::vertex_shader() {
		return *vertex_shader_;
	}

	shader& material::fragment_shader() {
		return *fragment_shader_;
	}

	shader_program& material::shader_program() {
		return *shader_program_;
	}
}
