/*
Exercice 3: Les variables static
-------------------------------------------------------------------------------------
1. Créer une classe Livre avec les attributs suivant: Auteur, titre, id
2. Créer une classe Etagère avec les attributs suivants: livre1, livre2, livre3, count qui calcule le nombre des livres dans la bibliothèque, il va nous aider à affecter des ids uniques pour chaque livre.
3. Créer les constructeurs par défaut et d'initialisation pour les deux classes.
4. Créer les setters public pour auteur et titre, ainsi que le setter de l'id privé
5. la fonction afficher pour les deux classes
6. Créer Les setters pour les trois livres à l'étagère.
7. Créer un programme de test.
*/
#include <iostream>
#include <string>
using namespace std;
class Etagere;
// 1. Créer une classe Livre avec les attributs suivant: Auteur, titre, id
class Livre {
private:
	string auteur;
	string titre;
	int id;
	// 4. Créer les setters public pour auteur et titre, ainsi que le setter de l'id privé
	void setId(int id) {
		this->id = 1000 + id;
	}
public:
	// 3. Créer les constructeurs par défaut et d'initialisation pour les deux classes.
	Livre() {
		id = -1;
		auteur = "";
		titre = "";
	}
	// 3. Créer les constructeurs par défaut et d'initialisation pour les deux classes.
	Livre(string auteur,string titre) {
		id = -1;
		this->auteur = auteur;
		this->titre = titre;
	}
	// 4. Créer les setters public pour auteur et titre, ainsi que le setter de l'id privé
	void setAuteur(string auteur) {
		this->auteur = auteur;
	}
	// 4. Créer les setters public pour auteur et titre, ainsi que le setter de l'id privé
	void setTitre(string titre) {
		this->titre = titre;
	}
	// 5. la fonction afficher pour les deux classes
	void afficher() {
		if (this->id>0) {
			cout <<endl<< "ID: " << this->id<<' '<<endl;
		}
		cout<<"Titre: " << this->titre<<endl;
		cout <<"Auteur: " << this->auteur<<endl;
	}
	friend class Etagere;
};
// 2. Créer une classe Etagère avec les attributs suivants: livre1, livre2, livre3, count qui calcule le nombre des livres dans la bibliothèque, il va nous aider à affecter des ids uniques pour chaque livre.
class Etagere {
private:
	Livre livre1;
	Livre livre2;
	Livre livre3;
	static int count;
public:
	// 3. Créer les constructeurs par défaut et d'initialisation pour les deux classes.
	Etagere() {}
	// 3. Créer les constructeurs par défaut et d'initialisation pour les deux classes.
	Etagere(Livre &l1, Livre &l2, Livre &l3) {
		l1.setId(++count);
		livre1 = l1;
		l2.setId(++count);
		livre2 = l2;
		l3.setId(++count);
		livre3 = l3;
	}
	// 5. la fonction afficher pour les deux classes
	void afficher_etagere() {
		if (livre1.id > 0)
			livre1.afficher();
		if (livre2.id > 0)
			livre2.afficher();
		if (livre3.id > 0)
			livre3.afficher();

		cout << endl << "Il y a " << count << " livres" << endl;
	}
	// 6. Créer Les setters pour les trois livres à l'étagère.
	void setLivre1(Livre &l) {
		l.setId(++count);
		this->livre1 = l;
	}
	void setLivre2(Livre &l) {
		l.setId(++count);
		this->livre2 = l;
	}
	void setLivre3(Livre &l) {
		l.setId(++count);
		this->livre3 = l;
	}
};

int Etagere::count = 0;


int main() {
	// 7. Créer un programme de test.
	Livre l1("UnAuteur", "Untitre"), l2, l3;
	Etagere e(l1, l2, l3);
	e.afficher_etagere();

	Etagere e2;
	Livre l4("Auteur2", "Titre 2");
	e2.setLivre3(l4);
	e2.afficher_etagere();
}
