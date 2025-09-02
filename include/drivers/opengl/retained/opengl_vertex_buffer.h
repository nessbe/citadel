// File:        opengl_vertex_buffer.h
// Project:     citadel
// Repository:  https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// For more details, see the LICENSE file at the root of the project.

#pragma once

#ifndef CITADEL_OPENGL_VERTEX_BUFFER_H
#define CITADEL_OPENGL_VERTEX_BUFFER_H

#include <cstddef>

#include "citadel/export.h"
#include "citadel/platforms.h"

#include "citadel/memory/buffer.h"

#include "citadel/rendering/retained/vertex_buffer.h"

#include "drivers/opengl/opengl.h"

namespace citadel
{
	class opengl_vertex_buffer : public vertex_buffer
	{
	public:
		CITADEL_API opengl_vertex_buffer(std::size_t size);
		CITADEL_API opengl_vertex_buffer(buffer_t&& data);

		CITADEL_API virtual ~opengl_vertex_buffer() override;

	private:
		GLuint id_;

	private:
		CITADEL_API virtual void _bind() override;
		CITADEL_API virtual void _unbind() override;

		CITADEL_API virtual void _set_data(const buffer_t& data) override;
	};
}

#endif
