// File:       wgl_loader.hpp
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

#include "citadel/pch.hpp"
#include "citadel/platforms/windows/wgl_loader.hpp"

#if CITADEL_PLATFORM_WINDOWS

namespace citadel {
	void* wgl_loader::get_procedure_address(const char* name) noexcept {
#if CITADEL_PLATFORM_WINDOWS
		void* address = wglGetProcAddress(name);

		if (address) {
			return address;
		}

		static HMODULE opengl32_module = LoadLibraryA("opengl32");
		return GetProcAddress(opengl32_module, name);
#endif
	}

	int wgl_loader::_load() {
		WNDCLASS dummy_window_class = { };
		dummy_window_class.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		dummy_window_class.lpfnWndProc = DefWindowProc;
		dummy_window_class.hInstance = GetModuleHandle(NULL);
		dummy_window_class.lpszClassName = L"DummyCitadelWindow";

		CITADEL_ASSERT(
			RegisterClass(&dummy_window_class),
			"Failed to register dummy window class"
		);

		HWND dummy_window = CreateWindowEx(
			0,
			dummy_window_class.lpszClassName,
			L"DummyWindow",
			0,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			NULL,
			NULL,
			dummy_window_class.hInstance,
			NULL
		);

		CITADEL_ASSERT(dummy_window, "Failed to open dummy window");

		HDC dummy_device_context = GetDC(dummy_window);

		PIXELFORMATDESCRIPTOR pixel_format_descriptor = { };
		pixel_format_descriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pixel_format_descriptor.nVersion = 1;
		pixel_format_descriptor.iPixelType = PFD_TYPE_RGBA;
		pixel_format_descriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pixel_format_descriptor.cColorBits = 32;
		pixel_format_descriptor.cDepthBits = 24;
		pixel_format_descriptor.cStencilBits = 8;

		int pixel_format = ChoosePixelFormat(dummy_device_context, &pixel_format_descriptor);
		CITADEL_ASSERT(pixel_format != 0, "Failed to choose dummy window pixel format");

		CITADEL_ASSERT(
			SetPixelFormat(dummy_device_context, pixel_format, &pixel_format_descriptor),
			"Failed to set dummy window pixel format"
		);

		HGLRC dummy_rendering_context = wglCreateContext(dummy_device_context);
		CITADEL_ASSERT(dummy_rendering_context, "Failed to create dummy rendering context");

		CITADEL_ASSERT(
			wglMakeCurrent(dummy_device_context, dummy_rendering_context),
			"Failed to make dummy rendering context current for dummy window"
		);

		int status = gladLoadWGLLoader((GLADloadproc)get_procedure_address, dummy_device_context);

		wglMakeCurrent(dummy_device_context, NULL);
		wglDeleteContext(dummy_rendering_context);

		ReleaseDC(dummy_window, dummy_device_context);
		DestroyWindow(dummy_window);

		UnregisterClass(dummy_window_class.lpszClassName, dummy_window_class.hInstance);

		return status;
	}

	void wgl_loader::_unload() {
		gladUnloadWGL();
	}

	int wgl_loader::_get_version_major() const {
		return 1;
	}

	int wgl_loader::_get_version_minor() const {
		return 0;
	}
}

#endif
