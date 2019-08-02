Work in progress:

 - Dual-tree traversal parallelised with Kokkos
 - Currently only works with single-precision types and num\_terms = 4

## Old regular Makefile information

Example of build command line for "regular" makefile:
make KOKKOS_PATH=/home/pkestene/kokkos-tutorial/kokkos NVCC_WRAPPER=/home/pkestene/kokkos-tutorial/kokkos/bin/nvcc_wrapper KOKKOS_DEVICES=Cuda,OpenMP KOKKOS_ARCH=Kepler30 TARGET=GPU 

## New Cmake-based build system

Use cmake to perform an out-of-source build.

Very important: you need to export environment variable CXX to set compiler for building a Kokkos application for GPU target:

``` bash
export CXX=${PATH_TO_MINIFMM_TOP_LEVEL}/external/kokkos/bin/nvcc_wrapper

```


Example of build (cmake command line):

``` bash
mkdir build; cd build
cmake -DCMAKE_BUILD_TYPE=Release -DKOKKOS_ENABLE_CUDA:BOOL=ON -DKOKKOS_ENABLE_CUDA_LAMBDA:BOOL=ON -DKOKKOS_ENABLE_OPENMP:BOOL=ON -DKOKKOS_ENABLE_CUDA_RELOCATABLE_DEVICE_CODE:BOOL=ON -DUSE_FLOAT:BOOL=ON ..
make -j 4
```

You should get an executable called fmm_kokkos_gpu.

``` bash
# example run on a Maxwell50 GPU
pkestene@mdlslx79:/home/pkestene/silicosmic/fmm/git/minifmm_pk/kokkos-gpu/build $ ./fmm_kokkos_gpu
-------------- FMM ARGS --------------
no. particles       100000 (10^5)
bin size            200
no. terms           10
theta               0.50
no. samples         100
--------------------------------------
num nodes = 1897
Built tree structure in 0.007670s
starting computation
--------------------
Performed upward tree pass in 0.094599s
GPU elapsed time = 1.174309
nm = 189700
Performed dual tree traversal in 1.186334s
Performed downward tree pass in 0.121864s
--------------------
Total elapsed FMM time = 1.403097
m2l calls = 0
--------------------
force err.     = 3.463025e-04
potential err. = 1.524264e-05
```

### Notice about cmake build

You will need to adapt some CMAKE variables to your own platform :
- KOKKOS_ARCH must match your target GPU architecture: valid values are Kepler,Kepler30,Kepler32,Kepler35,Kepler37,Maxwell,Maxwell50,Maxwell52,Maxwell53,Pascal60,Pascal61,Volta70,Volta72,Turing75
- 

