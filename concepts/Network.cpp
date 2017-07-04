#include <stdio.h>
#include "Network.h"

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
