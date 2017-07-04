#ifndef __NETWORK__
#define __NETWORK__

#include <vector>
#include "Layer.h"

using std::vector;

class Network{
public:
	Network();
	~Network();
	
	void addLayer(Layer*);
	Layer* getLayer(int);
	void update();
	int size();
private:
	vector<Layer*> layers;
};
#endif
