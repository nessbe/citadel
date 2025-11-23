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

#include "citadel/rendering/render_command.hpp"

#include "citadel/drivers/opengl/opengl_shader_program.hpp"

namespace citadel {
CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_UNREACHABLE_CODE)

	std::unique_ptr<shader_program> shader_program::create(rendering_api_type api, const std::string& name) {
		switch (api) {
		case rendering_api_type::none:
			CITADEL_PANIC("Rendering API cannot be none");
			return nullptr;

		case rendering_api_type::opengl:
			return std::make_unique<opengl_shader_program>(name);
		}

		CITADEL_PANIC("Unknown rendering API");
		return nullptr;
	}

CITADEL_IGNORE_WARNING_POP()

	std::unique_ptr<shader_program> shader_program::create(const std::string& name) {
		return create(render_command::get_api(), name);
	}

	shader_program::shader_program(const std::string& name)
		: name_(name) { }

	bool shader_program::link() {
		bool result = _link();

		if (result) {
			fetch_uniforms();
		}

		return result;
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

	void shader_program::fetch_uniforms() {
		uniforms_.clear();
		_fetch_uniforms();
	}

	void shader_program::set_uniform_bool(const std::string& name, bool value) {
		_set_uniform_bool(name, value);
	}

	void shader_program::set_uniform_int(const std::string& name, int value) {
		_set_uniform_int(name, value);
	}

	void shader_program::set_uniform_ivec2(const std::string& name, const ivec2& value) {
		_set_uniform_ivec2(name, value);
	}

	void shader_program::set_uniform_ivec3(const std::string& name, const ivec3& value) {
		_set_uniform_ivec3(name, value);
	}

	void shader_program::set_uniform_ivec4(const std::string& name, const ivec4& value) {
		_set_uniform_ivec4(name, value);
	}

	void shader_program::set_uniform_float(const std::string& name, float value) {
		_set_uniform_float(name, value);
	}

	void shader_program::set_uniform_vec2(const std::string& name, const vec2& value) {
		_set_uniform_vec2(name, value);
	}

	void shader_program::set_uniform_vec3(const std::string& name, const vec3& value) {
		_set_uniform_vec3(name, value);
	}

	void shader_program::set_uniform_vec4(const std::string& name, const vec4& value) {
		_set_uniform_vec4(name, value);
	}

	void shader_program::set_uniform_mat3(const std::string& name, const mat3& value) {
		_set_uniform_mat3(name, value);
	}

	void shader_program::set_uniform_mat4(const std::string& name, const mat4& value) {
		_set_uniform_mat4(name, value);
	}

	bool shader_program::uniform_exists(const std::string& name) const {
		return uniforms_.find(name) != uniforms_.end();
	}

	const uniform_info& shader_program::get_uniform(const std::string& name) const {
		CITADEL_ASSERT(uniform_exists(name), "Uniform '" + name + "' does not exist");
		return uniforms_.at(name);
	}

	const std::unordered_map<std::string, uniform_info>& shader_program::get_uniforms() const noexcept {
		return uniforms_;
	}

	std::size_t shader_program::uniform_count() const noexcept {
		return uniforms_.size();
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

	void shader_program::add_uniform(const uniform_info& uniform) {
		if (!uniform_exists(uniform.name)) {
			uniforms_.emplace(uniform.name, uniform);
		}
	}
}
