#include <fstream>
#include "dictionary.hpp"

void Dictionary::addWord(string& word){
	bool found = false;
	string key = word.substr(0, k);
	map< string, vector < Mot > >::iterator position = words.find(key);
	if(position != words.end()){
		vector<Mot>::iterator it = position->second.begin();
		while(it != position->second.end()){
			if(word.compare(it->getValue()) == 0){
				it->setNbrOccur(it->getNbrOccur() + 1);
				found = true;
				break;
			}
			it ++;
		}
	}
	if(! found){
		Mot nouveau(word);
		if(position != words.end()){
			position->second.push_back(nouveau);
		}else{
			vector<Mot> v;
			v.push_back(nouveau);
			words.insert(pair<string, vector<Mot> >(key, v));
		}
	}
}

void Dictionary::load(string& fileName){
	string value;
	int occ;
	ifstream input(fileName.c_str());
	while(! input.eof()){
		input >> value 
			>> occ;
		string key = value.substr(0, k);
		Mot nouveau(value, occ);
		map< string, vector < Mot > >::iterator position = words.find(key);
		if(position != words.end()){
			position->second.push_back(nouveau);
		}else{
			vector<Mot> v;
			v.push_back(nouveau);
			words.insert(pair<string, vector<Mot> >(key, v));	
		}
	}
	input.close();
}

void Dictionary::affichageMotCompleted(string& monBoutDeChaine){
	if(monBoutDeChaine.size() >= k){
		string key = monBoutDeChaine.substr(0, k);
		map< string, vector < Mot > >::iterator position = words.find(key);
		if(position != words.end()){
			
		}
	}
}


void Dictionary::Save(string & fileName){
	
	//
	ofstream myFile;
	map< string , vector<Mot> >::iterator it1;
	//
	myFile.open(fileName);
	//
	for(it1 = words.begin();it1 != words.end();it1++)
	{
		for( vector<Mot>iterator::it2 = it1->second.begin() ; it2 != it1.end() ; it2++ )
		{
			myFile << it2->getValue()  << " " << it2->getNbrOccur() << endl;
		}
	}
	myFile.close(); 
}
