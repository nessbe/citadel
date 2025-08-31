// File:        main_loop.cpp
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
#include "citadel/core/main_loop.h"

namespace citadel
{
	void main_loop::start()
	{
		is_running_ = true;
	}

	void main_loop::stop()
	{
		is_running_ = false;
	}

	void main_loop::begin_step()
	{
		is_step_in_progress_ = true;
	}

	void main_loop::end_step()
	{
		is_step_in_progress_ = false;
	}

	bool main_loop::is_running() const noexcept
	{
		return is_running_;
	}

	bool main_loop::is_step_in_progress() const noexcept
	{
		return is_step_in_progress_;
	}
}
