// File:        application.h
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

#ifndef CITADEL_APPLICATION_H
#define CITADEL_APPLICATION_H

#include "citadel/attributes.h"
#include "citadel/export.h"

#include "citadel/cli/command_line.h"

#include "citadel/core/main_loop.h"
#include "citadel/core/platform_window.h"
#include "citadel/core/window.h"

#include "citadel/memory/scope.h"

int main(int argc, char** argv);

namespace citadel
{
	class application
	{
	public:
		friend int ::main(int argc, char** argv);

	public:
		application() = default;
		virtual ~application() = default;

		CITADEL_API CITADEL_GETTER static application& get();

		CITADEL_API void start();
		CITADEL_API void stop();

		CITADEL_API CITADEL_GETTER bool is_running() const noexcept;
		CITADEL_API CITADEL_GETTER window& get_window();

	protected:
		CITADEL_API void begin_step();
		CITADEL_API void update();
		CITADEL_API void end_step();

	private:
		inline static application* instance;

		main_loop main_loop_;
		scope<window> window_ = nullptr;

	private:
		CITADEL_API void initialize();
		CITADEL_API CITADEL_NODISCARD int run(const command_line& arguments);
		CITADEL_API void shutdown();

		virtual void _initialize() = 0;
		CITADEL_NODISCARD virtual int _run(const command_line& arguments) = 0;
		virtual void _shutdown() = 0;
	};

	application* create_application();
}

#endif
