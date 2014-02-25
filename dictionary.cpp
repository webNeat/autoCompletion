#include <fstream>
#include <iostream>
#include <algorithm>
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

void Dictionary::load(string fileName){
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
	int size = monBoutDeChaine.size();
	if(size >= k){
		string key = monBoutDeChaine.substr(0, k);
		map< string, vector < Mot > >::iterator position = words.find(key);
		if(position != words.end()){
			vector<Mot> propositions;
			vector<Mot>::iterator it = position->second.begin();
			while(it != position->second.end()){
				if(monBoutDeChaine.compare(it->getValue().substr(0,size)) == 0){
					propositions.push_back(*it);
				}
				it ++;
			}
			showSorted(propositions);
		}
	}
}

void Dictionary::showSorted(vector<Mot>& list){
	sort(list.begin(), list.end());
	vector<Mot>::iterator it = list.begin();
	cout << " [ ";
	cout << it->getValue();
	it ++;
	while(it != list.end()){
		cout << " | " << it->getValue();
		it ++;
	}
	cout << " ] ";
}

void Dictionary::save(string fileName){
	//
	ofstream myFile(fileName.c_str());
	map< string , vector<Mot> >::iterator it1;
	//
	for(it1 = words.begin();it1 != words.end();it1++){
		for(vector<Mot>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); it2 ++){
			myFile << it2->getValue();
			myFile << " " << it2->getNbrOccur() << endl;
		}
	}
	//
	myFile.close(); 
}

void Dictionary::print(){
	string text = "";
	map< string , vector<Mot> >::iterator it1;
	//
	for(it1 = words.begin();it1 != words.end();it1++){
		text += it1->first + ":\n";
		for(vector<Mot>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); it2 ++){
			text += "\t" + it2->getValue() + "\n";
		}
	}
	cout << text;
}