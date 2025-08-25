// File:        utils.h
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

#ifndef CITADEL_UTILS_H
#define CITADEL_UTILS_H

#include "citadel/attributes.h"
#include "citadel/export.h"

#define CITADEL_ITERATOR_WRAPPER(type, member) \
	CITADEL_API CITADEL_GETTER std::vector<type>::iterator begin() noexcept { return member.begin(); } \
	CITADEL_API CITADEL_GETTER std::vector<type>::iterator end() noexcept { return member.end(); } \
	CITADEL_API CITADEL_GETTER std::vector<type>::const_iterator cbegin() const noexcept { return member.cbegin(); } \
	CITADEL_API CITADEL_GETTER std::vector<type>::const_iterator cend() const noexcept { return member.cend(); } \
	CITADEL_API CITADEL_GETTER std::vector<type>::reverse_iterator rbegin() noexcept { return member.rbegin(); } \
	CITADEL_API CITADEL_GETTER std::vector<type>::reverse_iterator rend() noexcept { return member.rend(); } \
	CITADEL_API CITADEL_GETTER std::vector<type>::const_reverse_iterator crbegin() const noexcept { return member.crbegin(); } \
	CITADEL_API CITADEL_GETTER std::vector<type>::const_reverse_iterator crend() const noexcept { return member.crend(); }

#endif
