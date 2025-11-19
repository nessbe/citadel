// File:       shader_program.cpp
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
#include "citadel/rendering/shaders/shader_program.hpp"

#include "citadel/drivers/opengl/opengl_shader_program.hpp"

namespace citadel {
CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_UNREACHABLE_CODE)

	std::unique_ptr<shader_program> shader_program::create(rendering_api::api api, const std::string& name) {
		switch (api) {
		case rendering_api::api::none:
			CITADEL_PANIC("Rendering API cannot be none");
			return nullptr;

		case rendering_api::api::opengl:
			return std::make_unique<opengl_shader_program>(name);
		}

		CITADEL_PANIC("Unknown rendering API");
		return nullptr;
	}

CITADEL_IGNORE_WARNING_POP()

	shader_program::shader_program(const std::string& name)
		: name_(name) { }

	bool shader_program::link() {
		return _link();
	}

	void shader_program::use() {
		_use();
	}

	bool shader_program::attach(const std::shared_ptr<shader>& shader) {
		CITADEL_ASSERT(shader, "The given shader is null");

		shader_type type = shader->get_type();

		if (has_shader(type)) {
			return false;
		}

		_attach(shader);
		shaders_[type] = shader;

		return true;
	}

	void shader_program::detach(shader_type type) {
		if (!has_shader(type)) {
			return;
		}

		const std::shared_ptr<shader>& shader = shaders_.at(type);
		_detach(shader);

		shaders_.erase(type);
	}

	void shader_program::set_uniform_boolean(const std::string& name, bool value) {
		_set_uniform_boolean(name, value);
	}

	void shader_program::set_uniform_int1(const std::string& name, int value) {
		_set_uniform_int1(name, value);
	}

	void shader_program::set_uniform_int2(const std::string& name, const ivec2& value) {
		_set_uniform_int2(name, value);
	}

	void shader_program::set_uniform_int3(const std::string& name, const ivec3& value) {
		_set_uniform_int3(name, value);
	}

	void shader_program::set_uniform_int4(const std::string& name, const ivec4& value) {
		_set_uniform_int4(name, value);
	}

	void shader_program::set_uniform_float1(const std::string& name, float value) {
		_set_uniform_float1(name, value);
	}

	void shader_program::set_uniform_float2(const std::string& name, const vec2& value) {
		_set_uniform_float2(name, value);
	}

	void shader_program::set_uniform_float3(const std::string& name, const vec3& value) {
		_set_uniform_float3(name, value);
	}

	void shader_program::set_uniform_float4(const std::string& name, const vec4& value) {
		_set_uniform_float4(name, value);
	}

	void shader_program::set_uniform_mat3(const std::string& name, const mat3& value) {
		_set_uniform_mat3(name, value);
	}

	void shader_program::set_uniform_mat4(const std::string& name, const mat4& value) {
		_set_uniform_mat4(name, value);
	}

	std::vector<std::shared_ptr<shader>> shader_program::get_shaders() const {
		std::vector<std::shared_ptr<shader>> shaders;
		shaders.reserve(shaders_.size());

		std::transform(shaders_.begin(), shaders_.end(), std::back_inserter(shaders), [](const std::pair<shader_type, std::shared_ptr<shader>> shader) {
			return shader.second;
		});

		return shaders;
	}

	bool shader_program::has_shader(shader_type type) const {
		return shaders_.find(type) != shaders_.end();
	}

	std::shared_ptr<shader> shader_program::get_shader(shader_type type) const {
		if (!has_shader(type)) {
			return nullptr;
		}

		return shaders_.at(type);
	}

	const std::string& shader_program::get_name() const noexcept {
		return name_;
	}
}
