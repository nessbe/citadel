// File:       architectures.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#define CITADEL_ARCHITECTURE_32_BIT    0
#define CITADEL_ARCHITECTURE_64_BIT    0
#define CITADEL_ARCHITECTURE_X86_32    0
#define CITADEL_ARCHITECTURE_X86_64    0
#define CITADEL_ARCHITECTURE_ARM2      0
#define CITADEL_ARCHITECTURE_ARM3      0
#define CITADEL_ARCHITECTURE_ARM4T     0
#define CITADEL_ARCHITECTURE_ARM5      0
#define CITADEL_ARCHITECTURE_ARM6T2    0
#define CITADEL_ARCHITECTURE_ARM6      0
#define CITADEL_ARCHITECTURE_ARM7      0
#define CITADEL_ARCHITECTURE_ARM32     0
#define CITADEL_ARCHITECTURE_ARM64     0
#define CITADEL_ARCHITECTURE_MIPS      0
#define CITADEL_ARCHITECTURE_SUPERH    0
#define CITADEL_ARCHITECTURE_POWERPC   0
#define CITADEL_ARCHITECTURE_POWERPC64 0
#define CITADEL_ARCHITECTURE_SPARC     0
#define CITADEL_ARCHITECTURE_M68K      0
#define CITADEL_ARCHITECTURE_RISCV     0

#if defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
	#undef CITADEL_ARCHITECTURE_X86_32
	#define CITADEL_ARCHITECTURE_X86_32 1
#elif defined(__x86_64__) || defined(_M_X64)
	#undef CITADEL_ARCHITECTURE_X86_64
	#define CITADEL_ARCHITECTURE_X86_64 1
#elif defined(__ARM_ARCH_2__)
	#undef CITADEL_ARCHITECTURE_ARM2
	#define CITADEL_ARCHITECTURE_ARM2 1
#elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
	#undef CITADEL_ARCHITECTURE_ARM3
	#define CITADEL_ARCHITECTURE_ARM3 1
#elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
	#undef CITADEL_ARCHITECTURE_ARM4T
	#define CITADEL_ARCHITECTURE_ARM4T 1
#elif defined(__ARM_ARCH_5__) || defined(__ARM_ARCH_5E_)
	#undef CITADEL_ARCHITECTURE_ARM5
	#define CITADEL_ARCHITECTURE_ARM5 1
#elif defined(__ARM_ARCH_6T2__) || defined(__ARM_ARCH_6T2_)
	#undef CITADEL_ARCHITECTURE_ARM6T2
	#define CITADEL_ARCHITECTURE_ARM6T2 1
#elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__)
	#undef CITADEL_ARCHITECTURE_ARM6
	#define CITADEL_ARCHITECTURE_ARM6 1
#elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
	#undef CITADEL_ARCHITECTURE_ARM7
	#define CITADEL_ARCHITECTURE_ARM7 1
#elif defined(__arm__) || defined(_M_ARM)
	#undef CITADEL_ARCHITECTURE_ARM32
	#define CITADEL_ARCHITECTURE_ARM32 1
#elif defined(__aarch64__) || defined(_M_ARM64)
	#undef CITADEL_ARCHITECTURE_ARM64
	#define CITADEL_ARCHITECTURE_ARM64 1
#elif defined(mips) || defined(__mips__) || defined(__mips)
	#undef CITADEL_ARCHITECTURE_MIPS
	#define CITADEL_ARCHITECTURE_MIPS 1
#elif defined(__sh__)
	#undef CITADEL_ARCHITECTURE_SUPERH
	#define CITADEL_ARCHITECTURE_SUPERH 1
#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
	#undef CITADEL_ARCHITECTURE_POWERPC
	#define CITADEL_ARCHITECTURE_POWERPC 1
#elif defined(__PPC64__) || defined(__ppc64__) || defined(_ARCH_PPC64)
	#undef CITADEL_ARCHITECTURE_POWERPC64
	#define CITADEL_ARCHITECTURE_POWERPC64 1
#elif defined(__sparc__) || defined(__sparc)
	#undef CITADEL_ARCHITECTURE_SPARC
	#define CITADEL_ARCHITECTURE_SPARC 1
#elif defined(__m68k__)
	#undef CITADEL_ARCHITECTURE_M68K
	#define CITADEL_ARCHITECTURE_M68K 1
#elif defined(__riscv) || defined(__riscv_xlen)
	#undef CITADEL_ARCHITECTURE_RISCV
	#define CITADEL_ARCHITECTURE_RISCV 1
#endif

#ifdef __riscv_xlen
	#if __riscv_xlen == 64
		#undef CITADEL_ARCHITECTURE_64_BIT
		#define CITADEL_ARCHITECTURE_64_BIT 1
	#elif __riscv_xlen == 32
		#undef CITADEL_ARCHITECTURE_32_BIT
		#define CITADEL_ARCHITECTURE_32_BIT 1
	#endif
#else
	#if defined(_WIN64) || defined(__x86_64__) || defined(__aarch64__) || defined(__LP64__)
		#undef CITADEL_ARCHITECTURE_64_BIT
		#define CITADEL_ARCHITECTURE_64_BIT 1
	#else
		#undef CITADEL_ARCHITECTURE_32_BIT
		#define CITADEL_ARCHITECTURE_32_BIT 1
	#endif
#endif
