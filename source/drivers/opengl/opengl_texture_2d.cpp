// File:       opengl_texture_2d.cpp
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
#include "citadel/drivers/opengl/opengl_texture_2d.hpp"

namespace citadel {
	opengl_texture_2d::opengl_texture_2d(const image& image)
		: texture_2d(image)
	{
		image::dimension_type width = image.get_width();
		image::dimension_type height = image.get_height();
		std::size_t channel_count = image.get_channel_count();

		if (channel_count == 4) {
			internal_format_ = GL_RGBA8;
			data_format_ = GL_RGBA;
		}
		else if (channel_count == 3) {
			internal_format_ = GL_RGB8;
			data_format_ = GL_RGB;
		}

		CITADEL_ASSERT(internal_format_ != 0, "2D texture internal format not supported (channel count: {0})", channel_count);
		CITADEL_ASSERT(data_format_ != 0, "2D texture data format not supported (channel count: {0})", channel_count);

		glCreateTextures(GL_TEXTURE_2D, 1, &id_);
		glTextureStorage2D(id_, 1, internal_format_, static_cast<GLsizei>(width), static_cast<GLsizei>(height));

		glTextureParameteri(id_, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(id_, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTextureParameteri(id_, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(id_, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTextureSubImage2D(id_, 0, 0, 0, static_cast<GLsizei>(width), static_cast<GLsizei>(height), data_format_, GL_UNSIGNED_BYTE, image.raw());
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	}

	opengl_texture_2d::~opengl_texture_2d() {
		glDeleteTextures(1, &id_);
	}

	opengl_texture_2d::opengl_texture_2d(opengl_texture_2d&& other) noexcept
		: opengl_texture_2d(other.get_image())
	{
		id_ = other.id_;
		other.id_ = 0;
	}

	opengl_texture_2d& opengl_texture_2d::operator=(opengl_texture_2d&& other) noexcept {
		if (this != &other) {
			glDeleteTextures(1, &id_);

			id_ = other.id_;
			other.id_ = 0;
		}

		return *this;
	}

	opengl_texture_2d::id_type opengl_texture_2d::get_id() const noexcept {
		return id_;
	}

	void opengl_texture_2d::_bind(slot_type slot) {
		glBindTextureUnit(slot, id_);
	}
}
