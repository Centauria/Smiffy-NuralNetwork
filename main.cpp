#include <iostream>
#include "concepts\Cell.h"
#include "concepts\Layer.h"
#include "concepts\util.h"
using std::cin;
using std::cout;
using std::endl;

void Foo() {
	Layer* layer0=new Layer(4,one);
	Layer* layer1=new Layer(4,sigmoid);
	Layer* layer2=new Layer(4,sigmoid);
	Layer* layer3=new Layer(2,sigmoid);
	layer0->getCell(1)->setPhi(zero);
	for(int i=0;i<4;i++){
		layer1->getCell(i)->addAncestor(layer0->getCell(i),1);
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			layer2->getCell(i)->addAncestor(layer1->getCell(j),randn01());
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<4;j++){
			layer3->getCell(i)->addAncestor(layer2->getCell(j),randn01());
		}
	}
	layer0->update();
	layer1->update();
	layer2->update();
	layer3->update();
	showVector(layer0->output());
	showVector(layer1->output());
	showVector(layer2->output());
	showVector(layer3->output());
	delete layer0,layer1,layer2,layer3;
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
