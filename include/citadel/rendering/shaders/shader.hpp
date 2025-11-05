// File:       shader.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/rendering/shaders/shader_type.hpp"

CITADEL_IGNORE_WARNING_PUSH
CITADEL_IGNORE_WARNING(CITADEL_WARNING_PADDING)

namespace citadel {
	class api shader {
	public:
		static std::unique_ptr<shader> create(const std::string& name, shader_type type, const std::string& source);
		static std::unique_ptr<shader> create(const std::string& name, shader_type type);

		shader(const std::string& name, shader_type type, const std::string& source);
		shader(const std::string& name, shader_type type);

		virtual ~shader();

		shader(const shader&) = delete;
		shader& operator=(const shader&) = delete;

		void construct();
		void destroy() noexcept;

		bool compile();

		nodisc const std::string& get_name() const noexcept;

		nodisc const std::string& get_source() const noexcept;
		void set_source(const std::string& value);

		nodisc shader_type get_type() const noexcept;

		nodisc bool is_compiled() const noexcept;

	private:
		std::string name_;
		std::string source_;

		shader_type type_;

		bool is_compiled_ = false;

	private:
		virtual void _construct() = 0;
		virtual void _destroy() noexcept = 0;

		virtual bool _compile() = 0;

		virtual void _set_source(const std::string& value) = 0;
	};
}

CITADEL_IGNORE_WARNING_POP
