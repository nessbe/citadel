-- File:       basic_application.lua
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

project "basic_application"
	kind "WindowedApp"
	language "C++"
	cppdialect "C++17"

	targetdir("%{wks.location}/build/bin/%{prj.name}")
	objdir("%{wks.location}/build/obj/%{prj.name}")

	defines "CITADEL_THIS_LOGGER_NAME=\"BASIC_APPLICATION\""

	files {
		"include/**.hpp",
		"include/**.inl",
		"source/**.cpp"
	}

	includedirs {
		"include"
	}

	externalincludedirs {
		"%{wks.location}/include",
		"%{wks.location}/vendor/glad/include"
	}

	links {
		"opengl32",
		"gdi32",
		"citadel",
		"glad"
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

	filter "kind:WindowedApp"
		defines "CITADEL_WINDOWED"

	filter "configurations:debug"
		defines "CITADEL_DEBUG"
		symbols "On"
		runtime "Debug"

	filter "configurations:release"
		defines "CITADEL_RELEASE"
		optimize "On"
		runtime "Release"
