#include "DataInput.h"
#include "..\concepts\util.h"

DataInput::DataInput(){
	
}

DataInput::DataInput(int n):Layer(n,same){
	
}

DataInput::DataInput(string filename){
	this->opencsv(filename);
}

DataInput::~DataInput(){
	csv.close();
}

void DataInput::opencsv(string filename){
	if(csv.is_open()) csv.close();
	this->csv.open(filename);
	string line;
	vector<string> types;
	if(this->csvAvailable()){
		string comma(",");
		getline(csv,line);
		types=split(line,comma);
	}
	else throw "bad csv";
	this->cells.clear();
	for(string s:types){
		this->addCell(new Cell(same));
	}
}

bool DataInput::csvAvailable(){
	return csv.is_open()&&csv.good()&&!csv.eof();
}

void DataInput::next(){
	if(this->csvAvailable()){
		string line;
		getline(csv,line);
		this->setb(readVector(line));
	}
	this->update();
}
