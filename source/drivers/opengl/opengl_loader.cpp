// File:        opengl_loader.cpp
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
#include "drivers/opengl/opengl_loader.h"

PFNGLGENVERTEXARRAYSPROC glGenVertexArraysProc = nullptr;
PFNGLBINDVERTEXARRAYPROC glBindVertexArrayProc = nullptr;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArraysProc = nullptr;
PFNGLGENBUFFERSPROC glGenBuffersProc = nullptr;
PFNGLBINDBUFFERPROC glBindBufferProc = nullptr;
PFNGLBUFFERDATAPROC glBufferDataProc = nullptr;
PFNGLBUFFERSUBDATAPROC glBufferSubDataProc = nullptr;
PFNGLDELETEBUFFERSPROC glDeleteBuffersProc = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArrayProc = nullptr;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArrayProc = nullptr;
PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttribProc = nullptr;
PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttribProc = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointerProc = nullptr;
PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointerProc = nullptr;
PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointerProc = nullptr;
PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisorProc = nullptr;

namespace citadel
{
	void load_opengl_functions()
	{
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLGENVERTEXARRAYSPROC, glGenVertexArraysProc, glGenVertexArrays);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLBINDVERTEXARRAYPROC, glBindVertexArrayProc, glBindVertexArray);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArraysProc, glDeleteVertexArrays);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLGENBUFFERSPROC, glGenBuffersProc, glGenBuffers);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLBINDBUFFERPROC, glBindBufferProc, glBindBuffer);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLBUFFERDATAPROC, glBufferDataProc, glBufferData);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLBUFFERSUBDATAPROC, glBufferSubDataProc, glBufferSubData);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLDELETEBUFFERSPROC, glDeleteBuffersProc, glDeleteBuffers);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArrayProc, glEnableVertexAttribArray);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArrayProc, glDisableVertexAttribArray);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLENABLEVERTEXARRAYATTRIBPROC, glEnableVertexArrayAttribProc, glEnableVertexArrayAttrib);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLDISABLEVERTEXARRAYATTRIBPROC, glDisableVertexArrayAttribProc, glDisableVertexArrayAttrib);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointerProc, glVertexAttribPointer);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLVERTEXATTRIBIPOINTERPROC, glVertexAttribIPointerProc, glVertexAttribIPointer);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLVERTEXATTRIBLPOINTERPROC, glVertexAttribLPointerProc, glVertexAttribLPointer);
		CITADEL_LOAD_OPENGL_FUNCTION(PFNGLVERTEXATTRIBDIVISORPROC, glVertexAttribDivisorProc, glVertexAttribDivisor);
	}
}
