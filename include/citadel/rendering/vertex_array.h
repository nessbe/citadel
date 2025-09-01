// File:        vertex_array.h
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

#ifndef CITADEL_VERTEX_ARRAY_H
#define CITADEL_VERTEX_ARRAY_H

#include "citadel/attributes.h"
#include "citadel/export.h"

namespace citadel
{
	class vertex_array
	{
	public:
		vertex_array() = default;
		virtual ~vertex_array() = default;

		CITADEL_API void bind();
		CITADEL_API void unbind();

		CITADEL_API CITADEL_GETTER bool is_bound() const noexcept;

	private:
		bool is_bound_ = false;

	private:
		virtual void _bind() = 0;
		virtual void _unbind() = 0;
	};
}

#endif
