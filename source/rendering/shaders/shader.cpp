// File:       shader.cpp
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
#include "citadel/rendering/shaders/shader.hpp"

#include "citadel/rendering/render_command.hpp"

#include "citadel/drivers/opengl/opengl_shader.hpp"

namespace citadel {

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_UNREACHABLE_CODE)

	reference<shader> shader::create(rendering_api_type api, const std::string& name, shader_type type, const std::string& source) {
		switch (api) {
		case rendering_api_type::none:
			CITADEL_UNREACHABLE("Rendering API must not be none");
			return nullptr;

		case rendering_api_type::opengl:
			return make_referenced<opengl_shader>(name, type, source);

		default:
			CITADEL_UNREACHABLE("Unknown rendering API: {0}", api);
			return nullptr;
		}
	}

	reference<shader> shader::create(rendering_api_type api, const std::string& name, shader_type type) {
		switch (api) {
		case rendering_api_type::none:
			CITADEL_UNREACHABLE("Rendering API must not be none");
			return nullptr;

		case rendering_api_type::opengl:
			return make_referenced<opengl_shader>(name, type);

		default:
			CITADEL_UNREACHABLE("Unknown rendering API: {0}", api);
			return nullptr;
		}
	}

CITADEL_WARNING_IGNORE_POP

	reference<shader> shader::create(const std::string& name, shader_type type, const std::string& source) {
		return create(render_command::get_api(), name, type, source);
	}

	reference<shader> shader::create(const std::string& name, shader_type type) {
		return create(render_command::get_api(), name, type);
	}

	shader::shader(const std::string& name, shader_type type, const std::string& source)
		: name_(name), source_(source), type_(type) { }

	shader::shader(const std::string& name, shader_type type)
		: shader(name, type, "") { }

	bool shader::compile() {
		bool result = _compile();
		is_compiled_ = result ? result : is_compiled_;
		return result;
	}

	const std::string& shader::get_name() const noexcept {
		return name_;
	}

	const std::string& shader::get_source() const noexcept {
		return source_;
	}

	void shader::set_source(const std::string& value) {
		_set_source(value);
		source_ = value;
		is_compiled_ = false;
	}

	shader_type shader::get_type() const noexcept {
		return type_;
	}

	bool shader::is_compiled() const noexcept {
		return is_compiled_;
	}
}
