/*
Exercice 3 : Création d’une pile
-----------------------------------------------------------------------------------
Une pile (« stack » en anglais) est une structure de données basée sur le principe « Dernier arrivé, premier sorti », ou LIFO (Last In, First Out).
1. Créer une classe PileChar qui a les variables max (La taille maximale 50 par défaut), sommet , et pile (pointeur sur les caractères)
2. Créer les constructeurs:
	a. le premier en utilisant le constructeur par défaut qui initialise la taille maximale
	b. le deuxième en utilisant le constructeur d'initialisation pour initialiser les variables max et sommet 0 par défaut et allocation en utilisant new char avec la taille fournie
	c. le troisième en utilisant le constructeur de copie
3. Créer le destructeur qui libérent les valeurs de la pile
4. Définit les méthodes publiques suivantes;
	a. Une méthode taille() qui donne comme résultat un entier positif qui est le nombre maximum de caractères qu’il sera possible d’y mettre
	b. Une méthode compter() qui donne comme résultat un entier positif qui est le nombre d’éléments actuellement présents sur la pile
	c. Une méthode afficher() qui affiche entre des ’[’ et ’]’ les éléments actuellement présents dans la pile.
	d. Une méthode empiler() qui prend un caractère en paramètre et le place sur le dessus de la pile
	e. Une méthode depiler() qui enlève le caractère du dessus de la pile et le renvoi en valeur de retour
5. Définir l’opérateur = (il faut supprimer la pile précédente, affecter les nouvelles valeurs de max et sommet, allocation de la pile, et enfin l’insertion des valeurs)
*/
#include <iostream>

using namespace std;

// 1. Créer une classe PileChar qui a les variables max (La taille maximale 50 par défaut), sommet , et pile (pointeur sur les caractères)
class PileChar {
private:
	int max;
	int sommet;
	char* pile;
public:
	// 2. Créer les constructeurs:	a.le premier en utilisant le constructeur par défaut qui initialise la taille maximale
	PileChar() {
		max = 50;
		sommet = 0;
		pile = new char[max];
	}
	// 2. Créer les constructeurs :	b.le deuxième en utilisant le constructeur d'initialisation pour initialiser les variables max et sommet 0 par défaut et allocation en utilisant new char avec la taille fournie
	PileChar(int max) {
		this->max = max;
		this->sommet = 0;
		this->pile = new char[max];
	}
	// 2. Créer les constructeurs:	c.le troisième en utilisant le constructeur de copie
	PileChar(const PileChar& p) {
		this->max = p.max;
		this->sommet = p.sommet;
		this->pile = new char[max];
		for (int i = 0; i < this->sommet; i++) {
			this->pile[i] = p.pile[i];
		}
	}
	// 3. Créer le destructeur qui libérent les valeurs de la pile
	~PileChar() {
		delete[] this->pile;
	}
	// 4. Définit les méthodes publiques suivantes; a.Une méthode taille() qui donne comme résultat un entier positif qui est le nombre maximum de caractères qu’il sera possible d’y mettre
	int taille() {
		return this->max;
	}
	// 4. Définit les méthodes publiques suivantes; b. Une méthode compter() qui donne comme résultat un entier positif qui est le nombre d’éléments actuellement présents sur la pile
	int compter() {
		return this->sommet;
	}
	// 4. Définit les méthodes publiques suivantes; c. Une méthode afficher() qui affiche entre des ’[’ et ’]’ les éléments actuellement présents dans la pile.
	void afficher() {
		cout << '[';
		for (int i = 0; i < this->sommet; i++) {
			cout << this->pile[i];
		}
		cout << ']';
	}
	// 4. Définit les méthodes publiques suivantes; d. Une méthode empiler() qui prend un caractère en paramètre et le place sur le dessus de la pile
	void empiler(char c) {
		if (this->sommet < this->max) {
			this->pile[this->sommet] = c;
			this->sommet++;
		}else {
			cout << "La pile est pleine" << endl;
		}
	}
	// 4. Définit les méthodes publiques suivantes; e. Une méthode depiler() qui enlève le caractère du dessus de la pile et le renvoi en valeur de retour
	char depiler() {
		if (this->sommet > 0) {
			return this->pile[this->sommet--];
		}else {
			cout << "La pile est vide"<<endl;
			return ' ';
		}
	}
	// 5. Définir l’opérateur = (il faut supprimer la pile précédente, affecter les nouvelles valeurs de max et sommet, allocation de la pile, et enfin l’insertion des valeurs)
	void operator=(const PileChar& p) {
		delete[] this->pile;
		this->max = p.max;
		this->sommet = p.sommet;
		this->pile = new char[this->max];
		for (int i = 0; i < this->sommet; i++) {
			this->pile[i] = p.pile[i];
		}
	}
};
/*
int main() {
	PileChar p1(10);
	p1.empiler('s');
	p1.empiler('o');
	p1.empiler('u');
	p1.empiler('f');
	PileChar p2 = p1;
	cout << "p2: ";
	p2.afficher();
	int taille = p1.compter();
	cout <<endl<< "p1: ";
	p1.afficher();
	// Pour vider la pile
	for (int i = 0; i < taille; i++) {
		p1.depiler();
	}

	cout <<endl<< "Apres:"<<endl<<"p1: ";
	p1.afficher();
	cout <<endl<< "p2: ";
	p2.afficher();

	PileChar p3(60);
	p3.empiler('p');
	p3.empiler('o');
	p3.empiler('o');
	cout << endl << "p3: ";
	p3.afficher();
	PileChar p4;
	cout << endl << "p4: ";
	p4.afficher();
	p4 = p3;
	cout << endl <<"Apres affactation: "<<endl << "p4: ";
	p4.afficher();


	return 0;
}*/