// File:        logger.h
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

#ifndef CITADEL_LOGGER_H
#define CITADEL_LOGGER_H

#include <ostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

#include "citadel/attributes.h"
#include "citadel/export.h"

#include "citadel/io/sinks/sink.h"
#include "citadel/io/sinks/sink_stack.h"

#include "citadel/logging/log_level.h"
#include "citadel/logging/log_message.h"
#include "citadel/logging/log_settings.h"

#include "citadel/memory/reference.h"

namespace Citadel
{
	class Logger
	{
	public:
		explicit Logger(const std::string& configuration)
			: configuration_(configuration) { }
		~Logger() = default;

		CITADEL_API CITADEL_GETTER const std::string& get_configuration() const noexcept;

		CITADEL_API CITADEL_INLINE Reference<Sink> back_sink() const;

		CITADEL_API CITADEL_INLINE void push_sink(Reference<Sink> sink, const LogSettings& settings);
		CITADEL_API CITADEL_INLINE Reference<Sink> pop_sink();

		template<typename... VarArgs>
		void log(Reference<LogMessage> message, VarArgs&&... arguments)
		{
			write_sinks(message, std::forward<VarArgs>(arguments)...);
		}

		template<typename... VarArgs>
		CITADEL_INLINE void log_debug(const std::string& message, VarArgs&&... arguments)
		{
			log(make_referenced<LogMessage>(message, LogLevel::Debug), std::forward<VarArgs>(arguments)...);
		}

		template<typename... VarArgs>
		CITADEL_INLINE void log_trace(const std::string& message, VarArgs&&... arguments)
		{
			log(make_referenced<LogMessage>(message, LogLevel::Trace), std::forward<VarArgs>(arguments)...);
		}

		template<typename... VarArgs>
		CITADEL_INLINE void log_info(const std::string& message, VarArgs&&... arguments)
		{
			log(make_referenced<LogMessage>(message, LogLevel::Info), std::forward<VarArgs>(arguments)...);
		}

		template<typename... VarArgs>
		CITADEL_INLINE void log_warning(const std::string& message, VarArgs&&... arguments)
		{
			log(make_referenced<LogMessage>(message, LogLevel::Warning), std::forward<VarArgs>(arguments)...);
		}

		template<typename... VarArgs>
		CITADEL_INLINE void log_error(const std::string& message, VarArgs&&... arguments)
		{
			log(make_referenced<LogMessage>(message, LogLevel::Error), std::forward<VarArgs>(arguments)...);
		}

		template<typename... VarArgs>
		CITADEL_INLINE void log_critical(const std::string& message, VarArgs&&... arguments)
		{
			log(make_referenced<LogMessage>(message, LogLevel::Critical), std::forward<VarArgs>(arguments)...);
		}

	private:
		std::string configuration_;

		SinkStack sinks_;
		std::vector<LogSettings> settings_;

	private:
		template<typename... VarArgs>
		void write_sinks(Reference<LogMessage> message, VarArgs&&... arguments)
		{
			for (std::size_t i = 0; i < sinks_.size(); i++)
			{
				if (write_sink(i, message, std::forward<VarArgs>(arguments)...))
				{
					return;
				}
			}
		}

		template<typename... VarArgs>
		bool write_sink(std::size_t index, Reference<LogMessage> message, VarArgs&&... arguments)
		{
			const Reference<Sink>& sink = sinks_[index];
			const LogSettings& settings = settings_[index];

			if (!settings.is_valid(message))
			{
				return false;
			}

			std::string formatted_message = format_message(message, settings, std::forward<VarArgs>(arguments)...);

			return sink->write(formatted_message);
		}

		template<typename... VarArgs>
		std::string format_message(Reference<LogMessage> message, const LogSettings& settings, VarArgs&&... arguments)
		{
			std::ostringstream oss;

			oss << '[' << configuration_ << "]";
			oss << '[' << message->get_level() << "] ";

			std::string literal = message->format(std::forward<VarArgs>(arguments)...);
			oss << literal;

			return oss.str();
		}
	};
}

#endif
