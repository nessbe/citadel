// File:       command_line.cpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
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

#include "citadel/pch.hpp"
#include "citadel/cli/command_line.hpp"

namespace citadel {
	command_line::command_line(int argc, char* argv[])
		: arguments_(argc) {

		if (argc > 0) {
			program_name_ = argv[0];
		}

		for (int i = 1; i < argc; i++) {
			arguments_[i] = argv[i];
		}
	}

	const std::string& command_line::get_program_name() const noexcept {
		return program_name_;
	}

	const std::vector<std::string>& command_line::get_arguments() const noexcept {
		return arguments_;
	}

	std::size_t command_line::get_argument_count() const noexcept {
		return arguments_.size();
	}

	std::size_t command_line::size() const noexcept {
		return arguments_.size() + 1;
	}

	const std::string& command_line::operator[](std::size_t index) const noexcept {
		CITADEL_ASSERT(index < size(), "Index is out of range");

		if (index == 0) {
			return program_name_;
		} else {
			return arguments_[index - 1];
		};
	}
}
