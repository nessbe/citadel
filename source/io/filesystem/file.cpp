// File:       file.cpp
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
#include "citadel/io/filesystem/file.hpp"

#include "citadel/platforms/stl/stl_file.hpp"

namespace citadel {
	reference<file> file::create(const std::string& path, file_open_mode::enumeration open_mode) {
		return make_referenced<stl_file>(path, open_mode);
	}

	file::file(const std::string& path, file_open_mode::enumeration open_mode)
		: path_(path), open_mode_(open_mode){ }

	void* file::get_native_handle() const {
		return _get_native_handle();
	}

	const std::string& file::get_path() const noexcept {
		return path_;
	}

	file_open_mode::enumeration file::get_open_mode() const noexcept {
		return open_mode_;
	}
}
