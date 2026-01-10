// File:       random_access_stream.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/stream.hpp"

namespace citadel {
	class CITADEL_API random_access_stream : public stream {
	public:
		random_access_stream() = default;

		random_access_stream(const random_access_stream&) = delete;
		random_access_stream& operator=(const random_access_stream&) = delete;

		random_access_stream(random_access_stream&&) noexcept = delete;
		random_access_stream& operator=(random_access_stream&&) noexcept = delete;

		CITADEL_NODISCARD position_type tell();
		CITADEL_NODISCARD offset_type size();

		CITADEL_NODISCARD int peek();

		bool seek(position_type position);
		bool seek(offset_type offset, stream_direction direction);

		CITADEL_NODISCARD bool eol();

	private:
		CITADEL_NODISCARD virtual position_type _tell() = 0;
		CITADEL_NODISCARD virtual offset_type _size() = 0;

		CITADEL_NODISCARD virtual int _peek() = 0;

		virtual bool _seek(position_type position) = 0;
		virtual bool _seek(offset_type offset, stream_direction direction) = 0;
	};
}
