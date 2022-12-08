#include <iostream>
#include <string>
using namespace std;
class Etagere;
class Livre {
private:
	string auteur;
	string titre;
	int id;
	void setId(int id) {
		this->id = 1000 + id;
	}
public:
	Livre() {
		id = -1;
		auteur = "";
		titre = "";
	}
	Livre(string auteur,string titre) {
		id = -1;
		this->auteur = auteur;
		this->titre = titre;
	}
	void setAuteur(string auteur) {
		this->auteur = auteur;
	}
	void setTitre(string titre) {
		this->titre = titre;
	}
	void afficher() {
		if (this->id>0) {
			cout <<endl<< "ID: " << this->id<<' '<<endl;
		}
		cout<<"Titre: " << this->titre<<endl;
		cout <<"Auteur: " << this->auteur<<endl;
	}
	friend class Etagere;
};

class Etagere {
private:
	Livre livre1, livre2, livre3;
	static int count;
public:
	Etagere() {}
	Etagere(Livre l1, Livre l2, Livre l3) {
		l1.setId(++count);
		livre1 = l1;
		l2.setId(++count);
		livre2 = l2;
		l3.setId(++count);
		livre3 = l3;
	}
	void setLivre1(Livre l) {
		l.setId(++count);
		this->livre1 = l;
	}
	void setLivre2(Livre l) {
		l.setId(++count);
		this->livre2 = l;
	}
	void setLivre3(Livre l) {
		l.setId(++count);
		this->livre3 = l;
	}
	void afficher_etagere() {
		if (livre1.id > 0)
			livre1.afficher();
		if (livre2.id > 0)
			livre2.afficher();
		if (livre3.id > 0)
			livre3.afficher();

		cout << endl << "Il y a " << count << " livres" << endl;
	}
};

int Etagere::count = 0;


int main() {
	Livre l1("UnAuteur", "Untitre"), l2, l3;
	Etagere e(l1, l2, l3);
	e.afficher_etagere();

	Etagere e2;
	Livre l4("Auteur2", "Titre 2");
	e2.setLivre3(l4);
	e2.afficher_etagere();
}