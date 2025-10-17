# File:       generate-vs-projects.sh
# Project:    citadel
# Repository: https://github.com/nessbe/citadel
#
# Copyright (c) 2025 nessbe
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at:
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# For more details, see the LICENSE file at the root of the project.

#!/bin/bash

VISUAL_STUDIO_VERSION=2022

if ! command -v premake5 &> /dev/null; then
	echo "Premake is not installed."
	echo "Please install the Premake binary before continuing."
	echo "You can find it at this link:"
	echo "https://premake.github.io/download/"
	exit 1
fi

pushd .. &> /dev/null

premake5 vs$VISUAL_STUDIO_VERSION

popd &> /dev/null

if [ $? -ne 0 ]; then
	echo "Failed to generate Visual Studio project files."
	exit 1
else
	echo "Visual Studio project files generated successfully."
	exit 0
fi
