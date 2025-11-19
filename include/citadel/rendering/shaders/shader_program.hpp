// File:       shader_program.hpp
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

#include <memory>
#include <string>
#include <unordered_map>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/rendering/shaders/shader.hpp"
#include "citadel/rendering/shaders/shader_type.hpp"

CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_PADDING)

namespace citadel {
	class api shader_program {
	public:
		static std::unique_ptr<shader_program> create(const std::string& name);

		shader_program(const std::string& name);
		virtual ~shader_program() = default;

		shader_program(const shader_program&) = delete;
		shader_program& operator=(const shader_program&) = delete;

		bool link();
		void use();

		bool attach(const std::shared_ptr<shader>& shader);
		void detach(shader_type type);

		void set_uniform_boolean(const std::string& name, bool value);

		void set_uniform_int1(const std::string& name, int value);
		void set_uniform_int2(const std::string& name, const ivec2& value);
		void set_uniform_int3(const std::string& name, const ivec3& value);
		void set_uniform_int4(const std::string& name, const ivec4& value);

		void set_uniform_float1(const std::string& name, float value);
		void set_uniform_float2(const std::string& name, const vec2& value);
		void set_uniform_float3(const std::string& name, const vec3& value);
		void set_uniform_float4(const std::string& name, const vec4& value);

		void set_uniform_mat3(const std::string& name, const mat3& value);
		void set_uniform_mat4(const std::string& name, const mat4& value);

		nodisc std::vector<std::shared_ptr<shader>> get_shaders() const;
		nodisc bool has_shader(shader_type type) const;
		nodisc std::shared_ptr<shader> get_shader(shader_type type) const;

		nodisc const std::string& get_name() const noexcept;

	private:
		std::unordered_map<shader_type, std::shared_ptr<shader>> shaders_;
		std::string name_;

	private:
		virtual bool _link() = 0;
		virtual void _use() = 0;

		virtual void _attach(const std::shared_ptr<shader>& shader) = 0;
		virtual void _detach(const std::shared_ptr<shader>& shader) = 0;

		virtual void _set_uniform_boolean(const std::string& name, bool value) = 0;

		virtual void _set_uniform_int1(const std::string& name, int value) = 0;
		virtual void _set_uniform_int2(const std::string& name, const ivec2& value) = 0;
		virtual void _set_uniform_int3(const std::string& name, const ivec3& value) = 0;
		virtual void _set_uniform_int4(const std::string& name, const ivec4& value) = 0;

		virtual void _set_uniform_float1(const std::string& name, float value) = 0;
		virtual void _set_uniform_float2(const std::string& name, const vec2& value) = 0;
		virtual void _set_uniform_float3(const std::string& name, const vec3& value) = 0;
		virtual void _set_uniform_float4(const std::string& name, const vec4& value) = 0;

		virtual void _set_uniform_mat3(const std::string& name, const mat3& value) = 0;
		virtual void _set_uniform_mat4(const std::string& name, const mat4& value) = 0;
	};
}

CITADEL_IGNORE_WARNING_POP()
