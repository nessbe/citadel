// File:       opengl_vertex_buffer.hpp
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

#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/drivers/opengl.hpp"

#include "citadel/rendering/vertices/vertex.hpp"
#include "citadel/rendering/vertices/vertex_buffer.hpp"

CITADEL_IGNORE_WARNING_PUSH()
CITADEL_IGNORE_WARNING(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported opengl_vertex_buffer : public vertex_buffer {
	public:
		using id = GLuint;

	public:
		opengl_vertex_buffer(std::size_t size);
		opengl_vertex_buffer(const std::vector<vertex>& vertices);
		opengl_vertex_buffer(const void* data, std::size_t size);

		virtual ~opengl_vertex_buffer() override;

		opengl_vertex_buffer(const opengl_vertex_buffer&) = delete;
		opengl_vertex_buffer& operator=(const opengl_vertex_buffer&) = delete;

		opengl_vertex_buffer(opengl_vertex_buffer&& other) noexcept;
		opengl_vertex_buffer& operator=(opengl_vertex_buffer&& other) noexcept;

		nodisc id get_id() const noexcept;

	private:
		id id_ = 0;

	private:
		virtual void _bind() override;
		virtual void _unbind() override;

		virtual void _set_data(const void* data, std::size_t size) override;
	};
}

CITADEL_IGNORE_WARNING_POP()
