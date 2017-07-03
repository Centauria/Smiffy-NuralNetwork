#ifndef __LAYER__
#define __LAYER__

#include <vector>
#include "Cell.h"

using std::vector;

class Layer{
public:
	Layer();
	Layer(int,Activator);
	~Layer();
	
	void addCell(Cell*);
	Cell* getCell(int);
	void update();
	vector<double> output();
private:
	vector<Cell*> cells;
};
#endif
