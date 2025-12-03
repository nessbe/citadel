// File:       opengl_index_buffer.hpp
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

#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/drivers/opengl.hpp"

#include "citadel/rendering/vertices/index_buffer.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported opengl_index_buffer : public index_buffer {
	public:
		using id = GLuint;

	public:
		opengl_index_buffer(const std::vector<index>& indices);
		opengl_index_buffer(const index* data, std::size_t size);

		virtual ~opengl_index_buffer() override;

		opengl_index_buffer(const opengl_index_buffer&) = delete;
		opengl_index_buffer& operator=(const opengl_index_buffer&) = delete;

		opengl_index_buffer(opengl_index_buffer&& other) noexcept;
		opengl_index_buffer& operator=(opengl_index_buffer&& other) noexcept;

	private:
		id id_ = 0;

	private:
		virtual void _bind() override;
		virtual void _unbind() override;

		virtual void _set_data(const index* data, std::size_t size) override;
	};
}

CITADEL_WARNING_IGNORE_POP
