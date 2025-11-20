// File:       utility.hpp
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

#include <vector>

#include "citadel/attributes.hpp"

#define CITADEL_VECTOR_ITERATOR_WRAPPER(type, property)                                                     \
	::std::vector<type>::iterator begin() noexcept { return property.begin(); }                         \
	::std::vector<type>::iterator end() noexcept { return property.end(); }                             \
	::std::vector<type>::reverse_iterator rbegin() noexcept { return property.rbegin(); }               \
	::std::vector<type>::reverse_iterator rend() noexcept { return property.rend(); }                   \
	::std::vector<type>::const_iterator cbegin() const noexcept { return property.cbegin(); }           \
	::std::vector<type>::const_iterator cend() const noexcept { return property.cend(); }               \
	::std::vector<type>::const_reverse_iterator crbegin() const noexcept { return property.crbegin(); } \
	::std::vector<type>::const_reverse_iterator crend() const noexcept { return property.crend(); }
