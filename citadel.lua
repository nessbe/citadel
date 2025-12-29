-- File:       citadel.lua
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

project "citadel"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"

	targetdir("build/bin")
	objdir("build/obj")

	pchheader "citadel/pch.hpp"
	pchsource "source/pch.cpp"

	defines "CITADEL_THIS_LOGGER_NAME=\"CITADEL\""

	files {
		"include/**.hpp",
		"include/**.inl",
		"source/**.cpp"
	}

	includedirs {
		"include"
	}

	externalincludedirs {
		"vendor/glad/include",
		"vendor/lua/include"
	}

	links {
		"opengl32",
		"glad",
		"lua"
	}

	dependson {
		"lua"
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

	filter "kind:StaticLib"
		defines "CITADEL_LINKAGE_STATIC"

	filter "kind:SharedLib"
		defines {
			"CITADEL_LINKAGE_DYNAMIC",
			"CITADEL_BUILD_DLL"
		}

	filter "configurations:debug"
		defines "CITADEL_DEBUG"
		symbols "On"
		runtime "Debug"

	filter "configurations:release"
		defines "CITADEL_RELEASE"
		optimize "On"
		runtime "Release"
