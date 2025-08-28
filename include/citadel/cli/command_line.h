// File:        command_line.h
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

#ifndef CITADEL_COMMAND_LINE_H
#define CITADEL_COMMAND_LINE_H

#include <optional>
#include <ostream>
#include <string>
#include <vector>

#include "citadel/attributes.h"
#include "citadel/export.h"

namespace citadel
{
	class command_line
	{
	public:
		CITADEL_API command_line(int argc, char** argv);
		~command_line() = default;

		CITADEL_API CITADEL_GETTER int size() const noexcept;
		CITADEL_API CITADEL_GETTER int get_argument_count() const noexcept;

		CITADEL_API CITADEL_GETTER const std::string& get_command() const;

		CITADEL_API CITADEL_GETTER bool has_argument(int index) const noexcept;
		CITADEL_API CITADEL_GETTER std::optional<std::string> get_argument(int index) const;

		CITADEL_API CITADEL_NODISCARD std::string to_string() const;
		CITADEL_API CITADEL_GETTER operator std::string() const;

	private:
		int size_;
		std::string command_;
		std::vector<std::string> arguments_;
	};

	CITADEL_API CITADEL_INLINE std::ostream& operator<<(std::ostream& out, const command_line& object);
}

#endif
