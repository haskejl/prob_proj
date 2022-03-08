#ifndef MATH_INTERNAL_H
#define MATH_INTERNAL_H

#define _USE_MATH_DEFINES
#include <float.h>
#include <math.h>

#include "common.h"

void gen_evenly_spaced_array(const float begin, const float end, const unsigned int n, float* results);

#endif