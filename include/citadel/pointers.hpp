// File:       pointers.hpp
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

#include "citadel/assert.hpp"

#define CITADEL_POINTER_GET(pointer, property, placeholder) pointer ? pointer->property : placeholder
#define CITADEL_POINTER_GET_OR_NULL(pointer, property, placeholder) CITADEL_POINTER_GET(pointer, property, nullptr)

#define CITADEL_POINTER_SET(pointer, property, value) do { if (pointer) { pointer->property = value; } } while (0)

#define CITADEL_POINTER_CALL(pointer, method, ...) do { if (pointer) { pointer->method(__VA_ARGS__); } } while (0)
#define CITADEL_POINTER_CALL_OR_DEFAULT(pointer, method, placeholder, ...) pointer ? pointer->method(__VA_ARGS__) : placeholder
#define CITADEL_POINTER_CALL_OR_FALSE(pointer, method, ...) CITADEL_POINTER_CALL_OR_DEFAULT(pointer, method, false, __VA_ARGS__)

#define CITADEL_POINTER_RETURN_REFERENCE(pointer) CITADEL_SOFT_ASSERT(pointer, "Pointer " #pointer " is null"); return *pointer
