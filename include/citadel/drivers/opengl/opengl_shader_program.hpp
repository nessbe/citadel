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

#include "citadel/rendering/shaders/shader.hpp"
#include "citadel/rendering/shaders/shader_program.hpp"
#include "citadel/rendering/shaders/shader_type.hpp"

CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_PADDING)

namespace citadel {
	class api opengl_shader_program : public shader_program {
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

		virtual void _attach(const std::shared_ptr<shader>& shader) override;
		virtual void _detach(const std::shared_ptr<shader>& shader) override;

		virtual void _set_uniform_boolean(const std::string& name, bool value) override;

		virtual void _set_uniform_int1(const std::string& name, int value) override;
		virtual void _set_uniform_int2(const std::string& name, const ivec2& value) override;
		virtual void _set_uniform_int3(const std::string& name, const ivec3& value) override;
		virtual void _set_uniform_int4(const std::string& name, const ivec4& value) override;

		virtual void _set_uniform_float1(const std::string& name, float value) override;
		virtual void _set_uniform_float2(const std::string& name, const vec2& value) override;
		virtual void _set_uniform_float3(const std::string& name, const vec3& value) override;
		virtual void _set_uniform_float4(const std::string& name, const vec4& value) override;

		virtual void _set_uniform_mat3(const std::string& name, const mat3& value) override;
		virtual void _set_uniform_mat4(const std::string& name, const mat4& value) override;
	};
}

CITADEL_IGNORE_WARNING_POP()
