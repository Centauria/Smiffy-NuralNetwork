#ifndef __UTIL__
#define __UTIL__

#include <vector>
#include <string>

using namespace std;

void showVector(vector<double> numbers);
double randn01();
double randn(double avg,double var);
vector<string> split(string &s,string &delim);
vector<double> readVector(string s);
#endif
