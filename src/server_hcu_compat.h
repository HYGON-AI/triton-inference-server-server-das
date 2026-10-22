/***********************************************************************************
# Copyright (c) 2026 Hygon Information Technology Co., Ltd.
# SPDX-License-Identifier: BSD-3-Clause
**********************************************************************************/
// HCU (Hygon DTK / ROCm) compatibility shim for the Triton server.
//
// When USE_HCU is defined this maps the CUDA runtime names used by the server
// sources onto their HIP equivalents, so the existing sources compile
// unchanged on the HCU path. When USE_HCU is not defined it expands to nothing.
//
#pragma once

#ifdef USE_HCU
#include <hip/hip_runtime.h>

#ifndef CUDART_CB
#define CUDART_CB
#endif

// Type aliases.
using cudaError_t = hipError_t;
using cudaIpcMemHandle_t = hipIpcMemHandle_t;
using CUdeviceptr = hipDeviceptr_t;
using CUresult = hipError_t;
using cudaPointerAttributes = hipPointerAttribute_t;

// Enumerators.
#define cudaSuccess hipSuccess
#define CUDA_SUCCESS hipSuccess
#define cudaErrorNoDevice hipErrorNoDevice
#define cudaErrorInsufficientDriver hipErrorInsufficientDriver
#define cudaMemcpyHostToHost hipMemcpyHostToHost
#define cudaMemcpyHostToDevice hipMemcpyHostToDevice
#define cudaMemcpyDeviceToHost hipMemcpyDeviceToHost
#define cudaMemoryTypeHost hipMemoryTypeHost
#define cudaMemoryTypeDevice hipMemoryTypeDevice
#define cudaHostAllocPortable hipHostMallocPortable
#define cudaIpcMemLazyEnablePeerAccess hipIpcMemLazyEnablePeerAccess

// Runtime API.
#define cudaGetErrorString hipGetErrorString
#define cudaMemcpy hipMemcpy
#define cudaMemcpyAsync hipMemcpyAsync
#define cudaMemset hipMemset
#define cudaSetDevice hipSetDevice
#define cudaMalloc hipMalloc
#define cudaFree hipFree
#define cudaHostAlloc hipHostAlloc
#define cudaFreeHost hipHostFree
#define cudaStreamSynchronize hipStreamSynchronize
#define cudaPointerGetAttributes hipPointerGetAttributes
#define cudaIpcOpenMemHandle hipIpcOpenMemHandle
#define cudaIpcCloseMemHandle hipIpcCloseMemHandle
#endif  // USE_HCU
