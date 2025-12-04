// File:       opengl_shader.hpp
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

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported opengl_shader : public shader {
	public:
		using id = GLuint;

	public:
		opengl_shader(const std::string& name, shader_type type, const std::string& source);
		opengl_shader(const std::string& name, shader_type type);

		virtual ~opengl_shader() override;

		opengl_shader(const opengl_shader&) = delete;
		opengl_shader& operator=(const opengl_shader&) = delete;

		opengl_shader(opengl_shader&& other) noexcept;
		opengl_shader& operator=(opengl_shader&& other) noexcept;

		nodisc id get_id() const noexcept;
		nodisc GLenum get_opengl_type() const noexcept;

	private:
		id id_ = 0;

	private:
		virtual bool _compile() override;

		virtual void _set_source(const std::string& value) override;
	};
}

CITADEL_WARNING_IGNORE_POP
