// File:       key_code.cpp
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

#include "citadel/pch.hpp"
#include "citadel/input/key_code.hpp"

#include <unordered_map>
#include <string>

namespace citadel {
	const std::unordered_map<key_code, std::string> key_names = {
		{ key_code::none,                 "None" },

		// ASCII
		{ key_code::space,                "Space" },
		{ key_code::exclamation_mark,     "!" },
		{ key_code::quote,                "\"" },
		{ key_code::hash,                 "#" },
		{ key_code::dollar_sign,          "$" },
		{ key_code::percent,              "%" },
		{ key_code::ampersand,            "&" },
		{ key_code::apostrophe,           "'" },
		{ key_code::open_parenthesis,     "(" },
		{ key_code::close_parenthesis,    ")" },
		{ key_code::asterisk,             "*" },
		{ key_code::plus,                 "+" },
		{ key_code::comma,                "," },
		{ key_code::minus,                "-" },
		{ key_code::period,               "." },
		{ key_code::slash,                "/" },
		{ key_code::zero,                 "0" },
		{ key_code::one,                  "1" },
		{ key_code::two,                  "2" },
		{ key_code::three,                "3" },
		{ key_code::four,                 "4" },
		{ key_code::five,                 "5" },
		{ key_code::six,                  "6" },
		{ key_code::seven,                "7" },
		{ key_code::eight,                "8" },
		{ key_code::nine,                 "9" },
		{ key_code::colon,                ":" },
		{ key_code::semicolon,            ";" },
		{ key_code::less_than,            "<" },
		{ key_code::equal,                "=" },
		{ key_code::greater_than,         ">" },
		{ key_code::question_mark,        "?" },
		{ key_code::at,                   "@" },
		{ key_code::A,                    "A" },
		{ key_code::B,                    "B" },
		{ key_code::C,                    "C" },
		{ key_code::D,                    "D" },
		{ key_code::E,                    "E" },
		{ key_code::F,                    "F" },
		{ key_code::G,                    "G" },
		{ key_code::H,                    "H" },
		{ key_code::I,                    "I" },
		{ key_code::J,                    "J" },
		{ key_code::K,                    "K" },
		{ key_code::L,                    "L" },
		{ key_code::M,                    "M" },
		{ key_code::N,                    "N" },
		{ key_code::O,                    "O" },
		{ key_code::P,                    "P" },
		{ key_code::Q,                    "Q" },
		{ key_code::R,                    "R" },
		{ key_code::S,                    "S" },
		{ key_code::T,                    "T" },
		{ key_code::U,                    "U" },
		{ key_code::V,                    "V" },
		{ key_code::W,                    "W" },
		{ key_code::X,                    "X" },
		{ key_code::Y,                    "Y" },
		{ key_code::Z,                    "Z" },
		{ key_code::open_bracket,         "[" },
		{ key_code::backslash,            "\\" },
		{ key_code::close_bracket,        "]" },
		{ key_code::caret,                "^" },
		{ key_code::underscore,           "_" },
		{ key_code::backtick,             "`" },
		{ key_code::a,                    "a" },
		{ key_code::b,                    "b" },
		{ key_code::c,                    "c" },
		{ key_code::d,                    "d" },
		{ key_code::e,                    "e" },
		{ key_code::f,                    "f" },
		{ key_code::g,                    "g" },
		{ key_code::h,                    "h" },
		{ key_code::i,                    "i" },
		{ key_code::j,                    "j" },
		{ key_code::k,                    "k" },
		{ key_code::l,                    "l" },
		{ key_code::m,                    "m" },
		{ key_code::n,                    "n" },
		{ key_code::o,                    "o" },
		{ key_code::p,                    "p" },
		{ key_code::q,                    "q" },
		{ key_code::r,                    "r" },
		{ key_code::s,                    "s" },
		{ key_code::t,                    "t" },
		{ key_code::u,                    "u" },
		{ key_code::v,                    "v" },
		{ key_code::w,                    "w" },
		{ key_code::x,                    "x" },
		{ key_code::y,                    "y" },
		{ key_code::z,                    "z" },
		{ key_code::open_brace,           "{" },
		{ key_code::pipe,                 "|" },
		{ key_code::close_brace,          "}" },
		{ key_code::tilde,                "~" },
		{ key_code::del,                  "Del" },

		// Control
		{ key_code::escape,               "Escape" },
		{ key_code::enter,                "Enter" },
		{ key_code::tab,                  "Tab" },
		{ key_code::backspace,            "Backspace" },
		{ key_code::left_shift,           "Left Shift" },
		{ key_code::right_shift,          "Right Shift" },
		{ key_code::left_control,         "Left Control" },
		{ key_code::right_control,        "Right Control" },
		{ key_code::left_alt,             "Left Alt" },
		{ key_code::right_alt,            "Right Alt" },
		{ key_code::caps_lock,            "Caps Lock" },
		{ key_code::left_super,           "Left Super" },
		{ key_code::right_super,          "Right Super" },
		{ key_code::menu,                 "Menu" },

		// Navigation
		{ key_code::arrow_up,             "Arrow Up" },
		{ key_code::arrow_down,           "Arrow Down" },
		{ key_code::arrow_left,           "Arrow Left" },
		{ key_code::arrow_right,          "Arrow Right" },
		{ key_code::home,                 "Home" },
		{ key_code::end,                  "End" },
		{ key_code::page_up,              "Page Up" },
		{ key_code::page_down,            "Page Down" },
		{ key_code::insert,               "Insert" },
		{ key_code::delete_key,           "Delete" },

		// Numeric Pad
		{ key_code::num_lock,             "Num Lock" },
		{ key_code::numpad_0,             "Numpad 0" },
		{ key_code::numpad_1,             "Numpad 1" },
		{ key_code::numpad_2,             "Numpad 2" },
		{ key_code::numpad_3,             "Numpad 3" },
		{ key_code::numpad_4,             "Numpad 4" },
		{ key_code::numpad_5,             "Numpad 5" },
		{ key_code::numpad_6,             "Numpad 6" },
		{ key_code::numpad_7,             "Numpad 7" },
		{ key_code::numpad_8,             "Numpad 8" },
		{ key_code::numpad_9,             "Numpad 9" },
		{ key_code::numpad_add,           "Numpad +" },
		{ key_code::numpad_subtract,      "Numpad -" },
		{ key_code::numpad_multiply,      "Numpad *" },
		{ key_code::numpad_divide,        "Numpad /" },
		{ key_code::numpad_enter,         "Numpad Enter" },
		{ key_code::numpad_period,        "Numpad ." },

		// Functions
		{ key_code::f1,                   "F1" },
		{ key_code::f2,                   "F2" },
		{ key_code::f3,                   "F3" },
		{ key_code::f4,                   "F4" },
		{ key_code::f5,                   "F5" },
		{ key_code::f6,                   "F6" },
		{ key_code::f7,                   "F7" },
		{ key_code::f8,                   "F8" },
		{ key_code::f9,                   "F9" },
		{ key_code::f10,                  "F10" },
		{ key_code::f11,                  "F11" },
		{ key_code::f12,                  "F12" },
		{ key_code::f13,                  "F13" },
		{ key_code::f14,                  "F14" },
		{ key_code::f15,                  "F15" },
		{ key_code::f16,                  "F16" },
		{ key_code::f17,                  "F17" },
		{ key_code::f18,                  "F18" },
		{ key_code::f19,                  "F19" },
		{ key_code::f20,                  "F20" },
		{ key_code::f21,                  "F21" },
		{ key_code::f22,                  "F22" },
		{ key_code::f23,                  "F23" },
		{ key_code::f24,                  "F24" },

		// Multimedia / System
		{ key_code::print_screen,         "Print Screen" },
		{ key_code::pause,                "Pause" },
		{ key_code::scroll_lock,          "Scroll Lock" },
		{ key_code::volume_up,            "Volume Up" },
		{ key_code::volume_down,          "Volume Down" },
		{ key_code::volume_mute,          "Volume Mute" },
		{ key_code::media_play,           "Media Play" },
		{ key_code::media_stop,           "Media Stop" },
		{ key_code::media_next,           "Media Next" },
		{ key_code::media_previous,       "Media Previous" },
	};

	std::string get_key_name(key_code code) noexcept {
		if (key_names.find(code) != key_names.end()) {
			return key_names.at(code);
		}

		return "UNKNOWN";
	}

	std::ostream& operator<<(std::ostream& out, key_code value) {
		return out << get_key_name(value);
	}
}
