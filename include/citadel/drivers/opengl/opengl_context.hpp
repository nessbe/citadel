// File:       opengl_context.hpp
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

#include "citadel/export.hpp"
#include "citadel/platforms.hpp"

#include "citadel/drivers/opengl/opengl_loader.hpp"

#include "citadel/platforms/windows.hpp"
#include "citadel/platforms/windows/windows_window.hpp"

#include "citadel/rendering/rendering_context.hpp"

namespace citadel {
	class api opengl_context : public rendering_context {
	public:
		opengl_context() = default;

	private:
#if CITADEL_PLATFORM_WINDOWS
		HWND window_ = nullptr;
		HDC device_context_ = nullptr;
		HGLRC gl_rendering_context_ = nullptr;
#endif

		opengl_loader opengl_loader_;

	private:
#if CITADEL_PLATFORM_WINDOWS
		void construct_windows(windows_window* window);
#endif

		virtual void _construct(window* window) override;
		virtual void _destroy() override;

		virtual void _bind() override;
		virtual void _unbind() override;

		virtual void _swap_buffers() override;
	};
}
