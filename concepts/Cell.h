#ifndef __CELL__
#define __CELL__

#include <vector>
#include "functions.h"

using std::vector;

class Cell{
public:
	Cell();
	Cell(Activator);
	Cell(double);
	Cell(Activator,double);
	
	double output;
	
	void update();
	void addAncestor(Cell*,double);
	void setPhi(Activator);
	void setb(double);
	double getb();
private:
	vector<Cell*> ancestors;
	vector<double> weights;
	double b;
	Activator phi;
};
#endif
