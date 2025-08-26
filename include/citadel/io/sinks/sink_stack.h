// File:        sink_stack.h
// Project:     citadel
// Repository:  https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// For more details, see the LICENSE file at the root of the project.

#pragma once

#ifndef CITADEL_SINK_STACK_H
#define CITADEL_SINK_STACK_H

#include <initializer_list>
#include <sstream>
#include <string>
#include <vector>

#include "citadel/attributes.h"
#include "citadel/exceptions.h"
#include "citadel/export.h"
#include "citadel/utils.h"

#include "citadel/io/sinks/sink.h"

#include "citadel/format/stringifier.h"

#include "citadel/memory/reference.h"

namespace Citadel
{
	class SinkStack
	{
	public:
		SinkStack() = default;
		SinkStack(std::initializer_list<Reference<Sink>> sinks)
			: sinks_(sinks) { }
		~SinkStack() = default;

		CITADEL_API CITADEL_INLINE Reference<Sink> back_sink() const;

		CITADEL_API CITADEL_INLINE void push_sink(Reference<Sink> sink);
		CITADEL_API CITADEL_INLINE Reference<Sink> pop_sink();

		CITADEL_API std::size_t size() const;

		template<typename T>
		void propagate(T&& value)
		{
			propagate_implementation(Stringifier::to_string(std::forward<T>(value)));
		}

		CITADEL_API CITADEL_INLINE Reference<Sink>& operator[](const std::size_t index);

		CITADEL_ITERATOR_WRAPPER(Reference<Sink>, sinks_);

	private:
		std::vector<Reference<Sink>> sinks_;

		CITADEL_API void propagate_implementation(const std::string& value);
		CITADEL_API CITADEL_INLINE bool write(std::size_t index, const std::string& value);
	};
}

#endif
