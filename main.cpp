#include <iostream>
#include "concepts\Cell.h"
#include "concepts\Layer.h"
#include "concepts\Network.h"
#include "concepts\util.h"
#include "interface\DataInput.h"
using std::cin;
using std::cout;
using std::endl;

void Foo() {
	Network* net=new Network();
	net->addLayer(new Layer(2,same));
	net->addLayer(new Layer(40));
	net->addLayer(new Layer(2));
	net->getLayer(0)->connect(net->getLayer(1));
	net->getLayer(1)->connect(net->getLayer(2));
	net->update();
	for(int i=0;i<net->size();i++){
		showVector(net->getLayer(i)->output());
	}
	DataInput di("0-good.txt");
	di.plug(net->getLayer(0));
	di.next();
	net->update();
	for(int i=0;i<net->size();i++){
		showVector(net->getLayer(i)->output());
	}
	di.next();
	net->update();
	for(int i=0;i<net->size();i++){
		showVector(net->getLayer(i)->output());
	}
	delete net;
}

int main(int argc, char** argv) {
	char input = 0;
	
	cout << "Hello! I'm Smiffy." << endl;
	cout << "Press q to quit, press a to execute foo." << endl;	
	while(1) {
		cout << ">> ";
		cin >> input;
		if(input == 'a') {
			Foo();
		} else if(input == 'q') {
			break;
		} else if(input == 'c') {
			cout << randn(0,1) <<endl;
		} else if(input != '\n') {
			cout << "Unknown command '" << input << "'! Ignoring...\n";
		}
	}

	return 0;
}
