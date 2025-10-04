// File:       windows_key_code.cpp
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
#include "citadel/platforms/windows/windows_key_code.hpp"

#if CITADEL_PLATFORM_WINDOWS

namespace citadel {
	const std::unordered_map<std::uint16_t, key_code> windows_key_codes = {
		// ASCII
		{ ' ',                   key_code::space                },
		{ '!',                   key_code::exclamation_mark     },
		{ '"',                   key_code::quote                },
		{ '#',                   key_code::hash                 },
		{ '$',                   key_code::dollar_sign          },
		{ '%',                   key_code::percent              },
		{ '&',                   key_code::ampersand            },
		{ '\'',                  key_code::apostrophe           },
		{ '(',                   key_code::open_parenthesis     },
		{ ')',                   key_code::close_parenthesis    },
		{ '*',                   key_code::asterisk             },
		{ '+',                   key_code::plus                 },
		{ ',',                   key_code::comma                },
		{ '-',                   key_code::minus                },
		{ '.',                   key_code::period               },
		{ '/',                   key_code::slash                },
		{ ':',                   key_code::colon                },
		{ ';',                   key_code::semicolon            },
		{ '<',                   key_code::less_than            },
		{ '=',                   key_code::equal                },
		{ '>',                   key_code::greater_than         },
		{ '?',                   key_code::question_mark        },
		{ '@',                   key_code::at                   },
		{ '[',                   key_code::open_bracket         },
		{ '\\',                  key_code::backslash            },
		{ ']',                   key_code::close_bracket        },
		{ '^',                   key_code::caret                },
		{ '_',                   key_code::underscore           },
		{ '`',                   key_code::backtick             },
		{ '{',                   key_code::open_brace           },
		{ '|',                   key_code::pipe                 },
		{ '}',                   key_code::close_brace          },
		{ '~',                   key_code::tilde                },


		// Digits
		{ '0',                   key_code::zero                 },
		{ '1',                   key_code::one                  },
		{ '2',                   key_code::two                  },
		{ '3',                   key_code::three                },
		{ '4',                   key_code::four                 },
		{ '5',                   key_code::five                 },
		{ '6',                   key_code::six                  },
		{ '7',                   key_code::seven                },
		{ '8',                   key_code::eight                },
		{ '9',                   key_code::nine                 },

		// Capital letters
		{ 'A',                   key_code::A                    },
		{ 'B',                   key_code::B                    },
		{ 'C',                   key_code::C                    },
		{ 'D',                   key_code::D                    },
		{ 'E',                   key_code::E                    },
		{ 'F',                   key_code::F                    },
		{ 'G',                   key_code::G                    },
		{ 'H',                   key_code::H                    },
		{ 'I',                   key_code::I                    },
		{ 'J',                   key_code::J                    },
		{ 'K',                   key_code::K                    },
		{ 'L',                   key_code::L                    },
		{ 'M',                   key_code::M                    },
		{ 'N',                   key_code::N                    },
		{ 'O',                   key_code::O                    },
		{ 'P',                   key_code::P                    },
		{ 'Q',                   key_code::Q                    },
		{ 'R',                   key_code::R                    },
		{ 'S',                   key_code::S                    },
		{ 'T',                   key_code::T                    },
		{ 'U',                   key_code::U                    },
		{ 'V',                   key_code::V                    },
		{ 'W',                   key_code::W                    },
		{ 'X',                   key_code::X                    },
		{ 'Y',                   key_code::Y                    },
		{ 'Z',                   key_code::Z                    },

		// Control
		{ VK_ESCAPE,             key_code::escape               },
		{ VK_RETURN,             key_code::enter                },
		{ VK_TAB,                key_code::tab                  },
		{ VK_BACK,               key_code::backspace            },
		{ VK_SHIFT,              key_code::left_shift           },
		{ VK_CONTROL,            key_code::left_control         },
		{ VK_MENU,               key_code::left_alt             },
		{ VK_LSHIFT,             key_code::left_shift           },
		{ VK_RSHIFT,             key_code::right_shift          },
		{ VK_LCONTROL,           key_code::left_control         },
		{ VK_RCONTROL,           key_code::right_control        },
		{ VK_LMENU,              key_code::left_alt             },
		{ VK_RMENU,              key_code::right_alt            },
		{ VK_CAPITAL,            key_code::caps_lock            },
		{ VK_LWIN,               key_code::left_super           },
		{ VK_RWIN,               key_code::right_super          },
		{ VK_APPS,               key_code::menu                 },
								        
		// Navigation					        
		{ VK_UP,                 key_code::arrow_up             },
		{ VK_DOWN,               key_code::arrow_down           },
		{ VK_LEFT,               key_code::arrow_left           },
		{ VK_RIGHT,              key_code::arrow_right          },
		{ VK_HOME,               key_code::home                 },
		{ VK_END,                key_code::end                  },
		{ VK_PRIOR,              key_code::page_up              },
		{ VK_NEXT,               key_code::page_down            },
		{ VK_INSERT,             key_code::insert               },
		{ VK_DELETE,             key_code::delete_key           },

		// Numeric Pad
		{ VK_NUMLOCK,            key_code::num_lock             },
		{ VK_NUMPAD0,            key_code::numpad_0             },
		{ VK_NUMPAD1,            key_code::numpad_1             },
		{ VK_NUMPAD2,            key_code::numpad_2             },
		{ VK_NUMPAD3,            key_code::numpad_3             },
		{ VK_NUMPAD4,            key_code::numpad_4             },
		{ VK_NUMPAD5,            key_code::numpad_5             },
		{ VK_NUMPAD6,            key_code::numpad_6             },
		{ VK_NUMPAD7,            key_code::numpad_7             },
		{ VK_NUMPAD8,            key_code::numpad_8             },
		{ VK_NUMPAD9,            key_code::numpad_9             },
		{ VK_ADD,                key_code::numpad_add           },
		{ VK_SUBTRACT,           key_code::numpad_subtract      },
		{ VK_MULTIPLY,           key_code::numpad_multiply      },
		{ VK_DIVIDE,             key_code::numpad_divide        },
		{ VK_DECIMAL,            key_code::numpad_period        },
		{ VK_SEPARATOR,          key_code::numpad_enter         },
								        
		// Functions					        
		{ VK_F1,                 key_code::f1                   },
		{ VK_F2,                 key_code::f2                   },
		{ VK_F3,                 key_code::f3                   },
		{ VK_F4,                 key_code::f4                   },
		{ VK_F5,                 key_code::f5                   },
		{ VK_F6,                 key_code::f6                   },
		{ VK_F7,                 key_code::f7                   },
		{ VK_F8,                 key_code::f8                   },
		{ VK_F9,                 key_code::f9                   },
		{ VK_F10,                key_code::f10                  },
		{ VK_F11,                key_code::f11                  },
		{ VK_F12,                key_code::f12                  },
		{ VK_F13,                key_code::f13                  },
		{ VK_F14,                key_code::f14                  },
		{ VK_F15,                key_code::f15                  },
		{ VK_F16,                key_code::f16                  },
		{ VK_F17,                key_code::f17                  },
		{ VK_F18,                key_code::f18                  },
		{ VK_F19,                key_code::f19                  },
		{ VK_F20,                key_code::f20                  },
		{ VK_F21,                key_code::f21                  },
		{ VK_F22,                key_code::f22                  },
		{ VK_F23,                key_code::f23                  },
		{ VK_F24,                key_code::f24                  },

		// System
		{ VK_SNAPSHOT,           key_code::print_screen         },
		{ VK_PAUSE,              key_code::pause                },
		{ VK_SCROLL,             key_code::scroll_lock          },
								        
		// Non-standard					        
		{ VK_VOLUME_UP,          key_code::volume_up            },
		{ VK_VOLUME_DOWN,        key_code::volume_down          },
		{ VK_VOLUME_MUTE,        key_code::volume_mute          },
		{ VK_MEDIA_PLAY_PAUSE,   key_code::media_play           },
		{ VK_MEDIA_STOP,         key_code::media_stop           },
		{ VK_MEDIA_NEXT_TRACK,   key_code::media_next           },
		{ VK_MEDIA_PREV_TRACK,   key_code::media_previous       },
};


	key_code get_key_code_windows(std::uint16_t code) {
		if (windows_key_codes.find(code) != windows_key_codes.end()) {
			return windows_key_codes.at(code);
		}

		return key_code::none;
	}
}

#endif
