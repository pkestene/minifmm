#pragma once

#include <float.h>
#include <complex>
#include <cmath>

using TYPE=float; 
using TYPE_COMPLEX=std::complex<float>;
#define TYPE_MAX FLT_MAX
#define TYPE_ONE 1.0f
#define TYPE_EPS 5.0e-8f
#define TYPE_SQRT(x) sqrtf(x)
#define TYPE_ZERO 0.0f
#define TYPE_TWO 2.0f
#define TYPE_SIN(x) std::sin(x)
#define TYPE_COS(x) std::cos(x)
#define TYPE_ATAN2(x,y) std::atan2(x,y)
#define TYPE_ACOS(x) std::acos(x)
#define TYPE_CPOW(x,y) std::pow(x,y)
#define TYPE_CEXP(x) std::exp(x)
#define TYPE_ABS(x) std::abs(x)
#define TYPE_CONJ(x) std::conj(x)

