#include "Cell.h"

Cell::Cell(){
	this->b=0.0;
	this->phi=sigmoid;
	this->update();
}

Cell::Cell(Activator func){
	this->b=0.0;
	this->phi=func;
	this->update();
}

Cell::Cell(double b){
	this->b=b;
	this->phi=sigmoid;
	this->update();
}

Cell::Cell(Activator func,double b){
	this->b=b;
	this->phi=func;
	this->update();
}

void Cell::update(){
	double res=0;
	for(int i=0;i<this->ancestors.size();i++){
		res+=this->weights.at(i)*this->ancestors.at(i)->output;
	}
	vector<double> args;
	args.push_back(1.0);
	this->output=phi(args,res+b);
}

void Cell::addAncestor(Cell* c,double w){
	ancestors.push_back(c);
	weights.push_back(w);
}

void Cell::rmAncestor(Cell* c){
	for(vector<Cell*>::iterator it=this->ancestors.begin();it!=this->ancestors.end();it++){
		if(*it==c){
			this->ancestors.erase(it);
			break;
		}
	}
}

void Cell::clean(){
	this->ancestors.clear();
	this->weights.clear();
}


void Cell::setPhi(Activator func){
	this->phi=func;
}

void Cell::setb(double b){
	this->b=b;
}

double Cell::getb(){
	return this->b;
}

void Cell::setW(int index,double w){
	this->weights[index]=w;
}

double Cell::getW(int index){
	return this->weights.at(index);
}

vector<double> Cell::getW(){
	return this->weights;
}

Cell* Cell::getAncestor(int index){
	return this->ancestors.at(index);
}

int Cell::size(){
	return this->weights.size();
}
