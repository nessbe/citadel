-- File:       .gitignore
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

project "citadel"
	kind "StaticLib"
	staticruntime "Off"

	language "C++"
	cppdialect(cpp_dialect)

	targetdir(root_dir .. target_dir .. output_dir .. "%{prj.name}")
	objdir(root_dir .. obj_dir .. output_dir .. "%{prj.name}")

	files {
		"include/**.hpp",
		"include/**.inl",
		"source/**.cpp"
	}

	includedirs {
		"include"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

		defines {
			"CITADEL_DEBUG"
		}

	filter "configurations:Release"
		runtime "Release"
		optimize "On"

		defines {
			"CITADEL_RELEASE"
		}

