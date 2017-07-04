#ifndef __NETWORK__
#define __NETWORK__

#include <vector>

using std::vector;

class Network{
public:
	Network();
	~Network();
	
	void addLayer(Layer*);
	Layer* getLayer(int);
private:
	vector<Layer*> layers;
};
#endif
