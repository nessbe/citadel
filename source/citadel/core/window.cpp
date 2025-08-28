// File:        window.cpp
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
#include "citadel/core/window.h"

namespace citadel
{
	void window::open()
	{
		is_running_ = true;
		_open();
	}

	void window::close()
	{
		is_running_ = false;
		_close();
	}

	void window::show()
	{
		is_visible_ = true;
		_show();
	}

	void window::hide()
	{
		is_visible_ = false;
		_hide();
	}

	bool window::update()
	{
		if (!is_running_)
		{
			return false;
		}

		if (is_visible_)
		{
			return _update();
		}

		return is_running_;
	}

	window::dimension_t window::get_width() const noexcept
	{
		return width_;
	}

	void window::set_width(dimension_t width)
	{
		width_ = width;
		_set_width(width);
	}

	window::dimension_t window::get_height() const noexcept
	{
		return height_;
	}

	void window::set_height(dimension_t height)
	{
		height_ = height;
		_set_height(height);
	}

	const std::string& window::get_title() const
	{
		return title_;
	}

	void window::set_title(const std::string& title)
	{
		title_ = title;
		_set_title(title);
	}

	bool window::is_running() const noexcept
	{
		return is_running_;
	}

	bool window::is_visible() const noexcept
	{
		return is_visible_;
	}

	void* window::get_native_handle() const
	{
		return _get_native_handle();
	}
}
