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

#include "drivers/opengl/opengl.h"
#include "drivers/opengl/opengl_types.h"

typedef void (APIENTRY* PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays); // void glGenVertexArrays(GLsizei n, GLuint* arrays)
extern PFNGLGENVERTEXARRAYSPROC glGenVertexArraysProc;
#define glGenVertexArrays(n, ...) glGenVertexArraysProc(n, __VA_ARGS__)

typedef void (APIENTRY* PFNGLBINDVERTEXARRAYPROC)(GLuint array); // void glBindVertexArray(GLuint array)
extern PFNGLBINDVERTEXARRAYPROC glBindVertexArrayProc;
#define glBindVertexArray(array) glBindVertexArrayProc(array)

typedef void (APIENTRY* PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint* arrays); // void glDeleteVertexArrays(GLsizei n, const GLuint* arrays)
extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArraysProc;
#define glDeleteVertexArrays(n, ...) glDeleteVertexArraysProc(n, __VA_ARGS__)

typedef void (APIENTRY* PFNGLGENBUFFERSPROC)(GLsizei n, GLuint* buffers); // void glGenBuffers(GLsizei n, GLuint* buffers)
extern PFNGLGENBUFFERSPROC glGenBuffersProc;
#define glGenBuffers(n, ...) glGenBuffersProc(n, __VA_ARGS__)

typedef void (APIENTRY* PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer); // void glBindBuffer(GLenum target, GLuint buffer)
extern PFNGLBINDBUFFERPROC glBindBufferProc;
#define glBindBuffer(target, buffer) glBindBufferProc(target, buffer)

typedef void (APIENTRY* PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void* data, GLenum usage); // void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage)
extern PFNGLBUFFERDATAPROC glBufferDataProc;
#define glBufferData(target, size, data, usage) glBufferDataProc(target, size, data, usage)

typedef void (APIENTRY* PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void* data); // void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data)
extern PFNGLBUFFERSUBDATAPROC glBufferSubDataProc;
#define glBufferSubData(target, offset, size, data) glBufferSubDataProc(target, offset, size, data)

typedef void (APIENTRY* PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint* buffers); // void glDeleteBuffers(GLsizei n, const GLuint* buffers)
extern PFNGLDELETEBUFFERSPROC glDeleteBuffersProc;
#define glDeleteBuffers(n, ...) glDeleteBuffersProc(n, __VA_ARGS__)

typedef void (APIENTRY* PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index); // void glEnableVertexAttribArray(GLuint index)
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArrayProc;
#define glEnableVertexAttribArray(index) glEnableVertexAttribArrayProc(index)

typedef void (APIENTRY* PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index); // void glDisableVertexAttribArray(GLuint index)
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArrayProc;
#define glDisableVertexAttribArray(index) glDisableVertexAttribArrayProc(index)

typedef void (APIENTRY* PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index); // void glEnableVertexArrayAttrib(GLuint vaobj, GLuint index)
extern PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttribProc;
#define glEnableVertexArrayAttrib(vaobj, index) glEnableVertexArrayAttribProc(vaobj, index)

typedef void (APIENTRY* PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index); // void glDisableVertexArrayAttrib(GLuint vaobj, GLuint index)
extern PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttribProc;
#define glDisableVertexArrayAttrib(vaobj, index) glDisableVertexArrayAttribProc(vaobj, index)

typedef void (APIENTRY* PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer); // void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)
extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointerProc;
#define glVertexAttribPointer(index, size, type, normalized, stride, pointer) glVertexAttribPointerProc(index, size, type, normalized, stride, pointer)

typedef void (APIENTRY* PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer); // void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer)
extern PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointerProc;
#define glVertexAttribIPointer(index, size, type, stride, pointer) glVertexAttribIPointerProc(index, size, type, stride, pointer)

typedef void (APIENTRY* PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer); // void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer)
extern PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointerProc;
#define glVertexAttribLPointer(index, size, type, stride, pointer) glVertexAttribLPointerProc(index, size, type, stride, pointer)

typedef void (APIENTRY* PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor); // void glVertexAttribDivisor(GLuint index, GLuint divisor)
extern PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisorProc;
#define glVertexAttribDivisor(index, divisor) glVertexAttribDivisorProc(index, divisor)

namespace citadel
{
	CITADEL_API void load_opengl_functions();
}

#define CITADEL_LOAD_OPENGL_FUNCTION(type, pointer, function) \
	pointer = (type)wglGetProcAddress(#function); \
	CITADEL_ASSERT(pointer, "Failed to load OpenGL function '" #function "'")

#endif
