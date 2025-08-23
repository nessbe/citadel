// File:        architectures.h
// Project:     citadel
// Repository:  https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// For more details, see the LICENSE file at the root of the project.

#pragma once

#ifndef CITADEL_ARCHITECTURES_H
#define CITADEL_ARCHITECTURES_H

#define CITADEL_ARCHITECTURE_X86_32 0
#define CITADEL_ARCHITECTURE_X86_64 0
#define CITADEL_ARCHITECTURE_ARM_32 0
#define CITADEL_ARCHITECTURE_ARM_64 0
#define CITADEL_ARCHITECTURE_POWERPC 0
#define CITADEL_ARCHITECTURE_RISCV 0
#define CITADEL_ARCHITECTURE_UNKNOWN 0

#define CITADEL_ARCHITECTURE_X86_32_NAME "x86"
#define CITADEL_ARCHITECTURE_X86_64_NAME "x86_64"
#define CITADEL_ARCHITECTURE_ARM_32_NAME "ARM32"
#define CITADEL_ARCHITECTURE_ARM_64_NAME "ARM64"
#define CITADEL_ARCHITECTURE_POWERPC_NAME "PowerPC"
#define CITADEL_ARCHITECTURE_RISCV_NAME "RISC-V"
#define CITADEL_ARCHITECTURE_UNKNOWN_NAME "Unknown"

#define CITADEL_ARCHITECTURE_64BIT 0
#define CITADEL_ARCHITECTURE_32BIT 0

#if defined(__i386__) || defined(_M_IX86)
	#undef CITADEL_ARCHITECTURE_X86_32
	#define CITADEL_ARCHITECTURE_X86_32 1
	#define CITADEL_ARCHITECTURE_NAME CITADEL_ARCHITECTURE_X86_32_NAME
#elif defined(__x86_64__) || defined(_M_X64) || defined(_M_AMD64)
	#undef CITADEL_ARCHITECTURE_X86_64
	#define CITADEL_ARCHITECTURE_X86_64 1
	#define CITADEL_ARCHITECTURE_NAME CITADEL_ARCHITECTURE_X86_64_NAME
#elif defined(__arm__) || defined(_M_ARM)
	#undef CITADEL_ARCHITECTURE_ARM_32
	#define CITADEL_ARCHITECTURE_ARM_32 1
	#define CITADEL_ARCHITECTURE_NAME CITADEL_ARCHITECTURE_ARM_32_NAME
#elif defined(__aarch64__) || defined(_M_ARM64)
	#undef CITADEL_ARCHITECTURE_ARM_64
	#define CITADEL_ARCHITECTURE_ARM_64 1
	#define CITADEL_ARCHITECTURE_NAME CITADEL_ARCHITECTURE_ARM_64_NAME
#elif defined(__powerpc__) || defined(__ppc__) || defined(_M_PPC)
	#undef CITADEL_ARCHITECTURE_POWERPC
	#define CITADEL_ARCHITECTURE_POWERPC 1
	#define CITADEL_ARCHITECTURE_NAME CITADEL_ARCHITECTURE_POWERPC_NAME
#elif defined(__riscv) || defined(__riscv_xlen)
	#undef CITADEL_ARCHITECTURE_RISCV
	#define CITADEL_ARCHITECTURE_RISCV 1
	#define CITADEL_ARCHITECTURE_NAME CITADEL_ARCHITECTURE_RISCV_NAME
#else
	#undef CITADEL_ARCHITECTURE_UNKNOWN
	#define CITADEL_ARCHITECTURE_UNKNOWN 1
	#define CITADEL_ARCHITECTURE_NAME CITADEL_ARCHITECTURE_UNKNOWN_NAME
#endif

#if defined(__riscv_xlen)
	#if __risv_xlen == 64
		#undef CITADEL_ARCHITECTURE_64BIT
		#define CITADEL_ARCHITECTURE_64BIT 1
	#elif __riscv_xlen == 32
		#undef CITADEL_ARCHITECTURE_32BIT
		#define CITADEL_ARCHITECTURE_32BIT 1
	#endif
#else
	#if defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__) || defined(__LP64__)
		#undef CITADEL_ARCHITECTURE_64BIT
		#define CITADEL_ARCHITECTURE_64BIT 1
	#else
		#undef CITADEL_ARCHITECTURE_32BIT
		#define CITADEL_ARCHITECTURE_32BIT 1
	#endif
#endif

#endif
