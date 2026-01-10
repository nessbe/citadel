// File:       sink.cpp
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
#include "citadel/io/sinks/sink.hpp"

namespace citadel {
	sink::sink(const reference<random_access_stream>& stream)
		: stream_(stream)
	{
		CITADEL_PRECONDITION(stream != nullptr, "Stream must not be null");
	}

	sink::~sink() {
		flush();
	}

	stream::size_type sink::write(const void* data, stream::size_type size) {
		return stream_->write(data, size);
	}

	void sink::flush() {
		stream_->flush();
	}

	random_access_stream& sink::stream() const noexcept {
		return *stream_;
	}

	sink_reference make_sink(const reference<random_access_stream>& stream) {
		return make_referenced<sink>(stream);
	}
}
