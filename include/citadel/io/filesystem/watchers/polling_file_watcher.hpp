// File:       polling_file_watcher.hpp
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
#include <unordered_map>

#include "citadel/export.hpp"

#include "citadel/io/filesystem/watchers/file_watcher.hpp"

namespace citadel {
	class CITADEL_API polling_file_watcher final : public file_watcher {
	private:
		std::unordered_map<std::filesystem::path, std::filesystem::file_time_type> files_;

	private:
		virtual void _watch(const std::filesystem::path& path) override;
		virtual void _unwatch(const std::filesystem::path& path) override;

		virtual void _update() override;
	};
}
