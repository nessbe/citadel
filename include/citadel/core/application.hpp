// File:       application.hpp
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

#include "citadel/export.hpp"

#include "citadel/cli/command_line.hpp"

int main(int argc, char* argv[]);

namespace citadel {
	class application {
	public:
		friend int ::main(int argc, char* argv[]);

	public:
		application() = default;
		virtual ~application() = default;

		static application& get();

	private:
		CITADEL_API static application* instance_;

	private:
		CITADEL_API void initialize();
		CITADEL_API int run(const command_line& arguments);
		CITADEL_API void shutdown();

		virtual void _initialize() = 0;
		virtual int _run(const command_line& arguments) = 0;
		virtual void _shutdown() = 0;
	};

	application* create_application();
}
