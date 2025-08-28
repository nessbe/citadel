// File:        command_line.cpp
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
#include "citadel/cli/command_line.h"

namespace citadel
{
	command_line::command_line(int argc, char** argv)
		: size_(argc)
	{
		if (argc > 0)
		{
			command_ = argv[0];
		}

		for (int i = 1; i < argc; i++)
		{
			arguments_.emplace_back(argv[0]);
		}
	}

	int command_line::size() const noexcept
	{
		return size_;
	}

	int command_line::get_argument_count() const noexcept
	{
		return std::abs(size_ - 1);
	}

	const std::string& command_line::get_command() const
	{
		return command_;
	}

	bool command_line::has_argument(int index) const noexcept
	{
		return index < size_;
	}

	std::optional<std::string> command_line::get_argument(int index) const
	{
		if (has_argument(index))
		{
			return arguments_[index];
		}
		return std::nullopt;
	}

	std::string command_line::to_string() const
	{
		std::ostringstream out;
		out << command_;

		for (const std::string& argument : arguments_)
		{
			out << ' ' << argument;
		}

		return out.str();
	}

	command_line::operator std::string() const
	{
		return to_string();
	}

	std::ostream& operator<<(std::ostream& out, const command_line& object)
	{
		return out << object.to_string();
	}
}
