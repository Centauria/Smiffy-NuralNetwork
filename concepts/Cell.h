#ifndef __CELL__
#define __CELL__

#include <vector>
#include "functions.h"

using std::vector;

class Cell{
public:
	Cell();
	Cell(Activator);
	
	double output;
	
	void update();
	void addAncestor(Cell*,double);
	void setPhi(Activator);
private:
	vector<Cell*> ancestors;
	vector<double> weights;
	double b;
	Activator phi;
};
#endif
