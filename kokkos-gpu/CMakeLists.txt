cmake_minimum_required(VERSION 3.3)

project(fmm-cpu C CXX)

# C++11 is for Kokkos
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

option (USE_DOUBLE "build with double precision" ON)
if (USE_DOUBLE)
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_DOUBLE" )
endif()

#
# sources
#

# first build kokkos
add_subdirectory(kokkos)

# pass Kokkos include directories to our target application
include_directories(${Kokkos_INCLUDE_DIRS_RET})

# build fmm_kokkos_cpu
set (FMM_SRC
  cuda_utils.h
  dtt.cpp
  dtt.h
  finalise.cpp
  finalise.h
  initialise.cpp
  initialise.h
  kernels_gpu.cpp
  kernels_gpu.h
  kernels.cpp
  kernels.h
  parse_args.cpp
  parse_args.h
  params.h
  rng.h
  spharm_gpu.cpp
  spharm_gpu.h
  spharm.cpp
  spharm.h
  tree.cpp
  tree.h
  timer.h
  traversal.cpp
  traversal.h
  main.cpp
  type.h
  type_double.h
  type_float.h
  verify.cpp
  verify.h
  scheduler.hpp)

add_executable(fmm_kokkos_gpu
  ${FMM_SRC})

target_include_directories(fmm_kokkos_gpu
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  )
target_link_libraries(fmm_kokkos_gpu kokkos)
