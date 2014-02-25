#include<sting>




class Mot {
	private :
	string value;
	int nbrOccur;
	public :
	
	Mot(string value , int nbrOccur = 0);
	
	string getValue();
	
	void setValue(string value);
	
	int getNbrOccur();
    //fff
	void setNbrOccur(int nbrOccur);


	bool operator<(const Mot & mot){
		return ( this->nbrOccur < mot.nbrOccur );
	}
}



//class Mot .
//class Liste de mots : contient map de clés asociées a des vecteurs de strings
//Lecture FIle     Ecriture Dans FIle
//AfficherMotCompleted

//fonction qui permet d'afficher les occurences d'un mot a chaque saisie + met a jour le fichier :)
