// File:       reader.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/stream.hpp"

#include "citadel/memory/reference.hpp"

namespace citadel {
	class exported reader {
	public:
		explicit reader(const reference<stream>& stream);
		virtual ~reader() = default;

		nodisc stream& stream() const noexcept;

	private:
		reference<class stream> stream_;
	};
}
