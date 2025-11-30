// File:       exceptions.hpp
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

#include <iostream>

#ifdef CITADEL_NOTHROW
	#define CITADEL_THROW(exception, message, result) do { std::cerr << message << std::endl; } while(0); return result
	#define CITADEL_THROW_VOID(exception, message) do { std::cerr << message << std::endl; } while(0); return
#else
	#define CITADEL_THROW(exception, message, result) throw exception(message)
	#define CITADEL_THROW_VOID(exception, message) throw exception(message)
#endif

#define CITADEL_THROW_OR_FAIL(exception, message) CITADEL_THROW(exception, message, false)
