// File:       opengl_shader.cpp
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
#include "citadel/drivers/opengl/opengl_shader.hpp"

namespace citadel {
CITADEL_IGNORE_WARNING_PUSH();
CITADEL_IGNORE_WARNING(CITADEL_WARNING_UNREACHABLE_CODE);

	opengl_shader::native_type opengl_shader::to_native_type(shader_type type) noexcept {
		switch (type) {
		case shader_type::vertex:
			return GL_VERTEX_SHADER;

		case shader_type::fragment:
			return GL_FRAGMENT_SHADER;

		default:
			CITADEL_PANIC("The given is shader type is not yet supported for OpenGL");
		}
	}

CITADEL_IGNORE_WARNING_POP();

	opengl_shader::opengl_shader(const std::string& name, shader_type type, const std::string& source)
		: shader(name, type, source)
	{
		id_ = glCreateShader(get_native_type());
		CITADEL_SOFT_ASSERT(id_, "Failed to create OpenGL shader");

		const char* raw_source = source.c_str();
		glShaderSource(id_, 1, &raw_source, nullptr);
	}

	opengl_shader::opengl_shader(const std::string& name, shader_type type)
		: opengl_shader(name, type, "") { }

	opengl_shader::opengl_shader(opengl_shader&& other) noexcept
		: opengl_shader(other.get_name(), other.get_type(), other.get_source())
	{
		id_ = other.id_;
		other.id_ = 0;
	}

	opengl_shader::~opengl_shader() {
		glDeleteBuffers(1, &id_);
	}

	opengl_shader& opengl_shader::operator=(opengl_shader&& other) noexcept {
		if (this != &other) {
			glDeleteBuffers(1, &id_);

			id_ = other.id_;
			other.id_ = 0;
		}

		return *this;
	}

	opengl_shader::id opengl_shader::get_id() const noexcept {
		return id_;
	}

	opengl_shader::native_type opengl_shader::get_native_type() const noexcept {
		return to_native_type(get_type());
	}

	bool opengl_shader::_compile() {
		glCompileShader(id_);

		GLint success = 0;
		glGetShaderiv(id_, GL_COMPILE_STATUS, &success);

		if (success == GL_FALSE) {
			GLint log_length = 0;
			glGetShaderiv(id_, GL_INFO_LOG_LENGTH, &log_length);

			std::string log(static_cast<std::size_t>(log_length), '\0');
			glGetShaderInfoLog(id_, log_length, nullptr, &log[0]);

			std::cerr << "[CITADEL][ERROR][SHADER] " << log << std::endl;
			return false;
		}

		return true;
	}

	void opengl_shader::_set_source(const std::string& value) {
		const char* source = value.c_str();
		glShaderSource(id_, 1, &source, nullptr);
	}
}
