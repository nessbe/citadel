:: File:       build-gmake.bat
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

call generate-makefiles.bat

if %errorlevel% neq 0 (
	exit /b 1
)

where make >nul 2>&1

if %errorlevel% neq 0 (
	echo Make is not installed.
	echo Please install the Make binary before continuing.
	echo You can find it at this link:
	echo https://ftp.gnu.org/gnu/make/
)

pushd "%~dp0\.."

make clean && make

popd

if %errorlevel% neq 0 (
	echo Build failed.
	exit /b 1
) else (
	echo Build was successful.
	exit /b 0
)
