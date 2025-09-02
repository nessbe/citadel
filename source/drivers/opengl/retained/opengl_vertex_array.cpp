// File:        opengl_vertex_array.cpp
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
#include "drivers/opengl/retained/opengl_vertex_array.h"

namespace citadel
{
	opengl_vertex_array::opengl_vertex_array()
	{
		glGenVertexArrays(1, &id_);
	}

	opengl_vertex_array::~opengl_vertex_array()
	{
		glDeleteVertexArrays(1, &id_);
	}

	void opengl_vertex_array::_bind()
	{
		glBindVertexArray(id_);
	}

	void opengl_vertex_array::_unbind()
	{
		glBindVertexArray(0);
	}

	void opengl_vertex_array::_set_index_buffer(const reference<index_buffer>& index_buffer)
	{
	}

	void opengl_vertex_array::_add_vertex_buffer(const reference<vertex_buffer>& vertex_buffer, std::size_t vertex_buffer_index)
	{
		const vertex_buffer_layout& layout = vertex_buffer->get_layout();

		for (const vertex_buffer_element& element : layout)
		{

			switch (element.get_type())
			{
			case vertex_buffer_element::element_type::boolean:
			case vertex_buffer_element::element_type::int1:
			case vertex_buffer_element::element_type::int2:
			case vertex_buffer_element::element_type::int3:
			case vertex_buffer_element::element_type::int4:
				glEnableVertexAttribArray(static_cast<GLuint>(vertex_buffer_index));
				glVertexAttribIPointer(
					static_cast<GLsizei>(vertex_buffer_index),
					static_cast<GLint>(element.component_count()),
					element.get_opengl_type(),
					static_cast<GLsizei>(layout.get_stride()),
					reinterpret_cast<const char*>(element.get_offset())
				);
				break;

			case vertex_buffer_element::element_type::float1:
			case vertex_buffer_element::element_type::float2:
			case vertex_buffer_element::element_type::float3:
			case vertex_buffer_element::element_type::float4:
				glEnableVertexAttribArray(static_cast<GLuint>(vertex_buffer_index));
				glVertexAttribPointer(
					static_cast<GLsizei>(vertex_buffer_index),
					static_cast<GLint>(element.component_count()),
					element.get_opengl_type(),
					element.is_normalized() ? GL_TRUE : GL_FALSE,
					static_cast<GLsizei>(layout.get_stride()),
					reinterpret_cast<const char*>(element.get_offset())
				);
				break;

			case vertex_buffer_element::element_type::mat3:
			case vertex_buffer_element::element_type::mat4:
			{
				std::size_t component_count = element.component_count();

				for (std::size_t i = 0; i < component_count; i++)
				{
					glEnableVertexAttribArray(static_cast<GLuint>(vertex_buffer_index));
					glVertexAttribPointer(
						static_cast<GLsizei>(vertex_buffer_index),
						static_cast<GLint>(component_count),
						element.get_opengl_type(),
						element.is_normalized() ? GL_TRUE : GL_FALSE,
						static_cast<GLsizei>(layout.get_stride()),
						reinterpret_cast<const char*>(element.get_offset())
					);
					glVertexAttribDivisor(static_cast<GLint>(vertex_buffer_index), 1);
				}
			} break;

			default:
				CITADEL_ASSERT(false, "Unknown element_type");
				break;
			}
		}
	}
}
