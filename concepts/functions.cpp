#include <vector>
#include "functions.h"

using std::vector;

double sigmoid(vector<double> args,double in){
	return 1.0/(1.0+exp(-args.front()*in));
}

double one(vector<double> args,double in){
	return 1.0;
}

double zero(vector<double> args,double in){
	return 0.0;
}
