#include "../include/math_internal.h"

void gen_evenly_spaced_array(const float begin, const float end, const unsigned int n, float* results) {
    float inc = (end-begin)/n;
    results[0] = begin;
    for(unsigned int i=1; i<n; i++) {
		results[i] = inc+results[i-1];
	}
}

unsigned int factorialuint(const unsigned int x) {
  if(x == 0 || x == 1) {
    return 1;
  }
  else {
    return x*factorialuint(x-1);
  }
}

int factorialint(const int x) {
  if(x == 0 || x == 1) {
    return 1;
  }
  else {
    return x*factorialint(x-1);
  }
}