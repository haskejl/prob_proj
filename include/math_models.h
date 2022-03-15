#ifndef MATH_MODELS_H
#define MATH_MODELS_H

#define _USE_MATH_DEFINES
#include <float.h>
#include <math.h>

#include "common.h"
#include "distributions.h"
#include "math_internal.h"

void gen_rand_walk(const float mu, const float C, const unsigned int n, float* t, float* results);
void gen_bs_process(const float s0, const float mu, const float sigma, const unsigned int n, float* t, float*results);
float bs_call_price(float S, float E, float sigma, float r, float T, float t);

#endif