#include "../include/distributions.h"

void gen_norm_dist_pdf(double mean, double sd, int min, int max, int n_vals, double* results)
{
    double step_size = 0.1;
    double curr_val = min;

    for(int i=0; i<n_vals; i++)
    {
        *results = 1/(sd*sqrt(2*M_PI))*exp(-0.5*pow((curr_val-mean)/sd,2));
        curr_val += step_size;
        results++;
    }
}

double gen_norm_dist_rn(double mean, double sd)
{
    static bool haveSpare = false;
    static double spare;

    if(haveSpare)
    {
        haveSpare = false;
        return spare;
    }
    haveSpare = true;

    double u1, u2;
    do
    {
        u1 = rand()/((double)RAND_MAX);
        u2 = rand()/((double)RAND_MAX);
    }while(u1 < DBL_EPSILON);

    double mag = sd * sqrt(-2.0 * log(u1));
    spare = mag * sin(2*M_PI * u2) + mean;

    return mag * cos(2*M_PI * u2) + mean;
}
