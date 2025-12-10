// File:       this_logger.inl
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

namespace citadel {
	std::mutex& this_logger::mutex() {
		static std::mutex mutex;
		return mutex;
	}

	std::unordered_map<std::string, reference<logger>>& this_logger::instances() {
		static std::unordered_map<std::string, reference<logger>> instances;
		return instances;
	}

	logger& this_logger::initialize(const std::string& name) {
		std::lock_guard<std::mutex> lock(mutex());
		std::unordered_map<std::string, reference<logger>>& loggers = instances();

		if (loggers.find(name) == loggers.end()) {
			loggers[name] = make_referenced<logger>(name);
		}

		current = loggers[name];
		CITADEL_POINTER_RETURN_REFERENCE(current);
 	}

	logger& this_logger::get() {
		CITADEL_POINTER_RETURN_REFERENCE(current);
	}

	bool this_logger::set(const std::string& name) {
		std::lock_guard<std::mutex> lock(mutex());

		std::unordered_map<std::string, reference<logger>>& loggers = instances();
		std::unordered_map<std::string, reference<logger>>::iterator logger = loggers.find(name);

		if (logger != loggers.end()) {
			current = logger->second;
			return true;
		}

		return false;
	}

	void this_logger::log(const std::string& name, log_level level) {
		get().log(name, level);
	}

	void this_logger::log_debug(const std::string& message) {
		get().log_debug(message);
	}

	void this_logger::log_trace(const std::string& message) {
		get().log_trace(message);
	}

	void this_logger::log_info(const std::string& message) {
		get().log_info(message);
	}

	void this_logger::log_warning(const std::string& message) {
		get().log_warning(message);
	}

	void this_logger::log_error(const std::string& message) {
		get().log_error(message);
	}

	void this_logger::log_fatal(const std::string& message) {
		get().log_fatal(message);
	}

	bool this_logger::is_level_valid(log_level level) noexcept {
		return get().is_level_valid(level);
	}

	bool this_logger::is_off() noexcept {
		return get().is_off();
	}

	const std::string& this_logger::get_name() noexcept {
		return get().get_name();
	}

	const std::vector<sink_reference>& this_logger::get_sinks() noexcept {
		return get().get_sinks();
	}

	std::size_t this_logger::sink_count() noexcept {
		return get().sink_count();
	}

	void this_logger::push_sink(const sink_reference& sink) {
		get().push_sink(sink);
	}

	void this_logger::clear_sinks() {
		get().clear_sinks();
	}

	log_level this_logger::get_level() noexcept {
		return get().get_level();
	}

	void this_logger::set_level(log_level value) noexcept {
		return get().set_level(value);
	}
}
