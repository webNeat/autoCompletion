#include <iostream>
#include <cstdlib>
#include "dictionary.hpp"
using namespace std;

int main(){
    Dictionary dictionnaire(1);
    char a;
	string text,
		lexem;

    dictionnaire.load("words.txt");
    system("/bin/stty raw");
    while((cin >> noskipws >> a) && a != '*'){
        text = text + a;
        if(a == ' ')
            lexem = "";
        else
            lexem = lexem + a;
        system("clear");
        cout << text;
        dictionnaire.affichageMotCompleted(lexem);
    }
    system ("/bin/stty cooked");
    cout << endl;
    return 0;
}