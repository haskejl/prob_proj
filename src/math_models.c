#include "../include/math_models.h"

void gen_rand_walk(const float mu, const float C, const unsigned int n, float* t, float* results) {
    // Assume t is evenly spaced
    float sd = C*sqrt(t[1]-t[0]);
    results[0] = 0.f;
    for(int i=1; i<n; i++) {
        results[i] = mu*t[i] + gen_norm_dist_rn(0, sd);
    }
}

void gen_bs_process(const float s0, const float mu, const float sigma, const unsigned int n, float* t, float*results) {
    // Assume t is evenly spaced
    float sd = sqrt(t[1]-t[0]);
    float dt = t[1]-t[0];
    results[0] = s0;
    for(int i=1; i<n; i++) {
        results[i] = results[i-1]*(1 + mu*dt+sigma*gen_norm_dist_rn(0, sd));
    }
}

float bs_call_price(float S, float E, float sigma, float r, float T, float t) {
    t = T-t;
    float d1 = (log(S/E) + (r * pow(sigma,2)/2)*t)/(sigma*sqrt(t));
    float d2 = d1-sigma*sqrt(t);
    return S*std_norm_dist_phif(d1,12)-E*pow(M_E, (-r*t))*std_norm_dist_phif(d2,12);
}