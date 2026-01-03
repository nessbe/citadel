// File:       file.hpp
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

#include <cstddef>
#include <iosfwd>
#include <memory>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"
#include "citadel/warnings.hpp"

#include "citadel/io/random_access_stream.hpp"

#include "citadel/io/filesystem/file_open_mode.hpp"

#include "citadel/memory/reference.hpp"

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_PADDING)

namespace citadel {
	class exported file : public random_access_stream {
	public:
		nodisc static reference<file> create(const std::string& path, file_open_mode open_mode);

		file(const std::string& path, file_open_mode open_mode);
		virtual ~file() override = default;

		file(const file&) = delete;
		file& operator=(const file&) = delete;

		nodisc void* native_handle() const;

		nodisc const std::string& path() const noexcept;
		nodisc file_open_mode open_mode() const noexcept;

	private:
		std::string path_;
		file_open_mode open_mode_;

	private:
		nodisc virtual void* _native_handle() const = 0;
	};
}

CITADEL_WARNING_IGNORE_POP
