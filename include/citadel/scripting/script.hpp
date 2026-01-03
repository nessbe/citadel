// File:       script.hpp
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

#include "citadel/io/random_access_stream.hpp"

#include "citadel/memory/reference.hpp"

namespace citadel {
	class exported script {
	public:
		explicit script(const reference<random_access_stream>& stream);
		virtual ~script() = default;

		nodisc bool can_reload() const noexcept;
		void reload();

		nodisc random_access_stream& stream() noexcept;

	private:
		reference<random_access_stream> stream_;

	private:
		nodisc virtual bool _can_reload() const noexcept = 0;
		virtual void _reload() = 0;
	};
}
