-- File:       glad.lua
-- Project:    citadel
-- Repository: https://github.com/nessbe/citadel
--
-- Copyright (c) 2025 nessbe
-- This file is part of the citadel project and is licensed
-- under the terms specified in the LICENSE file located at the
-- root of this repository.
--
-- Unless required by applicable law or agreed to in writing,
-- the software is distributed on an "AS IS" BASIS, WITHOUT
-- WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
-- See the LICENSE file for details.

project "glad"
	kind "StaticLib"
	language "C"
	cdialect "C99"

	targetdir("%{wks.location}/build/bin")
	objdir("%{wks.location}/build/obj")

	files {
		"include/**.h",
		"src/**.c"
	}

	includedirs {
		"include"
	}

	links {
		"opengl32"
	}

	filter "configurations:debug"
		defines "DEBUG"
		symbols "On"
		runtime "Debug"

	filter "configurations:release"
		defines "NDEBUG"
		optimize "On"
		runtime "Release"
