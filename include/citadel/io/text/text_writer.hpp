// File:       text_writer.hpp
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

#include <memory>
#include <string>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/writer.hpp"

#include "citadel/io/filesystem/file.hpp"

namespace citadel {
	class text_writer : public writer {
	public:
		explicit text_writer(const std::shared_ptr<file>& file);

		nodisc void write_c_string(const char* buffer);
		nodisc void write_string(const std::string& string);
	};
}
