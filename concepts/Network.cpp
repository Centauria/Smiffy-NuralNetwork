#include <stdio.h>
#include "Network.h"
#include "util.h"

Network::Network(){
	
}

Network::~Network(){
	for(int i=0;i<this->layers.size();i++){
		delete this->layers.at(i);
		this->layers.at(i)=NULL;
	}
}

void Network::addLayer(Layer* layer){
	this->layers.push_back(layer);
}

Layer* Network::getLayer(int index){
	return this->layers.at(index);
}

void Network::update(){
	for(int i=0;i<this->layers.size();i++){
		this->layers.at(i)->update();
	}
}

int Network::size(){
	return this->layers.size();
}

void Network::show(){
	for(int i=0;i<this->size();i++){
		showVector(this->getLayer(i)->output());
	}
}

void Network::learn(vector<double> d){
	this->update();
	Layer* lastlayer=this->layers.back();
	vector<double> out=lastlayer->output();
	vector<double> delta=(d-out)*out*(ones(out.size())-out);
	for(int j=0;j<lastlayer->size();j++){
		Cell* cell=lastlayer->getCell(j);
		for(int i=0;i<cell->size();i++){
			cell->setW(i,cell->getW(i)+ITA*delta.at(j)*cell->getAncestor(i)->output);
		}
	}
	Layer* hiddenlayer=this->layers.at(this->layers.size()-2);
	out=hiddenlayer->output();
	vector<double> delta2=out*(ones(out.size())-out);
	for(int j=0;j<hiddenlayer->size();j++){
		double sum=0;
		for(int k=0;k<lastlayer->size();k++){
			sum+=delta.at(k)*lastlayer->getCell(k)->getW(j);
		}
		delta2[j]*=sum;
	}
	for(int j=0;j<hiddenlayer->size();j++){
		Cell* cell=hiddenlayer->getCell(j);
		for(int i=0;i<cell->size();i++){
			cell->setW(i,cell->getW(i)+ITA*delta2.at(j)*cell->getAncestor(i)->output);
		}
	}
}
