// File:       basic_application.hpp
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

#include <citadel/citadel.hpp>

namespace basic_application {
	class basic_application : public citadel::application {
	public:
		basic_application() = default;

		basic_application(const basic_application&) = delete;
		basic_application& operator=(const basic_application&) = delete;

		basic_application(basic_application&& other) noexcept;
		basic_application& operator=(basic_application&& other) noexcept;

	private:
		citadel::scope<citadel::window> window_ = nullptr;

	private:
		virtual void _initialize() override;
		virtual citadel::exit_code _run() override;
		virtual void _shutdown() override;
	};
}
