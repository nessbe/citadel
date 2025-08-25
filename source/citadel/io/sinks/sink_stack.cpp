// File:        sink_stack.cpp
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

#include "citadelpch.h"
#include "citadel/io/sinks/sink_stack.h"

namespace Citadel
{
	Reference<Sink> SinkStack::back_sink() const
	{
		return sinks_.back();
	}

	void SinkStack::push_sink(Reference<Sink> sink)
	{
		sinks_.push_back(sink);
	}

	Reference<Sink> SinkStack::pop_sink()
	{
		Reference<Sink> back = back_sink();
		sinks_.pop_back();
		return back;
	}

	std::size_t SinkStack::size() const
	{
		return sinks_.size();
	}

	void SinkStack::propagate_implementation(const std::string& value)
	{
		for (std::size_t i = 0; i < sinks_.size(); i++)
		{
			if (write(i, value))
			{
				return;
			}
		}
	}

	bool SinkStack::write(std::size_t index, const std::string& value)
	{
		const Reference<Sink>& sink = sinks_[index];
		return sink->write(value);
	}
}
