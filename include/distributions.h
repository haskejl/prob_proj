#ifndef DISTRIBUTIONS_H
#define DISTRIBUTIONS_H

#define _USE_MATH_DEFINES
#include <float.h>
#include <math.h>

#include "common.h"

void gen_norm_dist_pdf(float mean, float sd, int min, int max, int n_vals, float* results);

float gen_norm_dist_rn(float mean, float sd);

#endif
