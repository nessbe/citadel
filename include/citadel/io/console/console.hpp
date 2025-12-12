// File:       console.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/stream.hpp"
#include "citadel/io/stream_direction.hpp"

#include "citadel/memory/reference.hpp"

namespace citadel {
	class exported console : public stream {
	public:
		nodisc static console& get() noexcept;
		nodisc static const reference<console>& pointer() noexcept;

		console() = default;

		console(const console&) = delete;
		console& operator=(const console&) = delete;

		console(console&&) = delete;
		console& operator=(console&&) = delete;

	private:
		static reference<console> instance_;

	private:
		virtual size_type _read(void* buffer, size_type size) override;
		virtual size_type _write(const void* buffer, size_type size) override;

		nodisc virtual position_type _tell() override;
		nodisc virtual offset_type _size() override;

		nodisc virtual int _peek() override;

		virtual bool _seek(position_type position) override;
		virtual bool _seek(offset_type offset, stream_direction direction) override;

		virtual void _flush() override;

		nodisc virtual bool _is_good() const override;
		nodisc virtual bool _is_eof() const override;
	};
}
