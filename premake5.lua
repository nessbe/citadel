-- File:        premake5.lua (citadel)
-- Project:     citadel
-- Repository:  https://github.com/nessbe/citadel
--
-- Copyright (c) 2025 nessbe
-- Licensed under the Apache License, Version 2.0 (the "License");
-- you may not use this file except in compliance with the License.
-- You may obtain a copy of the License at:
--
--     https://www.apache.org/licenses/LICENSE-2.0
--
-- Unless required by applicable law or agreed to in writing, software
-- distributed under the License is distributed on an "AS IS" BASIS,
-- WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
-- See the License for the specific language governing permissions and
-- limitations under the License.
--
-- For more details, see the LICENSE file at the root of the project.

project "citadel"
	kind "SharedLib"
	staticruntime "Off"

	language "C++"
	cppdialect("C++" .. cpp_dialect)

	pchheader "citadel/pch.h"
	pchsource "source/pch.cpp"

	targetdir(root_dir .. "bin/" .. output_dir .. "%{prj.name}/")
	objdir(root_dir .. "bin-int/" .. output_dir .. "%{prj.name}/")

	files {
		"include/**.h",
		"source/**.cpp"
	}

	includedirs {
		"include/"
	}

	filter "kind:StaticLib"
		defines {
			"CITADEL_LINKAGE_STATIC"
		}

	filter "kind:SharedLib"
		defines {
			"CITADEL_LINKAGE_SHARED",
			"CITADEL_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines {
			"CITADEL_DEBUG"
		}

		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines {
			"CITADEL_RELEASE"
		}

		runtime "Release"
		optimize "On"
