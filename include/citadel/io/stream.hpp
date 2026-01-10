// File:       stream.hpp
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

#include <cstdio>
#include <iosfwd>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/stream_direction.hpp"

#include "citadel/memory/reference.hpp"
#include "citadel/memory/scope.hpp"

namespace citadel {
	class CITADEL_API stream {
	public:
		using size_type = std::streamsize;
		using position_type = std::streampos;
		using offset_type = std::streamoff;

	public:
		static const size_type eof_value;

	public:
		stream() = default;
		virtual ~stream() = default;

		stream(const stream&) = delete;
		stream& operator=(const stream&) = delete;

		size_type read(void* buffer, size_type size);
		size_type write(const void* buffer, size_type size);

		void flush();

		CITADEL_NODISCARD bool good() const;
		CITADEL_NODISCARD bool eof() const;

	private:
		virtual size_type _read(void* buffer, size_type size) = 0;
		virtual size_type _write(const void* buffer, size_type size) = 0;

		virtual void _flush() = 0;

		CITADEL_NODISCARD virtual bool _good() const = 0;
		CITADEL_NODISCARD virtual bool _eof() const = 0;
	};

	using stream_reference = reference<stream>;
	using stream_scope = scope<stream>;
}
