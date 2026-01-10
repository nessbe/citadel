// File:       loggers.cpp
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
#include "citadel/logging/loggers.hpp"

namespace citadel {
	std::unordered_map<std::string, reference<logger>>& loggers::instances() noexcept {
		static std::unordered_map<std::string, reference<logger>> instances;
		return instances;
	}

	std::mutex& loggers::mutex() noexcept {
		static std::mutex mutex;
		return mutex;
	}

	logger& loggers::get(const std::string& name) {
		std::unordered_map<std::string, reference<logger>>& loggers = instances();

		if (loggers.find(name) == loggers.end()) {
			add(name);
		}

		return *loggers[name];
	}

	logger& loggers::add(const std::string& name) {
		std::lock_guard<std::mutex> lock(mutex());
		std::unordered_map<std::string, reference<logger>>& loggers = instances();

		if (loggers.find(name) == loggers.end()) {
			loggers[name] = make_referenced<logger>(name);
		}

		this_logger::set(name);
		return get(name);
	}

	bool loggers::is_level_valid(const std::string& name, log_level level) {
		return get(name).is_level_valid(level);
	}

	bool loggers::is_off(const std::string& name) {
		return get(name).is_off();
	}

	log_level_palette& loggers::palette(const std::string& name) {
		return get(name).palette();
	}

	const std::string& loggers::get_name(const std::string& name) {
		return get(name).get_name();
	}

	const std::vector<sink_reference>& loggers::get_sinks(const std::string& name) {
		return get(name).get_sinks();
	}

	std::size_t loggers::sink_count(const std::string& name) {
		return get(name).sink_count();
	}

	void loggers::push_sink(const std::string& name, const sink_reference& sink) {
		get(name).push_sink(sink);
	}

	void loggers::clear_sinks(const std::string& name) {
		get(name).clear_sinks();
	}

	log_level loggers::get_level(const std::string& name) {
		return get(name).get_level();
	}

	void loggers::set_level(const std::string& name, log_level value) {
		return get(name).set_level(value);
	}
}
