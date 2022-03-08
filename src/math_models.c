#include "../include/math_models.h"

void gen_rand_walk(const float mu, const float C, const unsigned int n, float* t, float* results) {
    // Assume t is evenly spaced
    float sd = C*sqrt(t[1]-t[0]);
    results[0] = 0.f;
    for(int i=1; i<n; i++) {
        results[i] = mu*t[i] + gen_norm_dist_rn(0, sd);
    }
}