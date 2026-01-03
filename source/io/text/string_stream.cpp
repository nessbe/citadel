// File:       string_stream.cpp
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
#include "citadel/io/text/string_stream.hpp"

namespace citadel {
	string_stream::string_stream(const std::string& buffer)
		: buffer_(buffer), position_(0) { }

	std::string& string_stream::data() noexcept {
		return buffer_;
	}

	const std::string& string_stream::data() const noexcept {
		return buffer_;
	}

	char* string_stream::raw() noexcept {
		return buffer_.data();
	}

	const char* string_stream::raw() const noexcept {
		return buffer_.data();
	}

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_SPECTRE)

	bool string_stream::resize_if_out_of_range(position_type position) {
		if (position > size()) {
			buffer_.resize(static_cast<std::size_t>(position));
			return true;
		}
		return false;
	}

	stream::size_type string_stream::_read(void* buffer, size_type size) {
		size_type remaining = static_cast<size_type>(this->size()) - position_;
		size_type to_read = std::min(size, remaining);

		if (to_read > 0) {
			std::memcpy(buffer, buffer_.data() + position_, static_cast<std::size_t>(to_read));
			position_ += to_read;
		}
		return to_read;
	}

CITADEL_WARNING_IGNORE_POP

	stream::size_type string_stream::_write(const void* buffer, size_type size) {
		resize_if_out_of_range(position_ + size);
		std::memcpy(buffer_.data() + position_, buffer, static_cast<std::size_t>(size));
		position_ += size;
		return size;
	}

	stream::position_type string_stream::_tell() {
		return position_;
	}

	stream::offset_type string_stream::_size() {
		return static_cast<offset_type>(buffer_.size());
	}

	int string_stream::_peek() {
		if (eof()) {
			return static_cast<int>(eof_value);
		}
		return static_cast<int>(buffer_[static_cast<std::size_t>(position_)]);
	}

	bool string_stream::_seek(position_type position) {
		resize_if_out_of_range(position);
		position_ = position_;
		return true;
	}

CITADEL_WARNING_IGNORE_PUSH
CITADEL_WARNING_IGNORE(CITADEL_WARNING_SPECTRE)

	bool string_stream::_seek(offset_type offset, stream_direction direction) {
		switch (direction) {
		case stream_direction::begin: {
			bool result = resize_if_out_of_range(offset);
			position_ = offset;
			return result;
		}

		case stream_direction::current: {
			bool result = resize_if_out_of_range(position_ + offset);
			position_ += offset;
			return result;
		}

		case stream_direction::end: {
			position_type new_position = (offset > size()) ? 0 : size() - offset;
			bool result = resize_if_out_of_range(new_position);
			position_ = new_position;
			return result;
		}

		default:
			return false;
		}
	}

CITADEL_WARNING_IGNORE_POP

	void string_stream::_flush() { }

	bool string_stream::_good() const {
		return position_ <= static_cast<size_type>(buffer_.size());
	}

	bool string_stream::_eof() const {
		return position_ >= static_cast<size_type>(buffer_.size());
	}
}
