# File:       build-gmake.sh
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

chmod +x generate-makefiles.sh
./generate-makefiles.sh

if [ $? -ne 0 ]; then
	exit 1
fi

if ! command -v make &> /dev/null; then
	echo "Make is not installed."
	echo "Please install the Make binary before continuing."
	echo "You can find it at this link:"
	echo "https://ftp.gnu.org/gnu/make/"
	exit 1
fi

pushd .. &> /dev/null

make clean && make

popd &> /dev/null

if [ $? -ne 0 ]; then
	echo "Build failed."
	exit 1
else
	echo "Build was successful."
	exit 0
fi
