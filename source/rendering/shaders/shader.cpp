// File:       shader.cpp
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
#include "citadel/rendering/shaders/shader.hpp"

namespace citadel {
	std::unique_ptr<shader> shader::create(const std::string& name, shader_type type, const std::string& source) {
		return nullptr;
	}

	std::unique_ptr<shader> shader::create(const std::string& name, shader_type type) {
		return create(name, type, "");
	}

	shader::shader(const std::string& name, shader_type type, const std::string& source)
		: name_(name), source_(source), type_(type) { }

	shader::shader(const std::string& name, shader_type type)
		: shader(name, type, "") { }

	shader::~shader() {
		destroy();
	}

	bool shader::compile() {
		bool result = _compile();
		is_compiled_ = result ? result : is_compiled_;
		return result;
	}

	void shader::destroy() {
		_destroy();
	}

	const std::string& shader::get_name() const noexcept {
		return name_;
	}

	const std::string& shader::get_source() const noexcept {
		return source_;
	}

	void shader::set_source(const std::string& value) {
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
