// File:        opengl_loader.h
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

#ifndef CITADEL_OPENGL_LOADER_H
#define CITADEL_OPENGL_LOADER_H

#include "citadel/assert.h"
#include "citadel/export.h"
#include "citadel/platforms.h"

#if CITADEL_PLATFORM_WINDOWS
	#include <Windows.h>
	#include <gl/GL.h>
#endif

typedef void (APIENTRY* PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays); // void glGenVertexArrays(GLsizei n, GLuint* arrays)
typedef void (APIENTRY* PFNGLBINDVERTEXARRAYPROC)(GLuint array); // void glBindVertexArray(GLuint array)
typedef void (APIENTRY* PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint* arrays); // void glDeleteVertexArrays(GLsizei n, const GLuint* arrays)

extern PFNGLGENVERTEXARRAYSPROC glGenVertexArraysProc;
extern PFNGLBINDVERTEXARRAYPROC glBindVertexArrayProc;
extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArraysProc;

#define glGenVertexArrays(n, ...) glGenVertexArraysProc(n, ##__VA_ARGS__)
#define glBindVertexArray(array) glBindVertexArrayProc(array)
#define glDeleteVertexArrays(n, ...) glDeleteVertexArraysProc(n, ##__VA_ARGS__)

namespace citadel
{
	CITADEL_API inline void load_opengl_functions();
}

#define CITADEL_LOAD_OPENGL_FUNCTION(type, pointer, function) \
	pointer = (type)wglGetProcAddress(#function); \
	CITADEL_ASSERT(pointer, "Failed to load OpenGL function '" #function "'")

#endif
