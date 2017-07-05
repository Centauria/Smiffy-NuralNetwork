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

void Layer::plug(Layer* layer){
	if(this->cells.size()==layer->cells.size()){
		for(int i=0;i<layer->cells.size();i++){
			layer->getCell(i)->addAncestor(this->getCell(i),1.0);
		}
	}
	else{
		throw "Layer dimension mismatch.";
	}
}

void Layer::unplug(Layer* layer){
	if(this->cells.size()==layer->cells.size()){
		for(int i=0;i<layer->cells.size();i++){
			layer->getCell(i)->rmAncestor(this->getCell(i));
		}
	}
	else{
		throw "Layer dimension mismatch.";
	}
}

void Layer::connect(Layer* layer){
	for(int i=0;i<layer->cells.size();i++){
		for(int j=0;j<this->cells.size();j++){
			layer->getCell(i)->addAncestor(this->getCell(j),0.0);
		}
	}
}

void Layer::clean(){
	for(int j=0;j<this->cells.size();j++){
		this->getCell(j)->clean();
	}
}

void Layer::setb(vector<double> b){
	int asize=this->cells.size();
	int bsize=b.size();
	int size;
	if(asize<bsize) size=asize;
	else size=bsize;
	for(int i=0;i<size;i++){
		this->cells.at(i)->setb(b.at(i));
	}
}

vector<double> Layer::getb(){
	vector<double> res;
	for(int i=0;i<this->cells.size();i++){
		res.push_back(this->cells.at(i)->getb());
	}
	return res;
}

double Layer::getb(int index){
	return this->cells.at(index)->getb();
}
