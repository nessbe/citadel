// File:        basic_vec2.h
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

#ifndef CITADEL_BASIC_VEC2_H
#define CITADEL_BASIC_VEC2_H

#include "citadel/attributes.h"

namespace citadel
{
	template<typename T>
	class basic_vec2
	{
	public:
		T x, y;

	public:
		basic_vec2(T x, T y);
		~basic_vec2() = default;
	};
}

#include "citadel/math/vectors/basic_vec2.inl"

#endif
