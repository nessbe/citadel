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

namespace citadel {
	file::file(const std::string& path)
		: path_(path) { }

	std::size_t file::read(void* buffer, std::size_t size) {
		return _read(buffer, size);
	}

	std::size_t file::write(const void* buffer, std::size_t size) {
		return _write(buffer, size);
	}

	std::size_t file::tell() {
		return _tell();
	}

	std::size_t file::size() {
		return _size();
	}

	void file::seek(std::size_t position) {
		_seek(position);
	}

	void* file::get_native_handle() const {
		return _get_native_handle();
	}

	const std::string& file::get_path() const noexcept {
		return path_;
	}
}
