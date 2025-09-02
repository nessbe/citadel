// File:        vertex_buffer_element.h
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

// This file is highly inspired by this file in the Hazel GitHub repository by TheCherno:
//     - https://github.com/TheCherno/Hazel/blob/master/Hazel/src/Hazel/Renderer/Buffer.h

#pragma once

#ifndef CITADEL_VERTEX_BUFFER_ELEMENT_H
#define CITADEL_VERTEX_BUFFER_ELEMENT_H

namespace citadel
{
	class vertex_buffer_layout;
}

#include <cstddef>
#include <string>

#include "citadel/attributes.h"
#include "citadel/export.h"

#include "drivers/opengl/opengl.h"

namespace citadel
{
	class vertex_buffer_element
	{
	public:
		friend class vertex_buffer_layout;

	public:
		using element_type_t = int;
		enum class element_type : element_type_t
		{
			boolean = 0,
			int1 =    1,
			int2 =    2,
			int3 =    3,
			int4 =    4,
			float1 =  5,
			float2 =  6,
			float3 =  7,
			float4 =  8,
			mat3 =    9,
			mat4 =    10,
		};

	public:
		vertex_buffer_element(const std::string& name, element_type type, bool is_normalized)
			: name_(name), type_(type), is_normalized_(is_normalized), offset_(0) { }

		~vertex_buffer_element() = default;

		CITADEL_API CITADEL_GETTER const std::string& get_name() const noexcept;
		CITADEL_API CITADEL_GETTER bool is_normalized() const noexcept;
		CITADEL_API CITADEL_GETTER std::size_t get_offset() const noexcept;

		CITADEL_API CITADEL_GETTER element_type get_type() const noexcept;
		CITADEL_API CITADEL_GETTER GLenum get_opengl_type() const noexcept;

		CITADEL_API CITADEL_GETTER std::size_t size() const noexcept;
		CITADEL_API CITADEL_GETTER std::size_t component_count() const noexcept;

	private:
		std::string name_;
		element_type type_;
		bool is_normalized_;
		std::size_t offset_;

	private:
		CITADEL_API static std::size_t get_size(element_type type);
		CITADEL_API static std::size_t get_component_count(element_type type);

		CITADEL_API static GLenum to_opengl_type(element_type type);
	};
}

#endif
