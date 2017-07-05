#include <vector>
#include "functions.h"

using std::vector;

double sigmoid(vector<double> args,double in){
	return 1.0/(1.0+exp(-args.front()*in));
}

double d_sigmoid(vector<double> args,double in){
	double yj=sigmoid(args,in);
	return args.front()*yj*(1-yj);
}
double one(vector<double> args,double in){
	return 1.0;
}

double zero(vector<double> args,double in){
	return 0.0;
}

double ReLU(vector<double> args,double in){
	if(in>0.0) return in;
	else return 0.0;
}

double d_ReLU(vector<double> args,double in){
	if(in>0.0) return 1.0;
	else return 0.0;
}

double same(vector<double> args,double in){
	return in;
}
