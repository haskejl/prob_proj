#include "../include/math_internal.h"

void gen_evenly_spaced_array(unsigned int n, float begin, float end, float* results) {
    float inc = (end-begin)/n;
    results[0] = begin;
    for(unsigned int i=1; i<n; i++) {
		results[i] = inc+results[i-1];
	}
}