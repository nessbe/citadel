// File:       pipe.hpp
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
	class exported pipe : public stream {
	public:
		virtual ~pipe() = default;

		pipe(const pipe&) = delete;
		pipe& operator=(const pipe&) = delete;

		nodisc bool valid() const noexcept;

	private:
		nodisc virtual bool _valid() const noexcept = 0;
	};
}
