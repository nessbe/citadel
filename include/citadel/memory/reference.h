// File:        reference.h
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

#ifndef CITADEL_REFERENCE_H
#define CITADEL_REFERENCE_H

#include <memory>
#include <type_traits>

#include "citadel/attributes.h"

namespace Citadel
{
	template<typename T>
	using Reference = std::shared_ptr<T>;

	template<typename T, typename... VarArgs>
	CITADEL_GETTER Reference<T> make_referenced(VarArgs&&... arguments)
	{
		return std::make_shared<T>(std::forward<VarArgs>(arguments)...);
	}
}

#endif
