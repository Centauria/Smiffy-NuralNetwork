#ifndef __NETWORK__
#define __NETWORK__

#include <vector>
#include "Layer.h"

#define ITA 0.05

using std::vector;

class Network{
public:
	Network();
	~Network();
	
	void addLayer(Layer*);
	Layer* getLayer(int);
	void update();
	int size();
	void show();
	void learn(vector<double>);
private:
	vector<Layer*> layers;
};
#endif
