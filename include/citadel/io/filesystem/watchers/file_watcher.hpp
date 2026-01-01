// File:       file_watcher.hpp
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

#pragma once

#include <filesystem>
#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include  "citadel/memory/scope.hpp"

#include "citadel/io/filesystem/file_event.hpp"

namespace citadel {
	class exported file_watcher {
	public:
		nodisc static scope<file_watcher> create();

		virtual ~file_watcher() = default;

		void watch(const std::filesystem::path& path);
		void unwatch(const std::filesystem::path& path);

		void update();

		nodisc const std::vector<file_event>& events() const noexcept;

	private:
		virtual void _watch(const std::filesystem::path& path) = 0;
		virtual void _unwatch(const std::filesystem::path& path) = 0;

		virtual void _update() = 0;

	protected:
		std::vector<file_event> events_;
	};
}
