#include "../include/distributions.h"

void gen_norm_dist_pdf(double mean, double sd, double* results)
{
    int min = -5;
    int max = 5;

    int num_vals = 1000;

    double step_size = 0.01;
    double curr_val = min;

    for(int i=0; i<num_vals; i++)
    {
        *results = 1/(sd*sqrt(2*M_PI))*exp(-0.5*pow((curr_val-mean)/sd,2));
        curr_val += step_size;
        results++;
    }
}