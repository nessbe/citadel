// File:       stl_file.hpp
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

#include <fstream>
#include <iosfwd>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/filesystem/file.hpp"
#include "citadel/io/filesystem/file_open_mode.hpp"

namespace citadel {
	class exported stl_file : public file {
	public:
		stl_file(const std::string& path, file_open_mode::enumeration mode);
		virtual ~stl_file() override;

		stl_file(const stl_file&) = delete;
		stl_file& operator=(const stl_file&) = delete;

	private:
		std::fstream stream_;

	private:
		virtual std::streamsize _read(void* buffer, std::streamsize size) override;
		virtual std::streamsize _write(const void* buffer, std::streamsize size) override;

		nodisc virtual std::streampos _tell() override;
		nodisc virtual std::streamoff _size() override;

		nodisc virtual char _peek() override;
		virtual void _seek(std::streamoff position) override;

		nodisc virtual bool _is_good() const override;
		nodisc virtual bool _is_eof() const override;

		nodisc virtual void* _get_native_handle() const override;
	};
}
