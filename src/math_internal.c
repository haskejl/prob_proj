#include "../include/math_internal.h"

void gen_evenly_spaced_array(const float begin, const float end, const unsigned int n, float* results) {
    float inc = (end-begin)/n;
    results[0] = begin;
    for(unsigned int i=1; i<n; i++) {
		results[i] = inc+results[i-1];
	}
}