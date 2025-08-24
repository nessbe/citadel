// File:        formatter.cpp
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
#include "citadel/format/formatter.h"

namespace Citadel
{
	std::string Formatter::format() const
	{
		std::vector<std::string> empty_arguments;
		return format_implementation(empty_arguments);
	}

	std::string Formatter::format_implementation(const std::vector<std::string>& arguments) const
	{
		std::ostringstream oss;
		std::size_t position = 0;

		while (position < format_.size())
		{
			if (format_[position] == '{')
			{
				std::size_t end = format_.find('}', position);

				if (end != std::string::npos)
				{
					std::string index_string = format_.substr(position + 1, end - position - 1);
					std::size_t index = std::stoul(index_string);

					if (index < arguments.size())
					{
						oss << arguments[index];
					}
					else
					{
						oss << '{' << index_string << '}';
					}

					position = end + 1;
					continue;
				}
			}

			oss << format_[position++];
		}

		return oss.str();
	}
}
