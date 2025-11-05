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

CITADEL_IGNORE_WARNING_PUSH
CITADEL_IGNORE_WARNING(CITADEL_WARNING_PADDING)

namespace citadel {
	class api shader_program {
	public:
		static std::unique_ptr<shader_program> create(const std::string& name);

		shader_program(const std::string& name);
		virtual ~shader_program();

		shader_program(const shader_program&) = delete;
		shader_program& operator=(const shader_program&) = delete;

		void construct();
		void destroy() noexcept;

		bool link();
		void use();

		bool attach(shader* shader);
		void detach(shader_type type);

		nodisc std::vector<shader*> get_shaders() const;
		nodisc bool has_shader(shader_type type) const;
		nodisc shader* get_shader(shader_type type) const;

		nodisc const std::string& get_name() const noexcept;

	private:
		std::unordered_map<shader_type, shader*> shaders_;
		std::string name_;

	private:
		virtual void _construct() = 0;
		virtual void _destroy() noexcept = 0;

		virtual bool _link() = 0;
		virtual void _use() = 0;

		virtual void _attach(shader* shader) = 0;
		virtual void _detach(shader* shader) = 0;
	};
}

CITADEL_IGNORE_WARNING_POP
