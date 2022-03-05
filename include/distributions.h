#ifndef DISTRIBUTIONS_H
#define DISTRIBUTIONS_H

#define _USE_MATH_DEFINES
#include <float.h>
#include <math.h>

#include "common.h"

void gen_norm_dist_pdf(double mean, double sd, int min, int max, int n_vals, double* results);

double gen_norm_dist_rn(double mean, double sd);

#endif
