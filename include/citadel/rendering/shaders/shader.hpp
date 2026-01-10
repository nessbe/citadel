// File:       shader.hpp
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

#pragma once

#include <memory>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/math/matrices/mat3.hpp"
#include "citadel/math/matrices/mat4.hpp"

#include "citadel/math/vectors/vec2.hpp"
#include "citadel/math/vectors/vec3.hpp"
#include "citadel/math/vectors/vec4.hpp"

#include "citadel/memory/reference.hpp"

#include "citadel/rendering/rendering_api_type.hpp"

#include "citadel/rendering/shaders/shader_data_type.hpp"
#include "citadel/rendering/shaders/shader_type.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class CITADEL_API shader {
	public:
		CITADEL_NODISCARD static reference<shader> create(rendering_api_type api, const std::string& name, shader_type type, const std::string& source);
		CITADEL_NODISCARD static reference<shader> create(rendering_api_type api, const std::string& name, shader_type type);

		CITADEL_NODISCARD static reference<shader> create(const std::string& name, shader_type type, const std::string& source);
		CITADEL_NODISCARD static reference<shader> create(const std::string& name, shader_type type);

		shader(const std::string& name, shader_type type, const std::string& source);
		shader(const std::string& name, shader_type type);

		virtual ~shader() = default;

		shader(const shader&) = delete;
		shader& operator=(const shader&) = delete;

		bool compile();

		CITADEL_NODISCARD const std::string& get_name() const noexcept;

		CITADEL_NODISCARD const std::string& get_source() const noexcept;
		void set_source(const std::string& value);

		CITADEL_NODISCARD shader_type get_type() const noexcept;

		CITADEL_NODISCARD bool is_compiled() const noexcept;

	private:
		std::string name_;
		std::string source_;

		shader_type type_;

		bool is_compiled_ = false;

	private:
		virtual bool _compile() = 0;

		virtual void _set_source(const std::string& value) = 0;
	};
}

CITADEL_WARNING_IGNORE_POP
