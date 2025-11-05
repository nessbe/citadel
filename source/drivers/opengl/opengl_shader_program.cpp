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
		: shader_program(name) { }

	opengl_shader_program::opengl_shader_program(opengl_shader_program&& other) noexcept
		: opengl_shader_program(other.get_name()) {
		id_ = other.id_;
		other.id_ = id_;
	}

	opengl_shader_program& opengl_shader_program::operator=(opengl_shader_program&& other) noexcept {
		if (this != &other) {
			destroy();
		}

		return *this;
	}

	opengl_shader_program::id opengl_shader_program::get_id() const noexcept {
		return id_;
	}

	void opengl_shader_program::_construct() {
		destroy();
		id_ = glCreateProgram();
		CITADEL_ASSERT(id_, "Failed to create OpenGL shader program");
	}

	void opengl_shader_program::_destroy() noexcept {
		if (id_) {
			glDeleteProgram(id_);
			id_ = 0;
		}
	}

	bool opengl_shader_program::_link() {
		CITADEL_ASSERT(id_, "Shader program is not yet constructed");
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
		CITADEL_ASSERT(id_, "Shader program is not yet constructed");
		glUseProgram(id_);
	}

	void opengl_shader_program::_attach(shader* shader) {
		opengl_shader* driver_shader = dynamic_cast<opengl_shader*>(shader);
		CITADEL_ASSERT(driver_shader, "The given shader is not a valid OpenGL shader");

		if (driver_shader) {
			opengl_shader::id shader_id = driver_shader->get_id();
			CITADEL_ASSERT(shader_id, "The given shader is not yet constructed");

			CITADEL_ASSERT(id_, "Shader program is not yet constructed");
			glAttachShader(id_, shader_id);
		}
	}

	void opengl_shader_program::_detach(shader* shader) {
		opengl_shader* driver_shader = dynamic_cast<opengl_shader*>(shader);
		CITADEL_ASSERT(driver_shader, "The given shader is not a valid OpenGL shader");

		if (driver_shader) {
			opengl_shader::id shader_id = driver_shader->get_id();
			CITADEL_ASSERT(shader_id, "The given shader is not yet constructed");

			CITADEL_ASSERT(id_, "Shader program is not yet constructed");
			glDetachShader(id_, shader_id);
		}
	}
}
