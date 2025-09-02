// File:        vertex_buffer_element.cpp
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
#include "citadel/rendering/retained/vertex_buffer_element.h"

#include "citadel/rendering/retained/vertex_buffer_layout.h"

namespace citadel
{
	const std::string& vertex_buffer_element::get_name() const noexcept
	{
		return name_;
	}

	bool vertex_buffer_element::is_normalized() const noexcept
	{
		return is_normalized_;
	}

	std::size_t vertex_buffer_element::get_offset() const noexcept
	{
		return offset_;
	}

	vertex_buffer_element::element_type vertex_buffer_element::get_type() const noexcept
	{
		return type_;
	}

	GLenum vertex_buffer_element::get_opengl_type() const noexcept
	{
		return to_opengl_type(type_);
	}

	std::size_t vertex_buffer_element::size() const noexcept
	{
		return get_size(type_);
	}

	std::size_t vertex_buffer_element::component_count() const noexcept
	{
		return get_component_count(type_);
	}

	std::size_t vertex_buffer_element::get_size(element_type type)
	{
		switch (type)
		{
		case element_type::boolean:
			return sizeof(bool);

		case element_type::int1:
			return sizeof(int);

		case element_type::int2:
			return sizeof(int) * 2;

		case element_type::int3:
			return sizeof(int) * 3;

		case element_type::int4:
			return sizeof(int) * 4;

		case element_type::float1:
			return sizeof(float);

		case element_type::float2:
			return sizeof(float) * 2;

		case element_type::float3:
			return sizeof(float) * 3;

		case element_type::float4:
			return sizeof(float) * 4;

		case element_type::mat3:
			return sizeof(float) * 3 * 3;

		case element_type::mat4:
			return sizeof(float) * 4 * 4;

		default:
			CITADEL_ASSERT(false, "Unknown element_type");
			return 0;
		}
	}

	std::size_t vertex_buffer_element::get_component_count(element_type type)
	{
		switch (type)
		{
		case element_type::boolean:
			return 1;

		case element_type::int1:
			return 1;

		case element_type::int2:
			return 2;

		case element_type::int3:
			return 3;

		case element_type::int4:
			return 4;

		case element_type::float1:
			return 1;

		case element_type::float2:
			return 2;

		case element_type::float3:
			return 3;

		case element_type::float4:
			return 4;

		case element_type::mat3:
			return 3;

		case element_type::mat4:
			return 4;

		default:
			CITADEL_ASSERT(false, "Unknown element_type");
			return 0;
		}
	}

	GLenum vertex_buffer_element::to_opengl_type(element_type type)
	{
		switch (type)
		{
		case element_type::boolean:
			return GL_UNSIGNED_BYTE;

		case element_type::int1:
			return GL_INT;

		case element_type::int2:
			return GL_INT;

		case element_type::int3:
			return GL_INT;

		case element_type::int4:
			return GL_INT;

		case element_type::mat3:
			return GL_FLOAT;

		case element_type::mat4:
			return GL_FLOAT;

		case element_type::float1:
			return GL_FLOAT;

		case element_type::float2:
			return GL_FLOAT;

		case element_type::float3:
			return GL_FLOAT;

		case element_type::float4:
			return GL_FLOAT;

		default:
			CITADEL_ASSERT(false, "Unknown element_type");
			return 0;
		}
	}
}
