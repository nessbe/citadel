// File:       file.hpp
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

#include <cstddef>
#include <memory>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/filesystem/file_open_mode.hpp"

namespace citadel {
	class exported file {
	public:
		nodisc static std::unique_ptr<file> create(const std::string& path, file_open_mode::enumeration mode);

		file(const std::string& path, file_open_mode::enumeration mode);
		virtual ~file() = default;

		std::size_t read(void* buffer, std::size_t size);
		std::size_t write(const void* buffer, std::size_t size);

		std::size_t tell();
		std::size_t size();

		void seek(std::size_t position);

		nodisc void* get_native_handle() const;

		nodisc const std::string& get_path() const noexcept;

	private:
		std::string path_;

	private:
		virtual std::size_t _read(void* buffer, std::size_t size) = 0;
		virtual std::size_t _write(const void* buffer, std::size_t size) = 0;

		virtual std::size_t _tell() = 0;
		virtual std::size_t _size() = 0;

		virtual void _seek(std::size_t position) = 0;

		nodisc virtual void* _get_native_handle() const = 0;
	};
}
