#include "mot.hpp"

string Mot::getValue(){
	return value;	
}

Mot::Mot(string value , int nbrOccur){
	this->value = value;
	this->nbrOccur = nbrOccur;
}

void Mot::setValue(string value){
	this->value = value;
}

int Mot::getNbrOccur() const {
	return nbrOccur;
}

void Mot::setNbrOccur(int nbrOccur){
	this->nbrOccur = nbrOccur;
}