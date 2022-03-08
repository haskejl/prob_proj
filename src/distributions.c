#include "../include/distributions.h"

void gen_norm_dist_pdf(const float mean, const float sd, const int min, const int max, const int n_vals, float* results)
{
    float step_size = (float)(max-min)/n_vals;
    float curr_step = min;

    for(int i=0; i<n_vals; i++)
    {
        results[i] = 1/(sd*sqrt(2*M_PI))*exp(-0.5*pow((curr_step-mean)/sd,2));
        curr_step += step_size;
    }
}

float gen_norm_dist_rn(const float mean, const float sd)
{
    static bool haveSpare = false;
    static float spare;

    if(haveSpare)
    {
        haveSpare = false;
        return spare;
    }
    haveSpare = true;

    float u1, u2;
    do
    {
        u1 = rand()/((float)RAND_MAX);
        u2 = rand()/((float)RAND_MAX);
    }while(u1 < DBL_EPSILON);

    float mag = sd * sqrt(-2.0 * log(u1));
    spare = mag * sin(2*M_PI * u2) + mean;

    return mag * cos(2*M_PI * u2) + mean;
}
