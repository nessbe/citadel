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

#include "citadel/memory/reference.hpp"
#include "citadel/memory/scope.hpp"

#include "citadel/rendering/rendering_api_type.hpp"

#include "citadel/rendering/shaders/shader.hpp"
#include "citadel/rendering/shaders/shader_type.hpp"
#include "citadel/rendering/shaders/uniform_info.hpp"

CITADEL_IGNORE_WARNING_PUSH();
CITADEL_IGNORE_WARNING(CITADEL_WARNING_PADDING);

namespace citadel {
	class exported shader_program {
	public:
		nodisc static scope<shader_program> create(rendering_api_type api, const std::string& name);
		nodisc static scope<shader_program> create(const std::string& name);

		shader_program(const std::string& name);
		virtual ~shader_program() = default;

		shader_program(const shader_program&) = delete;
		shader_program& operator=(const shader_program&) = delete;

		bool link();
		void use();

		bool attach(const reference<shader>& shader);
		void detach(shader_type type);

		void fetch_uniforms();

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

		nodisc bool uniform_exists(const std::string& name) const;
		nodisc const uniform_info& get_uniform(const std::string& name) const;
		nodisc const std::unordered_map<std::string, uniform_info>& get_uniforms() const noexcept;
		nodisc std::size_t uniform_count() const noexcept;

		nodisc std::vector<reference<shader>> get_shaders() const;
		nodisc bool has_shader(shader_type type) const;
		nodisc reference<shader> get_shader(shader_type type) const;

		nodisc const std::string& get_name() const noexcept;

	protected:
		void add_uniform(const uniform_info& uniform);

	private:
		std::unordered_map<shader_type, reference<shader>> shaders_;
		std::unordered_map<std::string, uniform_info> uniforms_;
		std::string name_;

	private:

		virtual bool _link() = 0;
		virtual void _use() = 0;

		virtual void _attach(const reference<shader>& shader) = 0;
		virtual void _detach(const reference<shader>& shader) = 0;

		virtual void _set_uniform_bool(const std::string& name, bool value) = 0;

		virtual void _set_uniform_int(const std::string& name, int value) = 0;
		virtual void _set_uniform_ivec2(const std::string& name, const ivec2& value) = 0;
		virtual void _set_uniform_ivec3(const std::string& name, const ivec3& value) = 0;
		virtual void _set_uniform_ivec4(const std::string& name, const ivec4& value) = 0;

		virtual void _set_uniform_float(const std::string& name, float value) = 0;
		virtual void _set_uniform_vec2(const std::string& name, const vec2& value) = 0;
		virtual void _set_uniform_vec3(const std::string& name, const vec3& value) = 0;
		virtual void _set_uniform_vec4(const std::string& name, const vec4& value) = 0;

		virtual void _set_uniform_mat3(const std::string& name, const mat3& value) = 0;
		virtual void _set_uniform_mat4(const std::string& name, const mat4& value) = 0;

		virtual void _fetch_uniforms() = 0;
	};
}

CITADEL_IGNORE_WARNING_POP();
