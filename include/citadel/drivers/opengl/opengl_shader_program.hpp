// File:       opengl_shader_program.hpp
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

#pragma once

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/drivers/opengl.hpp"

#include "citadel/memory/reference.hpp"

#include "citadel/rendering/shaders/shader.hpp"
#include "citadel/rendering/shaders/shader_program.hpp"
#include "citadel/rendering/shaders/shader_type.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported opengl_shader_program : public shader_program {
	public:
		using id = GLuint;

	public:
		opengl_shader_program(const std::string& name);
		virtual ~opengl_shader_program() override;

		opengl_shader_program(const opengl_shader_program&) = delete;
		opengl_shader_program& operator=(const opengl_shader_program&) = delete;

		opengl_shader_program(opengl_shader_program&& other) noexcept;
		opengl_shader_program& operator=(opengl_shader_program&& other) noexcept;

		nodisc id get_id() const noexcept;

	private:
		id id_ = 0;

	private:
		virtual bool _link() override;
		virtual void _use() override;

		virtual void _attach(const reference<shader>& shader) override;
		virtual void _detach(const reference<shader>& shader) override;

		virtual void _set_uniform_bool(const std::string& name, bool value) override;

		virtual void _set_uniform_int(const std::string& name, int value) override;
		virtual void _set_uniform_ivec2(const std::string& name, const ivec2& value) override;
		virtual void _set_uniform_ivec3(const std::string& name, const ivec3& value) override;
		virtual void _set_uniform_ivec4(const std::string& name, const ivec4& value) override;

		virtual void _set_uniform_float(const std::string& name, float value) override;
		virtual void _set_uniform_vec2(const std::string& name, const vec2& value) override;
		virtual void _set_uniform_vec3(const std::string& name, const vec3& value) override;
		virtual void _set_uniform_vec4(const std::string& name, const vec4& value) override;

		virtual void _set_uniform_mat3(const std::string& name, const mat3& value) override;
		virtual void _set_uniform_mat4(const std::string& name, const mat4& value) override;

		virtual void _fetch_uniforms() override;
	};
}

CITADEL_WARNING_IGNORE_POP
