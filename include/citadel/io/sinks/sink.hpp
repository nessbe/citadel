// File:       sink.hpp
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

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/random_access_stream.hpp"

#include "citadel/memory/reference.hpp"

namespace citadel {
	class exported sink {
	public:
		sink(const reference<random_access_stream>& stream);
		~sink();

		stream::size_type write(const void* data, stream::size_type size);
		void flush();

		nodisc random_access_stream& stream() const noexcept;

	private:
		reference<random_access_stream> stream_;
	};

	using sink_reference = reference<sink>;

	nodisc exported sink_reference make_sink(const reference<random_access_stream>& stream);
}
