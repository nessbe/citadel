// File:       command_line.hpp
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

#pragma once

#include <string>
#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	class command_line {
	public:
		CITADEL_API command_line(int argc, char* argv[]);
		~command_line() = default;

		CITADEL_API CITADEL_GETTER const std::string& get_program_name() const noexcept;

		CITADEL_API CITADEL_GETTER const std::vector<std::string>& get_arguments() const noexcept;
		CITADEL_API CITADEL_GETTER std::size_t get_argument_count() const noexcept;

		CITADEL_API CITADEL_GETTER std::size_t size() const noexcept;

		CITADEL_API CITADEL_GETTER const std::string& operator[](std::size_t index) const noexcept;

	private:
		std::string program_name_;
		std::vector<std::string> arguments_;
	};
}
