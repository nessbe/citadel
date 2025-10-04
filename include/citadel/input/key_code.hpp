// File:       key_code.hpp
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

#include <cinttypes>
#include <ostream>
#include <string>
#include <unordered_map>

#include "citadel/export.hpp"

namespace citadel {
	enum class key_code : std::uint16_t {
		none                 =   0,

		// ASCII
		space                =  32,
		exclamation_mark     =  33, // !
		quote                =  34, // "
		hashtag              =  35, // #
		dollar_sign          =  36, // $
		percent              =  37, // %
		ampersand            =  38, // &
		apostrophe           =  39, // '
		open_parenthesis     =  40, // (
		close_parenthesis    =  41, // )
		asterisk             =  42, // *
		plus                 =  43, // +
		comma                =  44, // ,
		hyphen               =  45, // -
		period               =  46, // .
		slash                =  47, // /
		zero                 =  48, // 0
		one                  =  49, // 1
		two                  =  50, // 2
		three                =  51, // 3
		four                 =  52, // 4
		five                 =  53, // 5
		six                  =  54, // 6
		seven                =  55, // 7
		eight                =  56, // 8
		nine                 =  57, // 9
		colon                =  58, // :
		semicolon            =  59, // ;
		open_angle_bracket   =  60, // <
		equal                =  61, // =
		close_angle_bracket  =  62, // >
		question_mark        =  63, // ?
		ampersat             =  64, // @
		A                    =  65, // A
		B                    =  66, // B
		C                    =  67, // C
		D                    =  68, // D
		E                    =  69, // E
		F                    =  70, // F
		G                    =  71, // G
		H                    =  72, // H
		I                    =  73, // I
		J                    =  74, // J
		K                    =  75, // K
		L                    =  76, // L
		M                    =  77, // M
		N                    =  78, // N
		O                    =  79, // O
		P                    =  80, // P
		Q                    =  81, // Q
		R                    =  82, // R
		S                    =  83, // S
		T                    =  84, // T
		U                    =  85, // U
		V                    =  86, // V
		W                    =  87, // W
		X                    =  88, // X
		Y                    =  89, // Y
		Z                    =  90, // Z
		open_square_bracket  =  91, // [
		backslash            =  92,
		close_square_bracket =  93, // ]
		caret                =  94, // ^
		underscore           =  95, // _
		backquote            =  96, // `
		a                    =  97, // a
		b                    =  98, // b
		c                    =  99, // c
		d                    = 100, // d
		e                    = 101, // e
		f                    = 102, // f
		g                    = 103, // g
		h                    = 104, // h
		i                    = 105, // i
		j                    = 106, // j
		k                    = 107, // k
		l                    = 108, // l
		m                    = 109, // m
		n                    = 110, // n
		o                    = 111, // o
		p                    = 112, // p
		q                    = 113, // q
		r                    = 114, // r
		s                    = 115, // s
		t                    = 116, // t
		u                    = 117, // u
		v                    = 118, // v
		w                    = 119, // w
		x                    = 120, // x
		y                    = 121, // y
		z                    = 122, // z
		open_curly_bracket   = 123, // {
		pipe                 = 124, // |
		close_curly_bracket  = 125, // }
		tilde                = 126, // ~
		del                  = 127,

		// Control
		escape               = 128,
		enter                = 129,
		tab                  = 130,
		backspace            = 131,
		left_shift           = 132,
		right_shift          = 133,
		left_control         = 134,
		right_control        = 135,
		left_alt             = 136,
		right_alt            = 137,
		caps_lock            = 138,
		left_super           = 139,
		right_super          = 140, // Windows key or Command
		menu                 = 141,

		// Navigation
		arrow_up             = 160,
		arrow_down           = 161,
		arrow_left           = 162,
		arrow_right          = 163,
		home                 = 164,
		end                  = 165,
		page_up              = 166,
		page_down            = 167,
		insert               = 168,
		del_key              = 169,

		// Numeric Pad
		num_lock             = 190,
		numpad_0             = 191,
		numpad_1             = 192,
		numpad_2             = 193,
		numpad_3             = 194,
		numpad_4             = 195,
		numpad_5             = 196,
		numpad_6             = 197,
		numpad_7             = 198,
		numpad_8             = 199,
		numpad_9             = 200,
		numpad_add           = 201,
		numpad_subtract      = 202,
		numpad_multiply      = 203,
		numpad_divide        = 204,
		numpad_enter         = 205,
		numpad_period        = 206,

		// Functions
		f1                   = 221,
		f2                   = 222,
		f3                   = 223,
		f4                   = 224,
		f5                   = 225,
		f6                   = 226,
		f7                   = 227,
		f8                   = 228,
		f9                   = 229,
		f10                  = 230,
		f11                  = 231,
		f12                  = 232,
		f13                  = 233,
		f14                  = 234,
		f15                  = 235,
		f16                  = 236,
		f17                  = 237,
		f18                  = 238,
		f19                  = 239,
		f20                  = 240,
		f21                  = 241,
		f22                  = 242,
		f23                  = 243,
		f24                  = 244,

		// Multimedia / System
		print_screen         = 250,
		pause                = 251,
		scroll_lock          = 252,
		volume_up            = 253,
		volume_down          = 254,
		volume_mute          = 255,
		media_play           = 256,
		media_stop           = 257,
		media_next           = 258,
		media_previous       = 259,
	};

	CITADEL_API extern const std::unordered_map<key_code, std::string> key_names;
	CITADEL_API std::string get_key_name(key_code code) noexcept;
	CITADEL_API std::ostream& operator<<(std::ostream& out, key_code value);
}

namespace std {
	template <>
	struct hash<citadel::key_code> {
		size_t operator()(const citadel::key_code& value) const noexcept {
			return static_cast<size_t>(value);
		}
	};
}

