// File:        opengl_vertex_buffer.cpp
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

#include "citadelpch.h"
#include "drivers/opengl/retained/opengl_vertex_buffer.h"

namespace citadel
{
	opengl_vertex_buffer::opengl_vertex_buffer(std::size_t size)
		: vertex_buffer(size)
	{
		glGenBuffers(1, &id_);
		bind();
		glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
	}

	opengl_vertex_buffer::opengl_vertex_buffer(buffer_t&& data)
		: vertex_buffer(std::move(data))
	{
		glGenBuffers(1, &id_);
		bind();
		glBufferData(GL_ARRAY_BUFFER, size(), raw_data(), GL_STATIC_DRAW);
	}

	opengl_vertex_buffer::~opengl_vertex_buffer()
	{
		glDeleteBuffers(1, &id_);
	}

	void opengl_vertex_buffer::_bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, id_);
	}

	void opengl_vertex_buffer::_unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void opengl_vertex_buffer::_set_data(const buffer_t& data)
	{
		bind();
		glBufferSubData(GL_ARRAY_BUFFER, 0, data.size(), data.raw_data());
	}
}
