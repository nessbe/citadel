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

namespace citadel
{
	class application
	{
	public:
		application() = default;
		virtual ~application() = default;

		CITADEL_API void start();
		CITADEL_API void stop();

		CITADEL_API void initialize();
		CITADEL_API CITADEL_NODISCARD int run();
		CITADEL_API void shutdown();

		CITADEL_API bool is_running() const noexcept;

	private:
		bool is_running_ = false;

	private:
		virtual void _initialize() = 0;
		CITADEL_NODISCARD virtual int _run() = 0;
		virtual void _shutdown() = 0;
	};
}

#endif
