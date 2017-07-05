#ifndef __LAYER__
#define __LAYER__

#include <vector>
#include "Cell.h"

using std::vector;

class Layer{
public:
	Layer();
	Layer(int);
	Layer(int,Activator);
	~Layer();
	
	void addCell(Cell*);
	Cell* getCell(int);
	void update();
	vector<double> output();
	int size();
	void plug(Layer*);
	void connect(Layer*);
	void setb(vector<double>);
	vector<double> getb();
	double getb(int);
protected:
	vector<Cell*> cells;
};
#endif
