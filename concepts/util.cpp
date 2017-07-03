#include <iostream>
#include "util.h"

using std::cout;
using std::endl;

void showVector(vector<double> numbers){
	for(int i=0;i<numbers.size();i++){
		cout<<numbers.at(i)<<", ";
	}
	cout<<endl;
}
