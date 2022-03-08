#ifndef MATH_MODELS_H
#define MATH_MODELS_H

#define _USE_MATH_DEFINES
#include <float.h>
#include <math.h>

#include "common.h"
#include "distributions.h"
#include "math_internal.h"

void gen_rand_walk(const float mu, const float C, const unsigned int n, float* t, float* results);

#endif