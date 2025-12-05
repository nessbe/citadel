// File:       stream.hpp
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

#include <iosfwd>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/stream_direction.hpp"

#include "citadel/memory/reference.hpp"
#include "citadel/memory/scope.hpp"

namespace citadel {
	class exported stream {
	public:
		using size_type = std::streamsize;
		using position_type = std::streampos;
		using offset_type = std::streamoff;

	public:
		virtual ~stream() = default;

		size_type read(void* buffer, size_type size);
		size_type write(const void* buffer, size_type size);

		nodisc position_type tell();
		nodisc offset_type size();

		nodisc int peek();

		bool seek(position_type position);
		bool seek(offset_type offset, stream_direction direction);

		void flush();

		nodisc bool is_good() const;

		nodisc bool is_eol();
		nodisc bool is_eof() const;

	private:
		virtual size_type _read(void* buffer, size_type size) = 0;
		virtual size_type _write(const void* buffer, size_type size) = 0;

		nodisc virtual position_type _tell() = 0;
		nodisc virtual offset_type _size() = 0;

		nodisc virtual int _peek() = 0;

		virtual bool _seek(position_type position) = 0;
		virtual bool _seek(offset_type offset, stream_direction direction) = 0;

		virtual void _flush() = 0;

		nodisc virtual bool _is_good() const = 0;
		nodisc virtual bool _is_eof() const = 0;
	};

	using stream_reference = reference<stream>;
	using stream_scope = scope<stream>;
}
