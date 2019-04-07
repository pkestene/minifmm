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
  ../ref/finalise.cpp
  ../ref/initialise.cpp
  ../ref/main.cpp
  ../ref/parse_args.cpp
  ../ref/spharm.cpp
  ../ref/timer.cpp
  ../ref/traversal.cpp
  ../ref/tree.cpp
  ../ref/type.cpp
  ../ref/verify.cpp
  dtt.cpp
  kernels.cpp
  scheduler.hpp)

add_executable(fmm_kokkos_cpu
  ${FMM_SRC})

target_include_directories(fmm_kokkos_cpu
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../ref>
  )
target_link_libraries(fmm_kokkos_cpu kokkos)
