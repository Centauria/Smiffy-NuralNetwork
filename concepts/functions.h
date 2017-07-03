#ifndef __FUNCTIONS__
#define __FUNCTIONS__

#include <math.h>
#include <vector>

using std::vector;

typedef double (*Activator)(vector<double>,double);

double sigmoid(vector<double> args,double in);
double one(vector<double> args,double in);
double zero(vector<double> args,double in);
#endif