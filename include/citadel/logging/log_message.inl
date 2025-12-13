// File:       log_message.inl
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

namespace citadel {
	template <typename... Arguments>
	log_message<Arguments...>::log_message(const std::string& literal, log_level level, Arguments&&... arguments)
		: literal(literal), level(level), arguments(std::forward<Arguments>(arguments)...) { }
}
