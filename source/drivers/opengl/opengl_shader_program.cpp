// File:       opengl_shader_program.cpp
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
#include "citadel/drivers/opengl/opengl_shader_program.hpp"

#include "citadel/drivers/opengl/opengl_shader.hpp"

#include "citadel/rendering/shaders/uniform_info.hpp"

namespace citadel {
	opengl_shader_program::opengl_shader_program(const std::string& name)
		: shader_program(name)
	{
		id_ = glCreateProgram();
		CITADEL_ASSERT(id_ != 0, "Failed to create OpenGL shader program");
	}

	opengl_shader_program::~opengl_shader_program() {
		glDeleteProgram(id_);
	}

	opengl_shader_program::opengl_shader_program(opengl_shader_program&& other) noexcept
		: opengl_shader_program(other.get_name())
	{
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

	opengl_shader_program::id_type opengl_shader_program::get_id() const noexcept {
		return id_;
	}

	bool opengl_shader_program::_link() {
		glLinkProgram(id_);

		GLint success = 0;
		glGetProgramiv(id_, GL_LINK_STATUS, &success);

		if (success == GL_FALSE) {
			GLint log_length = 0;
			glGetProgramiv(id_, GL_INFO_LOG_LENGTH, &log_length);

			std::string log_message(static_cast<std::size_t>(log_length), '\0');
			glGetProgramInfoLog(id_, log_length, nullptr, &log_message[0]);

			CITADEL_LOG_ERROR("OpenGL shader program linking error: {0}", log_message);
			return false;
		}

		return true;
	}

	void opengl_shader_program::_use() const {
		glUseProgram(id_);
	}

	void opengl_shader_program::_attach(const reference<shader>& shader) {
		reference<opengl_shader> opengl_shader = std::dynamic_pointer_cast<class opengl_shader>(shader);
		CITADEL_ASSERT(opengl_shader, "Shader must be an OpenGL shader");

		if (opengl_shader) {
			opengl_shader::id_type shader_id = opengl_shader->get_id();
			glAttachShader(id_, shader_id);
		}
	}

	void opengl_shader_program::_detach(const reference<shader>& shader) {
		reference<opengl_shader> opengl_shader = std::dynamic_pointer_cast<class opengl_shader>(shader);
		CITADEL_ASSERT(opengl_shader, "Shader must be an OpenGL shader");

		if (opengl_shader) {
			opengl_shader::id_type shader_id = opengl_shader->get_id();
			glDetachShader(id_, shader_id);
		}
	}

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_SPECTRE)

	void opengl_shader_program::_set_uniform_bool(const std::string& name, bool value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		if (location < 0) {
			CITADEL_LOG_WARNING("Boolean uniform '{0}' not found in OpenGL shader program {1}", name, id_);
			return;
		}
		glUniform1i(location, value);
	}

	void opengl_shader_program::_set_uniform_int(const std::string& name, int value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		if (location < 0) {
			CITADEL_LOG_WARNING("Integer uniform '{0}' not found in OpenGL shader program {1}", name, id_);
			return;
		}
		glUniform1i(location, value);
	}

	void opengl_shader_program::_set_uniform_ivec2(const std::string& name, const ivec2& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		if (location < 0) {
			CITADEL_LOG_WARNING("Integer 2D vector uniform '{0}' not found in OpenGL shader program {1}", name, id_);
			return;
		}
		glUniform2i(location, value.x, value.y);
	}

	void opengl_shader_program::_set_uniform_ivec3(const std::string& name, const ivec3& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		if (location < 0) {
			CITADEL_LOG_WARNING("Integer 3D vector uniform '{0}' not found in OpenGL shader program {1}", name, id_);
			return;
		}
		glUniform3i(location, value.x, value.y, value.z);
	}

	void opengl_shader_program::_set_uniform_ivec4(const std::string& name, const ivec4& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		if (location < 0) {
			CITADEL_LOG_WARNING("Integer 4D uniform '{0}' not found in OpenGL shader program {1}", name, id_);
			return;
		}
		glUniform4i(location, value.x, value.y, value.z, value.w);
	}

	void opengl_shader_program::_set_uniform_float(const std::string& name, float value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		if (location < 0) {
			CITADEL_LOG_WARNING("Floating point uniform '{0}' not found in OpenGL shader program {1}", name, id_);
			return;
		}
		glUniform1f(location, value);
	}

	void opengl_shader_program::_set_uniform_vec2(const std::string& name, const vec2& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		if (location < 0) {
			CITADEL_LOG_WARNING("2D vector uniform '{0}' not found in OpenGL shader program {1}", name, id_);
			return;
		}
		glUniform2f(location, value.x, value.y);
	}

	void opengl_shader_program::_set_uniform_vec3(const std::string& name, const vec3& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		if (location < 0) {
			CITADEL_LOG_WARNING("3D vector uniform '{0}' not found in OpenGL shader program {1}", name, id_);
			return;
		}
		glUniform3f(location, value.x, value.y, value.z);
	}

	void opengl_shader_program::_set_uniform_vec4(const std::string& name, const vec4& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		if (location < 0) {
			CITADEL_LOG_WARNING("4D vector uniform '{0}' not found in OpenGL shader program {1}", name, id_);
			return;
		}
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}

	void opengl_shader_program::_set_uniform_mat3(const std::string& name, const mat3& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		if (location < 0) {
			CITADEL_LOG_WARNING("3x3 matrix uniform '{0}' not found in OpenGL shader program {1}", name, id_);
			return;
		}
		glUniformMatrix3fv(location, 1, GL_FALSE, value.data());
	}

	void opengl_shader_program::_set_uniform_mat4(const std::string& name, const mat4& value) {
		GLint location = glGetUniformLocation(id_, name.c_str());
		if (location < 0) {
			CITADEL_LOG_WARNING("4x4 matrix uniform '{0}' not found in OpenGL shader program {1}", name, id_);
			return;
		}
		glUniformMatrix4fv(location, 1, GL_FALSE, value.data());
	}

	void opengl_shader_program::_fetch_uniforms() {
		GLint uniform_count;
		glGetProgramiv(id_, GL_ACTIVE_UNIFORMS, &uniform_count);

		GLint max_uniform_name_length;
		glGetProgramiv(id_, GL_ACTIVE_UNIFORM_MAX_LENGTH, &max_uniform_name_length);

		for (GLint i = 0; i < uniform_count; i++) {
			GLchar uniform_name[256];
			GLsizei uniform_name_length = 0;

			GLint uniform_size = 0;
			GLenum uniform_type = 0;

			glGetActiveUniform(
				id_,
				static_cast<GLuint>(i),
				256,
				&uniform_name_length,
				&uniform_size,
				&uniform_type,
				uniform_name
			);

			GLint uniform_location = glGetUniformLocation(id_, uniform_name);

			uniform_info uniform = {
				uniform_name,
				shader_data_type_from_opengl(uniform_type),
				static_cast<std::size_t>(uniform_size),
				static_cast<std::uint32_t>(uniform_location)
			};

			add_uniform(uniform);
		}
	}

CITADEL_WARNING_IGNORE_POP

}
