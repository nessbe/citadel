// File:       opengl_texture_2d.hpp
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
#include "citadel/warnings.hpp"

#include "citadel/drivers/opengl.hpp"

#include "citadel/rendering/textures/texture_2d.hpp"

CITADEL_IGNORE_WARNING_PUSH();
CITADEL_IGNORE_WARNING(CITADEL_WARNING_PADDING);

namespace citadel {
	class exported opengl_texture_2d : public texture_2d {
	public:
		using id = GLuint;

	public:
		opengl_texture_2d(const image& image);
		virtual ~opengl_texture_2d() override;

		opengl_texture_2d(const opengl_texture_2d&) = delete;
		opengl_texture_2d& operator=(const opengl_texture_2d&) = delete;

		opengl_texture_2d(opengl_texture_2d&& other) noexcept;
		opengl_texture_2d& operator=(opengl_texture_2d&& other) noexcept;

		nodisc id get_id() const noexcept;

	private:
		id id_ = 0;

		GLuint internal_format_, data_format_;

	private:
		virtual void _bind(slot_type slot) override;
	};
}

CITADEL_IGNORE_WARNING_POP();
