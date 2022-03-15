#ifndef DISTRIBUTIONS_H
#define DISTRIBUTIONS_H

#define _USE_MATH_DEFINES
#include <float.h>
#include <math.h>

#include "common.h"
#include "math_internal.h"

void gen_norm_dist_pdf(const float mean, const float sd, const int min, const int max, const int n_vals, float* results);
float std_norm_dist_phif(const float x, const int n_iters);
float gen_norm_dist_rn(const float mean, const float sd);

#endif
