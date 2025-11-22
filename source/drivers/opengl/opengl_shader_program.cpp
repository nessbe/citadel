// File:       opengl_shader_program.cpp
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
#include "citadel/drivers/opengl/opengl_shader_program.hpp"

#include "citadel/drivers/opengl/opengl_shader.hpp"

namespace citadel {
	opengl_shader_program::opengl_shader_program(const std::string& name)
		: shader_program(name) {
		id_ = glCreateProgram();
		CITADEL_ASSERT(id_, "Failed to create OpenGL shader program");
	}

	opengl_shader_program::~opengl_shader_program() {
		glDeleteProgram(id_);
	}

	opengl_shader_program::opengl_shader_program(opengl_shader_program&& other) noexcept
		: opengl_shader_program(other.get_name()) {
		id_ = other.id_;
		other.id_ = 0;
	}

	opengl_shader_program& opengl_shader_program::operator=(opengl_shader_program&& other) noexcept {
		if (this != &other) {
			id_ = other.id_;
			other.id_ = 0;
		}

		return *this;
	}

	opengl_shader_program::id opengl_shader_program::get_id() const noexcept {
		return id_;
	}

	bool opengl_shader_program::_link() {
		CITADEL_ASSERT(id_, "Shader program is not yet created");
		glLinkProgram(id_);

		GLint success = 0;
		glGetProgramiv(id_, GL_LINK_STATUS, &success);

		if (success == GL_FALSE) {
			GLint log_length = 0;
			glGetProgramiv(id_, GL_INFO_LOG_LENGTH, &log_length);

			std::string log(static_cast<std::size_t>(log_length), '\0');
			glGetProgramInfoLog(id_, log_length, nullptr, &log[0]);

			std::cerr << "[CITADEL][ERROR][SHADER_PROGRAM] " << log << std::endl;
			return false;
		}

		return true;
	}

	void opengl_shader_program::_use() {
		CITADEL_ASSERT(id_, "Shader program is not yet created");
		glUseProgram(id_);
	}

	void opengl_shader_program::_attach(const std::shared_ptr<shader>& shader) {
		std::shared_ptr<opengl_shader> driver_shader = std::dynamic_pointer_cast<opengl_shader>(shader);
		CITADEL_ASSERT(driver_shader, "The given shader is not a valid OpenGL shader");

		if (driver_shader) {
			opengl_shader::id shader_id = driver_shader->get_id();
			CITADEL_ASSERT(shader_id, "The given shader is not yet created");

			CITADEL_ASSERT(id_, "Shader program is not yet created");
			glAttachShader(id_, shader_id);
		}
	}

	void opengl_shader_program::_detach(const std::shared_ptr<shader>& shader) {
		std::shared_ptr<opengl_shader> driver_shader = std::dynamic_pointer_cast<opengl_shader>(shader);
		CITADEL_ASSERT(driver_shader, "The given shader is not a valid OpenGL shader");

		if (driver_shader) {
			opengl_shader::id shader_id = driver_shader->get_id();
			CITADEL_ASSERT(shader_id, "The given shader is not yet created");

			CITADEL_ASSERT(id_, "Shader program is not yet created");
			glDetachShader(id_, shader_id);
		}
	}

	void opengl_shader_program::_set_uniform_bool(const std::string& name, bool value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		CITADEL_ASSERT(location >= 0, "Uniform '" + name + "' not found in shader program " + std::to_string(id_));
		glUniform1i(location, value);
	}

	void opengl_shader_program::_set_uniform_int(const std::string& name, int value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		CITADEL_ASSERT(location >= 0, "Uniform '" + name + "' not found in shader program " + std::to_string(id_));
		glUniform1i(location, value);
	}

	void opengl_shader_program::_set_uniform_ivec2(const std::string& name, const ivec2& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		CITADEL_ASSERT(location >= 0, "Uniform '" + name + "' not found in shader program " + std::to_string(id_));
		glUniform2i(location, value.x, value.y);
	}

	void opengl_shader_program::_set_uniform_ivec3(const std::string& name, const ivec3& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		CITADEL_ASSERT(location >= 0, "Uniform '" + name + "' not found in shader program " + std::to_string(id_));
		glUniform3i(location, value.x, value.y, value.z);
	}

	void opengl_shader_program::_set_uniform_ivec4(const std::string& name, const ivec4& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		CITADEL_ASSERT(location >= 0, "Uniform '" + name + "' not found in shader program " + std::to_string(id_));
		glUniform4i(location, value.x, value.y, value.z, value.w);
	}

	void opengl_shader_program::_set_uniform_float(const std::string& name, float value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		CITADEL_ASSERT(location >= 0, "Uniform '" + name + "' not found in shader program " + std::to_string(id_));
		glUniform1f(location, value);
	}

	void opengl_shader_program::_set_uniform_vec2(const std::string& name, const vec2& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		CITADEL_ASSERT(location >= 0, "Uniform '" + name + "' not found in shader program " + std::to_string(id_));
		glUniform2f(location, value.x, value.y);
	}

	void opengl_shader_program::_set_uniform_vec3(const std::string& name, const vec3& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		CITADEL_ASSERT(location >= 0, "Uniform '" + name + "' not found in shader program " + std::to_string(id_));
		glUniform3f(location, value.x, value.y, value.z);
	}

	void opengl_shader_program::_set_uniform_vec4(const std::string& name, const vec4& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		CITADEL_ASSERT(location >= 0, "Uniform '" + name + "' not found in shader program " + std::to_string(id_));
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}

	void opengl_shader_program::_set_uniform_mat3(const std::string& name, const mat3& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		CITADEL_ASSERT(location >= 0, "Uniform '" + name + "' not found in shader program " + std::to_string(id_));
		glUniformMatrix3fv(location, 1, GL_FALSE, value.data());
	}

	void opengl_shader_program::_set_uniform_mat4(const std::string& name, const mat4& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		CITADEL_ASSERT(location >= 0, "Uniform '" + name + "' not found in shader program " + std::to_string(id_));
		glUniformMatrix4fv(location, 1, GL_FALSE, value.data());
	}
}
