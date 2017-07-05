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
	cout<<"23333"<<endl;
}

int main(int argc, char** argv) {
	char input = 0;
	Network net;
	net.addLayer(new Layer(2));
	net.addLayer(new Layer(40));
	net.addLayer(new Layer(2));
	net.getLayer(0)->connect(net.getLayer(1));
	net.getLayer(1)->connect(net.getLayer(2));
	net.update();
	DataInput di("0-good.txt"),bi("1-good.txt");
	vector<double> d0{1,0};
	vector<double> d1{0,1};
	
	cout << "Hello! I'm Smiffy." << endl;
	cout << "Press q to quit, press a to execute foo." << endl;	
	while(1) {
		cout << ">> ";
		cin >> input;
		if(input == 'a') {
			Foo();
		} else if(input == 'g') {
			net.show();
		} else if(input == 'l') {
			net.getLayer(0)->clean();
			di.plug(net.getLayer(0));
			cout<<"learn 0..."<<endl;
			while(di.csvAvailable()){
				di.next();
				net.learn(d0);
			}
		} else if(input == 'k') {
			net.getLayer(0)->clean();
			bi.plug(net.getLayer(0));
			bi.next();
			cout<<"learn 1..."<<endl;
			while(bi.csvAvailable()){
				bi.next();
				net.learn(d1);
			}
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
