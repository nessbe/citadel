:: File:       generate-vs-projects.bat
:: Project:    citadel
:: Repository: https://github.com/nessbe/citadel
::
:: Copyright (c) 2025 nessbe
:: Licensed under the Apache License, Version 2.0 (the "License");
:: you may not use this file except in compliance with the License.
:: You may obtain a copy of the License at:
::
::     https://www.apache.org/licenses/LICENSE-2.0
::
:: Unless required by applicable law or agreed to in writing, software
:: distributed under the License is distributed on an "AS IS" BASIS,
:: WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
:: See the License for the specific language governing permissions and
:: limitations under the License.
::
:: For more details, see the LICENSE file at the root of the project.

@echo off

set "VISUAL_STUDIO_VERSION=2022"

where premake5 >nul 2>&1

if %errorlevel% neq 0 (
	echo Premake is not installed.
	echo Please install the Premake binary before continuing.
	echo You can find it at this link:
	echo https://premake.github.io/download/
	exit /b 1
)

pushd "%~dp0\.."

call premake5.exe vs%VISUAL_STUDIO_VERSION%

popd

if %errorlevel% neq 0 (
	echo Failed to generate Visual Studio project files.
	exit /b 1
) else (
	echo Visual Studio project files generated successfully.
	exit /b 0
)
