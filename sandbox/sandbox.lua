-- File:       sandbox.lua
-- Project:    citadel
-- Repository: https://github.com/nessbe/citadel
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

project "sandbox"
	kind "ConsoleApp"

	language "C++"
	cppdialect "C++20"

	targetdir(target_dir .. output_path .. "%{prj.name}")
	objdir(obj_dir .. output_path .. "%{prj.name}")

	links {
		"citadel"
	}

	files {
		"include/**.hpp",
		"include/**.inl",
		"source/**.cpp"
	}

	includedirs {
		"include"
	}

	externalincludedirs {
		root_dir .. "citadel/include"
	}

	filter "action:gmake"
		buildoptions(gcc_build_options)

	filter "action:vs*"
		buildoptions(msvc_build_options)

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "SANDBOX_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SANDBOX_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Distribution"
		defines "SANDBOX_DISTRIBUTION"
		runtime "Release"
		optimize "Full"
		staticruntime "On"
