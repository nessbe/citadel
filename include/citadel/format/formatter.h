// File:        formatter.h
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

#ifndef CITADEL_FORMATTER_H
#define CITADEL_FORMATTER_H

#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

#include "citadel/attributes.h"
#include "citadel/export.h"

namespace Citadel
{
	class Formatter
	{
	public:
		explicit Formatter(const std::string& format)
			: format_(format) { }
		~Formatter() = default;

		CITADEL_API CITADEL_INLINE std::string format() const;

		template<typename... VarArgs>
		std::string format(VarArgs&&... arguments) const
		{
			std::vector<std::string> string_arguments = { to_string(std::forward<VarArgs>(arguments))... };
			return format_implementation(string_arguments);
		}

	private:
		template<typename T>
		static std::string to_string(T&& value)
		{
			std::ostringstream oss;
			oss << value;
			return oss.str();
		}

		CITADEL_API std::string format_implementation(const std::vector<std::string>& arguments) const;

		std::string format_;
	};
}

#endif
