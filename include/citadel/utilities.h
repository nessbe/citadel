// File:        utilities.h
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

#ifndef CITADEL_UTILITIES_H
#define CITADEL_UTILITIES_H

#include <vector>

#include "citadel/attributes.h"
#include "citadel/export.h"

#define CITADEL_ITERATOR_WRAPPER(member) \
	auto begin() noexcept { return member.begin(); } \
	auto end() noexcept { return member.end(); } \
	auto begin() const noexcept { return member.begin(); } \
	auto end() const noexcept { return member.end(); } \
	auto cbegin() const noexcept { return member.cbegin(); } \
	auto cend() const noexcept { return member.cend(); } \
	auto rbegin() noexcept { return member.rbegin(); } \
	auto rend() noexcept { return member.rend(); } \
	auto rbegin() const noexcept { return member.rbegin(); } \
	auto rend() const noexcept { return member.rend(); } \
	auto crbegin() const noexcept { return member.crbegin(); } \
	auto crend() const noexcept { return member.crend(); }

#endif
