#ifndef MOT
#define MOT 1
#include <string>
using namespace std;

class Mot {
private:
	string value;
	int nbrOccur;

public:	
	Mot(string value , int nbrOccur = 0);
	string getValue();
	void setValue(string value);
	int getNbrOccur() const;
	void setNbrOccur(int nbrOccur);
	
	bool operator<(const Mot& mot) const{
		return nbrOccur < mot.getNbrOccur();
	}
};
#endif