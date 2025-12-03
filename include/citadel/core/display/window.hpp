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

#include <chrono>
#include <cinttypes>
#include <functional>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/core/display/surface.hpp"

#include "citadel/core/layers/layer_stack.hpp"

#include "citadel/memory/scope.hpp"

#include "citadel/rendering/rendering_api_type.hpp"
#include "citadel/rendering/rendering_context.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported window {
	public:
		using dimension = std::uint32_t;

		using clock = std::chrono::high_resolution_clock;

	public:
		nodisc static scope<window> create(rendering_api_type rendering_api, dimension x, dimension y, dimension width, dimension height, const std::string& title);
		nodisc static scope<window> create(rendering_api_type rendering_api, dimension width, dimension height, const std::string& title);

		nodisc static scope<window> create(dimension x, dimension y, dimension width, dimension height, const std::string& title);
		nodisc static scope<window> create(dimension width, dimension height, const std::string& title);

		window(rendering_api_type rendering_api, dimension x, dimension y, dimension width, dimension height, const std::string& title);
		window(rendering_api_type rendering_api, dimension width, dimension height, const std::string& title);

		virtual ~window() = default;

		window(const window&) = delete;
		window& operator=(const window&) = delete;

		void show();
		void hide();

		void maximize();
		void minimize();

		bool update();
		void render();

		void begin_frame();
		void end_frame();

		nodisc void* get_native_handle() const;

		nodisc const std::string& get_title() const noexcept;
		void set_title(const std::string& value);

		nodisc layer_stack& get_layer_stack();
		nodisc surface& get_surface() const;
		nodisc rendering_context& get_rendering_context() const;

		nodisc dimension get_x() const noexcept;
		void set_x(dimension value);

		nodisc dimension get_y() const noexcept;
		void set_y(dimension value);

		nodisc dimension get_width() const noexcept;
		void set_width(dimension value);

		nodisc dimension get_height() const noexcept;
		void set_height(dimension value);

		nodisc bool is_vsync() const noexcept;
		void set_vsync(bool value);

		nodisc bool should_close() const noexcept;
		nodisc bool is_visible() const noexcept;

	protected:
		dimension x_, y_, width_, height_;		

	private:
		std::string title_;

		layer_stack layer_stack_;
		scope<surface> surface_;
		scope<rendering_context> rendering_context_;

		clock::time_point last_frame_;

		bool is_vsync_ = false;

		bool should_close_ = false;
		bool is_visible_ = false;

	private:
		void initialize(rendering_api_type rendering_api);

		virtual void _show() = 0;
		virtual void _hide() = 0;

		virtual void _maximize() = 0;
		virtual void _minimize() = 0;

		virtual bool _update(double delta) = 0;
		virtual void _render() = 0;

		virtual void _begin_frame() = 0;
		virtual void _end_frame() = 0;

		virtual void* _get_native_handle() const = 0;

		virtual void _set_title(const std::string& value) = 0;

		virtual void _set_x(dimension value) = 0;
		virtual void _set_y(dimension value) = 0;
		virtual void _set_width(dimension value) = 0;
		virtual void _set_height(dimension value) = 0;

		virtual void _set_vsync(bool value) = 0;
	};
}

CITADEL_WARNING_IGNORE_POP
