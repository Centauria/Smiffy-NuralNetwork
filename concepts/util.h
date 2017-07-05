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
vector<double> operator+(const vector<double>& v1, const vector<double>& v2);
vector<double> operator-(const vector<double>& v1, const vector<double>& v2);
vector<double> operator*(const vector<double>& v1, const vector<double>& v2);
vector<double> operator/(const vector<double>& v1, const vector<double>& v2);
vector<double> nums(double num,int n);
vector<double> ones(int n);
vector<double> zeros(int n);
#endif
