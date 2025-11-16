// File:       opengl_vertex_array.hpp
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

#include "citadel/rendering/vertices/vertex_array.hpp"
#include "citadel/rendering/vertices/vertex_buffer.hpp"

CITADEL_IGNORE_WARNING_PUSH
CITADEL_IGNORE_WARNING(CITADEL_WARNING_PADDING)

namespace citadel {
	class api opengl_vertex_array : public vertex_array {
	public:
		using id = GLuint;

	public:
		opengl_vertex_array();
		virtual ~opengl_vertex_array() override;

		opengl_vertex_array(const opengl_vertex_array&) = delete;
		opengl_vertex_array& operator=(const opengl_vertex_array&) = delete;

		opengl_vertex_array(opengl_vertex_array&& other) noexcept;
		opengl_vertex_array& operator=(opengl_vertex_array&& other) noexcept;

		nodisc id get_id() const noexcept;

	private:
		id id_ = 0;

	private:
		virtual void _bind() override;
		virtual void _unbind() override;

		virtual void _add_buffer(const std::unique_ptr<vertex_buffer>& buffer) override;
	};
}

CITADEL_IGNORE_WARNING_POP
