Please use cmake to build:

1. mkdir build_cpu; cd build_cpu
2. cmake -DKOKKOS_ENABLE_OPENMP=ON ..
3. make -j 4

Notice:
I don't know why, currently the code only build with g++-8 (!?)

When using g++ 7.2.0 (default in Ubuntu 18.04), the fails to build with an internal compiler error !
see readme_build_error
