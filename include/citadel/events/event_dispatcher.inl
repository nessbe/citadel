// File:       event_dispatcher.inl
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
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

namespace citadel {
	template <typename T>
	requires std::is_base_of_v<event, T>
	bool event_dispatcher<T>::dispatch_event(T& event) {
		if (event.is_consumed()) {
			return true;
		}

		for (const callback& callback : callbacks_) {
			if (callback(event)) {
				event.consume();
				return true;
			}
		}

		return false;
	}

	template <typename T>
	requires std::is_base_of_v<event, T>
	void event_dispatcher<T>::push_callback(const callback& callback) {
		callbacks_.push_back(callback);
	}

	template <typename T>
	requires std::is_base_of_v<event, T>
	void event_dispatcher<T>::push_callback(callback&& callback) {
		callbacks_.push_back(std::move(callback));
	}

	template <typename T>
	requires std::is_base_of_v<event, T>
	typename event_dispatcher<T>::callback event_dispatcher<T>::pop_callback() {
		callback top = callbacks_.back();
		callbacks_.pop_back();
		return top;
	}
}
