// File:       reader.cpp
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

#include "citadel/pch.hpp"
#include "citadel/io/reader.hpp"

namespace citadel {
	reader::reader(const reference<random_access_stream>& stream)
		: stream_(stream)
	{
		CITADEL_PRECONDITION(stream != nullptr, "Stream must not be null");
	}

	random_access_stream& reader::stream() const noexcept {
		return *stream_;
	}
}
