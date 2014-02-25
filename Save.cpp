#include <vector>
#include <iostream>
#include <fstream>
#include "Mot.hpp"

using namespace std;

void Save(string fileName , map< string , vector<Mot> > vect ){
	
	//
	ofstream myFile;
	map< string , vector<Mot> >::iterator it1;
	//
	myFile.open(fileName);
	//
	for(it1 = vect.begin();it1 != vect.end();it1++)
	{
		for( vector<Mot>iterator::it2 = it1->second.begin() ; it2 != it1.end() ; it2++ )
		{
			myFile << it2->getValue()  << " " << it2->getNbrOccur() << endl;
		}
	}
	
	//
	
	myFile.close(); 
}



int main(){
	
	return 0;
}
