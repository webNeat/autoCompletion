#include <map>
#include <vector>
#include <string>
#include "mot.hpp"
using namespace std;

class Dictionary {
private:
	map<string, vector<Mot> > words;
	int k;
public:
	Dictionary(int size) : k(size) {}
	void addWord(string& word);
	
	void save(string& fileName);
	void load(string& fileName);

	void affichageMotCompleted(string& monBoutDeChaine);
};