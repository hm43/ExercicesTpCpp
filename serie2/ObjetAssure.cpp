/*
Exercice 5: L’Heritage multiple
-------------------------------------------------------------------------------------
a) Créer une classe objet assure comprenant :
– les données membres : montant (float), type (chaîne de caractères)
– un constructeur initialisant les données membres
– une fonction affiche qui affiche les informations sur l’objet assure
b) Créer une classe ordinateur dérivant publiquement de la classe objet assure et comprenant :
– les données membres : ram (int), hd(int), …
– un constructeur initialisant les données membres
– une fonction affiche qui affiche les informations sur l’ordinateur et qui appelle la fonction affiche de la classe objet assure
c) Créer une classe bagage dérivant publiquement de la classe objet assuré et comprenant :
– les données membres : type (chaîne de caractères), poids (float)
– un constructeur initialisant les données membres
– une fonction affiche affichant les informations sur le bagage et appelant la fonction affiche de la classe objet assure.
d) Créer une classe ordinateur portable dérivant publiquement des classes ordinateur et bagage et comprenant :
– les données membres poids (float) et epaisseur (float)
– un constructeur initialisant les données membres
– une fonction affiche qui affiche les informations sur l’ordinateur portable et qui appelle les fonctions affiche des classes bagage et ordinateur
e) Créer un programme qui crée un objet ordinateur portable et qui affiche les informations sur cet objet
Remarque : l’ordinateur portable doit bénéficier des 2 assurances, l’une contre le vol (en tant qu’ordinateur) et l’autre contre la perte (en tant que bagage).
*/
#include <iostream>
#include <string>

using namespace std;
// a) Créer une classe objet assure comprenant :
//– les données membres : montant(float), type(chaîne de caractères)
//– un constructeur initialisant les données membres
//– une fonction affiche qui affiche les informations sur l’objet assure
class Objetassure {
	float montant;
	string type;
public:
	Objetassure(float montant = 0.0, string type = "") {
		this->montant = montant;
		this->type = type;
	}
	void affiche() {
		cout << "montant: " << montant << endl;
		cout << "objet assure type: " << type << endl;
	}
};
// b) Créer une classe ordinateur dérivant publiquement de la classe objet assure et comprenant :
//– les données membres : ram(int), hd(int), …
//– un constructeur initialisant les données membres
//– une fonction affiche qui affiche les informations sur l’ordinateur et qui appelle la fonction affiche de la classe objet assure
class ordinateur :public Objetassure {
	int ram;
	int hd;
public:
	ordinateur(int ram = 0, int hd = 0, float mt = 0.0, string tp = ""): Objetassure(mt, tp) {
		this->ram = ram;
		this->hd = hd;
	}
	void affiche() {
		Objetassure::affiche();
		cout << "Mémoire type ram : " << ram << endl;
		cout << "Disque Dur: " << hd << endl;
	}
};
// c) Créer une classe bagage dérivant publiquement de la classe objet assuré et comprenant :
//– les données membres : type(chaîne de caractères), poids(float)
//– un constructeur initialisant les données membres
//– une fonction affiche affichant les informations sur le bagage et appelant la fonction affiche de la classe objet assure.
class bagage: public Objetassure {
	string type1;
	float poids;
public:
	bagage(string tp1 = "", float pd = 0, float mt = 0.0, string tp = ""): Objetassure(mt, tp) {
		type1 = tp1;
		poids = pd;
	}
	void affiche() {
		Objetassure::affiche();
		cout << "Type de bagage: " << type1 << endl;
		cout << "Poids du bagage: " << poids << endl;
	}
};
// d) Créer une classe ordinateur portable dérivant publiquement des classes ordinateur et bagage et comprenant :
//– les données membres poids(float) et epaisseur(float)
//– un constructeur initialisant les données membres
//– une fonction affiche qui affiche les informations sur l’ordinateur portable et qui appelle les fonctions affiche des classes bagage et ordinateur
class ordinateurportable: public ordinateur, public bagage {
	float poids1;
	float epaisseur;
public:
	ordinateurportable(float pd1 = 0.0, float epaiss = 0.0, int rm = 0, int hd = 0, string
		tp1 = "", float pd = 0.0): ordinateur(rm, hd), bagage(tp1, pd) {
		poids1 = pd1;
		epaisseur = epaiss;
	}
	void affiche() {
		ordinateur::affiche();
		bagage::affiche();
		cout << "ordinateur portable poids: " << poids1 << endl;
		cout << "epaisseur: " << epaisseur << endl;
	}
};


int main() {
	// e) Créer un programme qui crée un objet ordinateur portable et qui affiche les informations sur cet objet
	ordinateurportable orpor(10, 10, 256, 160, "a main", 50);
	orpor.affiche();
	return 0;
}
