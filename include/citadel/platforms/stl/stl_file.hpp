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
		virtual size_type _read(void* buffer, size_type size) override;
		virtual size_type _write(const void* buffer, size_type size) override;

		nodisc virtual position_type _tell() override;
		nodisc virtual offset_type _size() override;

		nodisc virtual int _peek() override;

		virtual bool _seek(position_type position) override;
		virtual bool _seek(offset_type offset, stream_direction_t direction) override;

		virtual void _flush() override;

		nodisc virtual bool _is_good() const override;
		nodisc virtual bool _is_eof() const override;

		nodisc virtual void* _get_native_handle() const override;
	};
}
