// File:       file_watcher.cpp
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
#include "citadel/io/filesystem/watchers/file_watcher.hpp"

#include "citadel/io/filesystem/watchers/polling_file_watcher.hpp"

namespace citadel {
	scope<file_watcher> file_watcher::create() {
		return make_scoped<polling_file_watcher>();
	}

	void file_watcher::watch(const std::filesystem::path& path) {
		_watch(path);
	}

	void file_watcher::unwatch(const std::filesystem::path& path) {
		_unwatch(path);
	}

	void file_watcher::update() {
		events_.clear();
		_update();
	}

	const std::vector<file_event>& file_watcher::events() const noexcept {
		return events_;
	}
}
