
#include "Mot.hpp"

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


int Mot::getNbrOccur(){
	return nbrOccur;
}	


void Mot::setNbrOccur(int nbrOccur){
	this->nbrOccur = nbrOccur;
}


bool Mot::operator<(const Mot & mot){
	return ( this->nbrOccur < mot.nbrOccur );
}
