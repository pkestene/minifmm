#include "type.h"

#ifdef USE_FLOAT
TYPE_COMPLEX I(0.0f, 1.0f);
#else
TYPE_COMPLEX I(0.0, 1.0);
#endif
