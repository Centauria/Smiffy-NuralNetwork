#ifndef __DATAINPUT__
#define __DATAINPUT__

#include <vector>
#include <string>
#include <fstream>
#include "..\concepts\Layer.h"
#include "..\concepts\functions.h"

using namespace std;

class DataInput:public Layer{
public:
	DataInput();
	DataInput(int);
	DataInput(string);
	~DataInput();
	
	void opencsv(string);
	bool csvAvailable();
	void next();
private:
	ifstream csv;
};
#endif
