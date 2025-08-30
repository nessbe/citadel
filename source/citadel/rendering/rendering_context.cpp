// File:        rendering_context.cpp
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
#include "citadel/rendering/rendering_context.h"

#include "citadel/core/window.h"

namespace citadel
{
	void rendering_context::initialize(window* window)
	{
		viewport_ = &window->get_viewport();
		_initialize(window);
	}

	void rendering_context::begin_frame()
	{
		is_frame_in_progress_ = true;
		_begin_frame();
	}

	void rendering_context::end_frame()
	{
		_end_frame();
		swap_buffers();

		is_frame_in_progress_ = false;
	}

	bool rendering_context::is_frame_in_progess() const noexcept
	{
		return is_frame_in_progress_;
	}

	viewport& rendering_context::get_viewport() const
	{
		return *viewport_;
	}

	void rendering_context::swap_buffers()
	{
		_swap_buffers();
	}
}
