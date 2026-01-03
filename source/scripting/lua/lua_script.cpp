#include "citadel/pch.hpp"
#include "citadel/scripting/lua/lua_script.hpp"

#include "citadel/io/filesystem/file.hpp"

#include "citadel/scripting/lua.hpp"

namespace citadel {
	lua_script::lua_script(const reference<random_access_stream>& stream)
		: script(stream), state_(make_referenced<lua_state>()), stack_(state_)
	{
		reload();
	}

	lua_state& lua_script::state() noexcept {
		return *state_;
	}

	lua_stack& lua_script::stack() noexcept {
		return stack_;
	}

	bool lua_script::_can_reload() const noexcept {
		return state_ != nullptr;
	}

	void lua_script::_reload() {
		if (reference<file> file = std::dynamic_pointer_cast<class file>(stream_)) {
			luaL_dofile(state_->native_handle(), file->path().c_str());
		}
		else {
			std::string content;
			stream().read(content.data(), static_cast<stream::size_type>(content.size()));

			luaL_dostring(state_->native_handle(), content.c_str());
		}
	}
}
