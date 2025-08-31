// File:        application.cpp
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
#include "citadel/core/application.h"

namespace citadel
{
	application& application::get()
	{
		return *instance;
	}

	void application::start()
	{
		is_running_ = true;
	}

	void application::stop()
	{
		is_running_ = false;
	}

	bool application::is_running() const noexcept
	{
		return is_running_;
	}

	window& citadel::application::get_window()
	{
		return *window_;
	}

	bool application::update()
	{
		window_->update();

		if (window_->should_close())
		{
			stop();
		}

		window_->render();

		return is_running_;
	}

	void application::initialize()
	{
		window_ = make_scoped<platform_window>(100, 75, 800, 600, "Application window");
		window_->open();

		_initialize();
		start();
	}

	int application::run(const command_line& arguments)
	{
		return _run(arguments);
	}

	void application::shutdown()
	{
		stop();
		_shutdown();
	}
}
