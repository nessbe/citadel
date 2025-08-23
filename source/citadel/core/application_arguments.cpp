// File:        application_arguments.cpp
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
#include "citadel/core/application_arguments.h"

namespace Citadel
{
	ApplicationArguments::ApplicationArguments(int argument_count, char** arguments)
		: argument_count_(static_cast<std::size_t>(argument_count - 1))
	{
		if (argument_count > 0)
		{
			program_name_ = arguments[0];
		}

		for (int i = 1; i < argument_count; i++)
		{
			arguments_.emplace_back(arguments[i]);
		}
	}

	std::size_t ApplicationArguments::size() const noexcept
	{
		return argument_count_;
	}

	std::string ApplicationArguments::to_string() const
	{
		std::ostringstream oss;
		oss << program_name_;

		for (const std::string& argument : arguments_)
		{
			oss << ' ' << argument;
		}

		return oss.str();
	}

	const std::string& ApplicationArguments::get_program_name() const noexcept
	{
		return program_name_;
	}

	bool ApplicationArguments::has_argument(std::size_t index) const noexcept
	{
		return index < size();
	}

	const std::string& ApplicationArguments::get_argument(std::size_t index) const
	{
		CITADEL_ASSERT(!has_argument(index), "Argument index is out of range");
		return arguments_.at(index);
	}
}
