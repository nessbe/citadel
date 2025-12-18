-- File:       citadel_c.lua
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

project "citadel_c"
	kind "StaticLib"
	language "C"
	cdialect "C99"

	targetdir("%{wks.location}/build/bin/%{prj.location}")
	objdir("%{wks.location}/build/obj/%{prj.location}")

	files {
		"include/**.h",
		"source/**.c"
	}

	includedirs {
		"include"
	}

	filter "action:gmake"
		buildoptions {
			"-Wall",
			"-Wno-unused-parameter"
		}

	filter "action:vs*"
		buildoptions {
			"/Wall",
			"/Qspectre",
			"/wd28251",
			"/wd4100"
		}

	filter "configurations:debug"
		symbols "On"
		runtime "Debug"

	filter "configurations:release"
		optimize "On"
		runtime "Release"
