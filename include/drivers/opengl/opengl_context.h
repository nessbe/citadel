// File:        opengl_context.h
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

#ifndef CITADEL_OPENGL_CONTEXT_H
#define CITADEL_OPENGL_CONTEXT_H

#include "citadel/export.h"
#include "citadel/platforms.h"

#include "citadel/rendering/rendering_context.h"

#include "platforms/windows/windows_window.h"

#if CITADEL_PLATFORM_WINDOWS
	#include <Windows.h>
	#include <gl/GL.h>
#endif

namespace citadel
{
	class opengl_context : public rendering_context
	{
	public:
		opengl_context() = default;
		virtual ~opengl_context() override = default;

	private:
#if CITADEL_PLATFORM_WINDOWS
		HWND window_handle_ = nullptr;
		HDC device_context_handle_ = nullptr;
		HGLRC gl_rendering_context_handle_ = nullptr;
#endif

	private:
		CITADEL_API virtual void _initialize(window* window) override;
		CITADEL_API virtual void _destroy() override;
		CITADEL_API virtual void _swap_buffers() override;

		CITADEL_API void initialize_windows(windows_window* window);
		CITADEL_API void destroy_windows();
		CITADEL_API void swap_buffers_windows() const;
	};
}

#endif
