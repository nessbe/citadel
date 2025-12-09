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

#pragma once

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/io/stream.hpp"

#include "citadel/memory/reference.hpp"
#include "citadel/memory/scope.hpp"

namespace citadel {
	class exported sink {
	public:
		sink(const stream_reference& stream);
		~sink();

		stream::size_type write(const void* data, stream::size_type size);
		void flush();

		nodisc stream& stream() const noexcept;

	private:
		stream_reference stream_;
	};

	using sink_reference = reference<sink>;
	using sink_scope = scope<sink>;
}
