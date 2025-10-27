// File:       window.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#include <cinttypes>
#include <memory>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

namespace citadel {
	class api window {
	public:
		using dimension = std::uint32_t;

	public:
		static std::unique_ptr<window> create(dimension x, dimension y, dimension width, dimension height, const std::string& title);
		static std::unique_ptr<window> create(dimension width, dimension height, const std::string& title);

		window(dimension x, dimension y, dimension width, dimension height, const std::string& title);
		window(dimension width, dimension height, const std::string& title);

		virtual ~window() = default;

		void open();
		void close();

		void show();
		void hide();

		void maximize();
		void minimize();

		bool update();

		nodisc bool is_open() const noexcept;
		nodisc bool is_visible() const noexcept;

		nodisc void* get_native_handle() const;

		nodisc dimension get_x() const noexcept;
		void set_x(dimension value);

		nodisc dimension get_y() const noexcept;
		void set_y(dimension value);

		nodisc dimension get_width() const noexcept;
		void set_width(dimension value);

		nodisc dimension get_height() const noexcept;
		void set_height(dimension value);

		nodisc const std::string& get_title() const noexcept;
		void set_title(const std::string& value);

	private:
		bool is_open_ = false;
		bool is_visible_ = false;

		dimension x_, y_, width_, height_;
		std::string title_;

	private:
		virtual void _open() = 0;
		virtual void _close() = 0;

		virtual void _show() = 0;
		virtual void _hide() = 0;

		virtual void _maximize() = 0;
		virtual void _minimize() = 0;

		virtual bool _update() = 0;

		virtual void* _get_native_handle() const = 0;

		virtual void _set_x(dimension value) = 0;
		virtual void _set_y(dimension value) = 0;
		virtual void _set_width(dimension value) = 0;
		virtual void _set_height(dimension value) = 0;
		virtual void _set_title(const std::string& value) = 0;
	};
}
