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

#include "citadel/rendering/rendering_types.h"

namespace citadel
{
	window::window(dimension_t x, dimension_t y, dimension_t width, dimension_t height, const std::string& title) :
		x_(x),
		y_(y),
		width_(width),
		height_(height),
		title_(title),
		viewport_(make_scoped<viewport>(
			static_cast<viewport::dimension_t>(x),
			static_cast<viewport::dimension_t>(y),
			static_cast<viewport::dimension_t>(width),
			static_cast<viewport::dimension_t>(height)
		)),
		rendering_context_(make_scoped<default_rendering_context>())
	{ }

	void window::open()
	{
		is_running_ = true;

		_open();
		rendering_context_->initialize(this);
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
		rendering_context_->begin_frame();

		rendering_context_->end_frame();

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

	window::dimension_t window::get_x() const noexcept
	{
		return x_;
	}

	void window::set_x(dimension_t x) noexcept
	{
		x_ = x;
		viewport_->set_x(static_cast<viewport::dimension_t>(x));

		_set_x(x);
	}

	window::dimension_t window::get_y() const noexcept
	{
		return y_;
	}

	void window::set_y(dimension_t y) noexcept
	{
		y_ = y;
		viewport_->set_y(static_cast<viewport::dimension_t>(y));

		_set_y(y);
	}

	window::dimension_t window::get_width() const noexcept
	{
		return width_;
	}

	void window::set_width(dimension_t width)
	{
		width_ = width;
		viewport_->set_width(width);

		_set_width(width);
	}

	window::dimension_t window::get_height() const noexcept
	{
		return height_;
	}

	void window::set_height(dimension_t height)
	{
		height_ = height;
		viewport_->set_height(height);

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

	viewport& window::get_viewport()
	{
		return *viewport_;
	}
}
