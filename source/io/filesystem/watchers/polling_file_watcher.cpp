// File:       polling_file_watcher.cpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#include "citadel/pch.hpp"
#include "citadel/io/filesystem/watchers/polling_file_watcher.hpp"

namespace citadel {
	void polling_file_watcher::_watch(const std::filesystem::path& path) {
		files_[path] = std::filesystem::exists(path)
			? std::filesystem::last_write_time(path)
			: std::filesystem::file_time_type::min();
	}

	void polling_file_watcher::_unwatch(const std::filesystem::path& path) {
		files_.erase(path);
	}

	void polling_file_watcher::_update() {
		for (auto& [path, last_time] : files_) {
			bool exists = std::filesystem::exists(path);

			if (!exists && last_time != std::filesystem::file_time_type::min()) {
				events_.push_back({ path, file_action::deleted });
				last_time = std::filesystem::file_time_type::min();
				continue;
			}

			if (exists) {
				std::filesystem::file_time_type current_time = std::filesystem::last_write_time(path);

				if (last_time == std::filesystem::file_time_type::min()) {
					events_.push_back({ path, file_action::created });
				}
				else if (current_time != last_time) {
					events_.push_back({ path, file_action::modified });
				}

				last_time = current_time;
			}
		}
	}
}
