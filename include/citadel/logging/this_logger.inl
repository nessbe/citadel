// File:        this_logger.inl
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

namespace citadel::this_logger
{
	logger& get() noexcept
	{
		return citadel::detail::this_logger;
	}

	bool is_level_valid(log_level level) noexcept
	{
		return get().is_level_valid(level);
	}

	void log(const std::string& message, log_level level)
	{
		get().log(message, level);
	}

	const std::string& get_name() noexcept
	{
		return get().get_name();
	}

	log_level get_min_level() noexcept
	{
		return get().get_min_level();
	}

	void set_min_level(log_level value) noexcept
	{
		get().set_min_level(value);
	}
}
