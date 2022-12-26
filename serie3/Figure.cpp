#include <iostream>
using namespace std;

class Figure {
protected:
	double x;
	double y;
	double z;
public:
	Figure(double x=0, double y=0, double z=0) :x(x), y(y), z(z){}
	virtual string description() {
		return "Figure";
	}
	virtual void affiche() {
		cout << x << " " << y << " " << z<<" ";
	}
};
class Triangle : public Figure {
private:
	double base, cote1, cote2, hauteur;
public:
	Triangle(double x, double y, double z, double b, double c1, 
		double c2, double h): Figure(x, y, z), base(b), cote1(c1), cote2(c2), 
	hauteur(h){}
	string description() {
		return "Triangle";
	}
	void affiche() {
		Figure::affiche();
		cout << base << " " << hauteur << " ";
	}
};
class Carre : public Figure {
private:
	double largeur;
public:
	Carre(double x, double y, double z, double l) 
		: Figure(x, y, z), largeur(l) {}
	string description() {
		return "Carre";
	}
	void affiche() {
		Figure::affiche();
		cout << largeur << " ";
	}
};
void afficherInfos(Figure& f) {
	cout << "Je suis un(e) " << f.description()<<endl;
	cout << "Mes attributs sont : ";
	f.affiche();
	cout << endl;
}

int main() {
	Triangle t(0, 0, 0, 5, 0, 0, 8);
	afficherInfos(t);
	Carre c(0, 0, 0, 4);
	afficherInfos(c);
	return 0;
}
