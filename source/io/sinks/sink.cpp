// File:       sink.hpp
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

#include "citadel/pch.hpp"
#include "citadel/io/sinks/sink.hpp"

namespace citadel {
	sink::sink(const stream_reference& stream)
		: stream_(stream)
	{
		CITADEL_SOFT_ASSERT(stream_, "The given stream is null");
	}

	sink::~sink() {
		flush();
	}

	stream::size_type sink::write(const void* data, stream::size_type size) {
		return CITADEL_POINTER_CALL_OR_ZERO(stream_, write, data, size);
	}

	void sink::flush() {
		CITADEL_POINTER_CALL(stream_, flush);
	}
}
