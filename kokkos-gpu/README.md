Work in progress:

 - Dual-tree traversal parallelised with Kokkos
 - Currently only works with single-precision types and num\_terms = 4

Example of build command line for "regular" makefile:
make KOKKOS_PATH=/home/pkestene/kokkos-tutorial/kokkos NVCC_WRAPPER=/home/pkestene/kokkos-tutorial/kokkos/bin/nvcc_wrapper KOKKOS_DEVICES=Cuda,OpenMP KOKKOS_ARCH=Kepler30 TARGET=GPU 

You can also use cmake in an out-of-source build (to avoid overwritting Makefile).
