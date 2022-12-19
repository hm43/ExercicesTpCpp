/*
Exercice 4: L’Heritage simple
-------------------------------------------------------------------------------------
1. Créer une classe personnel comprenant 3 données membres (nom, position, salaire),un
constructeur initialisant les données membres et une fonction affiche_personnel qui
affiche les informations sur le personnel.

2. Créer une classe patron dérivant publiquement de la classe personnel et ayant 2
données membres (bonus_annuel, marque de voiture de fonction) , un constructeur
initialisant les données membres et une fonction affiche_patron qui affiche les
informations sur le patron (entant que membre du personnel et patron). Créer un
programme permettant de tester ces classes.
*/
#include <iostream>
#include <string>

using namespace std;
// 1. Créer une classe personnel comprenant 3 données membres (nom, position, salaire),un constructeur initialisant les données membres et une fonction affiche_personnel qui affiche les informations sur le personnel.
class Personnel {
	string nom;
	string position;
	int salaire;
public:
	Personnel(string nom, string position, int salaire) {
		this->nom = nom;
		this->position = position;
		this->salaire = salaire;
	};
	void affiche_personnel() {
		cout << "Nom : " << nom << endl;
		cout << "Position : " << position << endl;
		cout << "Salaire : " << salaire << endl;
	};
};
// 2. Créer une classe patron dérivant publiquement de la classe personnel et ayant 2 données membres(bonus_annuel, marque de voiture de fonction), un constructeur initialisant les données membres et une fonction affiche_patron qui affiche les informations sur le patron(entant que membre du personnel et patron).Créer un programme permettant de tester ces classes.
class Patron: public Personnel {
	int bonus_annuel;
	string marque_voiture;
public:
	Patron(string nom, string position, int salaire, int bonus_annuel, string marque_voiture) 
		:Personnel(nom, position, salaire), 
		bonus_annuel(bonus_annuel), marque_voiture(marque_voiture)
	{}
	void affiche_patron() {
		affiche_personnel(); //a ne pas oublier d'afficher le nom, position, et salaire
		cout << "Bonus annuel = " << bonus_annuel << endl;
		cout << "Marque de voiture = " << marque_voiture << endl;
	};
};


int main() {
	Personnel b("Gerald", "gérant", 1250);
	b.affiche_personnel();
	Patron a("Fallon", "PDG", 2000, 500, "BMW");
	a.affiche_patron();

	return 0;
}
