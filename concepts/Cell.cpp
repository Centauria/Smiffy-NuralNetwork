#include "Cell.h"

Cell::Cell(){
	this->b=0.0;
	this->phi=sigmoid;
}

Cell::Cell(Activator func){
	this->b=0.0;
	this->phi=func;
}

Cell::Cell(double b){
	this->b=b;
	this->phi=sigmoid;
}

Cell::Cell(Activator func,double b){
	this->b=b;
	this->phi=func;
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

void Cell::setPhi(Activator func){
	this->phi=func;
}

void Cell::setb(double b){
	this->b=b;
}

double Cell::getb(){
	return this->b;
}
