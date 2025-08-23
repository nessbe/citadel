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

#include "citadel/core/application_arguments.h"
#include "citadel/core/exit_code.h"

namespace Citadel
{
	class Application
	{
	public:
		Application() = default;
		virtual ~Application() { }

		virtual void initialize() = 0;
		virtual ExitCode run(ApplicationArguments arguments) = 0;
		virtual void shutdown() = 0;

		CITADEL_API CITADEL_GETTER bool is_running() const noexcept;
		CITADEL_API CITADEL_SETTER void start() noexcept;
		CITADEL_API CITADEL_SETTER void stop() noexcept;

	private:
		bool is_running_ = false;
	};

	Application* create_application();
}

#endif
