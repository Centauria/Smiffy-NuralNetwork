#include <stdio.h>
#include "Layer.h"

Layer::Layer(){
	
}

Layer::Layer(int n){
	for(int i=0;i<n;i++){
		this->cells.push_back(new Cell());
	}
}

Layer::Layer(int n,Activator func){
	for(int i=0;i<n;i++){
		this->cells.push_back(new Cell(func));
	}
}

Layer::~Layer(){
	for(int i=0;i<this->cells.size();i++){
		delete this->cells.at(i);
		this->cells.at(i)=NULL;
	}
}

void Layer::addCell(Cell* c){
	this->cells.push_back(c);
}

Cell* Layer::getCell(int index){
	return this->cells.at(index);
}

void Layer::update(){
	for(int i=0;i<this->cells.size();i++){
		this->cells.at(i)->update();
	}
}

vector<double> Layer::output(){
	vector<double> out;
	for(int i=0;i<this->cells.size();i++){
		out.push_back(this->cells.at(i)->output);
	}
	return out;
}

int Layer::size(){
	return this->cells.size();
}
