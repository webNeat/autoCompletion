#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
	Dictionary dictionnaire(5);
	dictonnaire.load('MyFile.txt');
	char a;
	string Text;
	string Lexem;
	while((cin >>noskipws>> a) && a != '\n'){
		Text = Text + a;
		if(a != ' '){Lexem = "";}
		Lexem = Lexem + a;
		dictonnaire.affichageMotCompleted(Lexem);
	}
	
	cout << endl << str;
}
