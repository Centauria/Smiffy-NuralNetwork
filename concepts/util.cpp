#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include "util.h"

using namespace std;

void showVector(vector<double> numbers){
	cout<<"{ ";
	for(int i=0;i<numbers.size();i++){
		cout<<numbers.at(i)<<", ";
	}
	cout<<" }"<<endl;
}

double randn01(){
	static double V1, V2, S;
    static int phase = 0;
    double X;
    if ( phase == 0 ) {
	    do {
		    double U1 = (double)rand() / RAND_MAX;
		    double U2 = (double)rand() / RAND_MAX;
		    V1 = 2 * U1 - 1;
		    V2 = 2 * U2 - 1;
		    S = V1 * V1 + V2 * V2;
		} while(S >= 1 || S == 0);
	    X = V1 * sqrt(-2 * log(S) / S);
	} else
	    X = V2 * sqrt(-2 * log(S) / S);
    phase = 1 - phase;
    return X;
}

double randn(double avg,double var){
	double r=randn01();
	return r*var+avg;
}

vector<string> split(string &s,string &delim){
	vector<string> elems;
	size_t pos=0;
	size_t len=s.length();
	size_t delim_len=delim.length();
	if(delim_len==0){
		elems.push_back(s);
		return elems;
	}
	while(pos<len){
		int find_pos=s.find(delim,pos);
		if(find_pos<0){
			elems.push_back(s.substr(pos,len-pos));
			break;
		}
		elems.push_back(s.substr(pos,find_pos-pos));
		pos=find_pos+delim_len;
	}
	return elems;
}

vector<double> readVector(string s){
	string comma(",");
	vector<string> strs=split(s,comma);
	vector<double> res;
	stringstream ss;
	double num;
	for(string d:strs){
		ss<<d;
		ss>>num;
		ss.clear();
		res.push_back(num);
	}
	return res;
}
