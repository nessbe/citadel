// File:       uniform_info.cpp
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
#include "citadel/rendering/shaders/uniform_info.hpp"

namespace citadel {
	uniform_info::uniform_info(const std::string& name, shader_data_type::enumeration type, std::size_t size, std::uint32_t location)
		: name(name), size(size), type(type), location(location) { }
}
