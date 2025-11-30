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
#include <iosfwd>
#include <memory>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/io/filesystem/file_open_mode.hpp"

#include "citadel/memory/reference.hpp"

CITADEL_IGNORE_WARNING_PUSH();
CITADEL_IGNORE_WARNING(CITADEL_WARNING_PADDING);

namespace citadel {
	class exported file {
	public:
		nodisc static reference<file> create(const std::string& path, file_open_mode::enumeration open_mode);

		file(const std::string& path, file_open_mode::enumeration open_mode);
		virtual ~file() = default;

		std::streamsize read(void* buffer, std::streamsize size);
		std::streamsize write(const void* buffer, std::streamsize size);

		nodisc std::streampos tell();
		nodisc std::streamoff size();

		nodisc char peek();
		void seek(std::streamoff position);

		nodisc bool is_good() const;

		nodisc bool is_eol();
		nodisc bool is_eof() const;

		nodisc void* get_native_handle() const;

		nodisc const std::string& get_path() const noexcept;
		nodisc file_open_mode::enumeration get_open_mode() const noexcept;

	private:
		std::string path_;
		file_open_mode::enumeration open_mode_;

	private:
		virtual std::streamsize _read(void* buffer, std::streamsize size) = 0;
		virtual std::streamsize _write(const void* buffer, std::streamsize size) = 0;

		nodisc virtual std::streampos _tell() = 0;
		nodisc virtual std::streamoff _size() = 0;

		nodisc virtual char _peek() = 0;
		virtual void _seek(std::streamoff position) = 0;

		nodisc virtual bool _is_good() const = 0;
		nodisc virtual bool _is_eof() const = 0;

		nodisc virtual void* _get_native_handle() const = 0;
	};
}

CITADEL_IGNORE_WARNING_POP();
