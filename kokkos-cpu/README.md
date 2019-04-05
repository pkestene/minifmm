Please use cmake to build:

1. mkdir build_cpu; cd build_cpu
2. cmake -DKOKKOS_ENABLE_OPENMP=ON ..
3. make -j 4

The old flat `Makefile.old` is kept for reference.
