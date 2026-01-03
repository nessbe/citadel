// File:       string_stream.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/random_access_stream.hpp"

namespace citadel {
	class exported string_stream : public random_access_stream {
	public:
		explicit string_stream(const std::string& buffer);

		string_stream(const string_stream&) = delete;
		string_stream& operator=(const string_stream&) = delete;

		nodisc std::string& data() noexcept;
		nodisc const std::string& data() const noexcept;

		nodisc char* raw() noexcept;
		nodisc const char* raw() const noexcept;

	private:
		std::string buffer_;
		position_type position_;

	private:
		bool resize_if_out_of_range(position_type position);

		virtual size_type _read(void* buffer, size_type size) override;
		virtual size_type _write(const void* buffer, size_type size) override;

		nodisc virtual position_type _tell() override;
		nodisc virtual offset_type _size() override;

		nodisc virtual int _peek() override;

		virtual bool _seek(position_type position) override;
		virtual bool _seek(offset_type offset, stream_direction direction) override;

		virtual void _flush() override;

		nodisc virtual bool _good() const override;
		nodisc virtual bool _eof() const override;
	};
}

